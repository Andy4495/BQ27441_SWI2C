/******************************************************************************
  BQ27441_SWI2C Library Example

  https://gitlab.com/Andy4495/BQ27441_SWI2C

  Reads various battery stats every 10 seconds and prints to Serial.

******************************************************************************/

#include <SWI2C.h>            // Need this since BQ27441_SWI2C uses it
#include <BQ27441_SWI2C.h>

// Change the following depending on your board type. 
#define BOARD_LED RED_LED


// Change the following 2 defines to the pins you using to access BQ27441
#define SW_SCL  9
#define SW_SDA 10


BQ27441_SWI2C myBQ27441(SW_SDA, SW_SCL, BQ27441_I2C_ADDRESS);

int led_status = 0;

void setupBQ27441(void)
{
  uint16_t bq27441_device_id;

  // Get device type and set lipo_status
  /// To be implemented later
  bq27441_device_id = myBQ27441.readDeviceID();
  Serial.print("Device ID: 0x");
  Serial.println(bq27441_device_id, HEX);
  Serial.println("");

  if (bq27441_device_id != BQ27441_DEVICE_ID)
  {
    // If communication fails, print an error message and loop forever.
    Serial.println("Error: Unable to communicate with BQ27441.");
    Serial.println("  Check wiring and try again.");
    Serial.println("  Battery monitoring uses I2C module(1) at pins 9/10. ");
    while (1) ;
  }
  Serial.println("Connected to BQ27441!");
  Serial.println("");

}

void printBatteryStats()
{
  uint16_t data;

  // Read battery stats from the BQ27441-G1A
  unsigned int soc =          myBQ27441.readRegister(BQ27441_COMMAND_SOC);
  unsigned int volts =        myBQ27441.readRegister(BQ27441_COMMAND_VOLTAGE);
  int          current =      (int) myBQ27441.readRegister(BQ27441_COMMAND_AVG_CURRENT);
  unsigned int fullCapacity = myBQ27441.readRegister(BQ27441_COMMAND_FULL_CAPACITY);
  unsigned int capacity =     myBQ27441.readRegister(BQ27441_COMMAND_REM_CAPACITY);
  int          power =        (int) myBQ27441.readRegister(BQ27441_COMMAND_AVG_POWER);
  int          health =       (int) myBQ27441.readRegister(BQ27441_COMMAND_SOH);
  int          intTemp =      (int) myBQ27441.readRegister(BQ27441_COMMAND_INT_TEMP);  // Units of 0.1 Kelvins
  intTemp =    (((intTemp - 2730) * 9) / 5) + 320;                                     // Convert to 0.1 Fahrenheit
  int          battTemp =     (int) myBQ27441.readRegister(BQ27441_COMMAND_TEMP);      // Units of 0.1 Kelvins
  battTemp =   (((battTemp - 2730) * 9) / 5) + 320;                                    // Convert to 0.1 Fahrenheit

  Serial.print("State of charge (%):             ");
  Serial.println(soc);
  Serial.print("Battery voltage (mV):            ");
  Serial.println(volts);
  Serial.print("Average current (mA):            ");
  Serial.println(current);
  Serial.print("Full capacity (mAh):             ");
  Serial.println(fullCapacity);
  Serial.print("Remaining capacity (mAH):        ");
  Serial.println(capacity);
  Serial.print("Average power draw (mW):         ");
  Serial.println(power);
  Serial.print("State of health (%):             ");
  Serial.println(health);
  Serial.print("Internal temperature (F):        ");
  Serial.print(intTemp/10);
  Serial.print(".");
  Serial.println(intTemp%10);
  Serial.print("Battery temperature  (F):        ");
  Serial.print(battTemp/10);
  Serial.print(".");
  Serial.println(battTemp%10);
  Serial.println("----");
}

void setup()
{
  Serial.begin(9600);

  Serial.println("");
  Serial.println("BQ27441 over Software I2C");
  setupBQ27441();

  pinMode(BOARD_LED, OUTPUT);
}

void loop()
{
  led_status = ~led_status;
  digitalWrite(BOARD_LED, led_status);
  printBatteryStats();
  delay(10000);
}
