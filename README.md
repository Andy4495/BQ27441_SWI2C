BQ27441_SWI2C Library
====================

This library interfaces with the Texas Instruments BQ27441 Battery [Fuel Gauge][1] using software (bit-bang) I2C. This allows the device to be connected to any two available I/O pins instead of the hardware-specific I2C peripheral pins on your microcontroller.

SparkFun has a [library][4] available when using hardware I2C.

This library depends on a specific [SWI2C library][5].

Usage
-----

_Be sure to review the example sketch included with the library._

First, **include** the library header file:

    #include <SWI2C.h>
    #include <BQ27441_SWI2C.h>

Note that `<SWI2C.h>` is required, since this library depends on the [SWI2C][5] library.

Next, **instantiate** a BQ27441_SWI2C object.

`sda_pin` is the pin number for the SDA signal, `scl_pin` is the pin number for the SCL signal.

    BQ27441_SWI2C myBQ27441(uint8_t sda_pin, uint8_t scl_pin);

The library assumes an I2C device address of 0x55. If for some reason you need to use a different device address, then a third parameter can be used in the constructor:

    BQ27441_SWI2C myBQ27441(uint8_t sda_pin, uint8_t scl_pin, uint8_t device_address);


#### Library Methods ####

The library includes specific methods to read the various device values. 

Standard Commands (see [Technical Reference][3] Chapter 4.2 - 4.19):

    uint16_t getTemperature();                  // Result in 0.1 Kelvins
    uint16_t getTemperatureC();                 // Result in 0.1 Celsius
    uint16_t getTemperatureF();                 // Result in 0.1 Fahrenheit
    uint16_t getVoltage();
    uint16_t getFlags();
    uint16_t getNominalAvailableCapacity();
    uint16_t getFullAvailableCapacity();
    uint16_t getRemainingCapacity();
    uint16_t getFullChargeCapacity();
    int16_t  getAverageCurrent();
    int16_t  getStandbyCurrent();
    int16_t  getMaxLoadCurrent();
    int16_t  getAveragePower();
    uint16_t getStateOfCharge();
    uint16_t getInternalTemperature();            // Result in 0.1 Kelvins
    int16_t  getInternalTemperatureC();           // Result in 0.1 Celsius
    int16_t  getInternalTemperatureF();           // Result in 0.1 Fahrenheit
    uint16_t getStateOfHealth();
    uint16_t getRemainingCapacityUnfiltered();
    uint16_t getRemainingCapacityFiltered();
    uint16_t getFullChargeCapacityUnfiltered();
    uint16_t getFullChargeCapacityFiltered();
    uint16_t getStateOfChargeUnfiltered();

Extended Data Commands (see [Technical Reference][3] Chapter 5.1 - 5.2):

    uint16_t getOpConfig();
    uint16_t getDesignCapacity();

Control Subcommands (see [Technical Reference][3] Chapter 4.1.1 - 4.1.6):

    uint16_t getControlStatus();
    uint16_t getDeviceType();
    uint16_t getFWVersion();
    uint16_t getDMCode();
    uint16_t getPrevMacwrite();
    uint16_t getChemID();


Since this library was designed as a simple interface to use software I2C to access battery status (e.g. voltage, current, temperature), other commands which configure or control the BQ27441 are left unimplemented.


References
---------------------

+ Texas Instruments [BQ27441 product page][1].
+ BQ27441 [Datasheet][2].
+ BQ27441 [User's Guide][6].
+ BQ27441 [Technical Reference][3].
+ [SparkFun BQ27441 library][4] implemented with hardware I2C.
+ [SWI2C library][5].

[1]:http://www.ti.com/product/bq27441-g1
[2]:http://www.ti.com/lit/gpn/bq27441-g1
[3]:http://www.ti.com/lit/pdf/sluuac9
[4]:https://github.com/sparkfun/SparkFun_BQ27441_Arduino_Library
[5]:https://gitlab.com/Andy4495/SWI2C
[6]:http://www.ti.com/lit/pdf/sluuap4
