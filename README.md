# BQ27441_SWI2C Library

[![Arduino Compile Sketches](https://github.com/Andy4495/BQ27441_SWI2C/actions/workflows/arduino-compile-sketches.yml/badge.svg)](https://github.com/Andy4495/BQ27441_SWI2C/actions/workflows/arduino-compile-sketches.yml)
[![Check Markdown Links](https://github.com/Andy4495/BQ27441_SWI2C/actions/workflows/check-links.yml/badge.svg)](https://github.com/Andy4495/BQ27441_SWI2C/actions/workflows/check-links.yml)

This library interfaces with the Texas Instruments BQ27441 Battery [Fuel Gauge][1] using software (bit-bang) I2C. This allows the device to be connected to any two available I/O pins instead of the hardware-specific I2C peripheral pins on your microcontroller.

SparkFun has a [library][4] available when using hardware I2C.

This library depends on a specific [SWI2C library][5].

## Usage

_Be sure to review the example sketch included with the library._

1. Install the [SWI2C][5] library in addition to this library.

2. **Include** the library header file:

    ```cpp
    #include <BQ27441_SWI2C.h>
    ```

    Note that this library depends on the [SWI2C][5] library.

3. **Instantiate** a BQ27441_SWI2C object.

    `sda_pin` is the pin number for the SDA signal, `scl_pin` is the pin number for the SCL signal.

    ```cpp
    BQ27441_SWI2C myBQ27441(uint8_t sda_pin, uint8_t scl_pin);  // Default I2C address 0x55
    ```

    The library assumes an I2C device address of 0x55. If for some reason you need to use a different device address, then a third parameter can be used in the constructor:

    ```cpp
    BQ27441_SWI2C myBQ27441(uint8_t sda_pin, uint8_t scl_pin, uint8_t device_address);
    ```

4. Access the various device registers using the library methods listed below.

### Library Methods

The library includes specific methods to read the various device values.

Standard Commands (see [Technical Reference][3] Chapter 4.2 - 4.19):

```cpp
uint16_t getTemperature();                  // Result in 0.1 Kelvins
uint16_t getTemperatureC();                 // Result in 0.1 Celsius
int16_t  getTemperatureF();                 // Result in 0.1 Fahrenheit
int16_t  getVoltage();
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
```

Extended Data Commands (see [Technical Reference][3] Chapter 5.1 - 5.2):

```cpp
uint16_t getOpConfig();
uint16_t getDesignCapacity();
```

Control Subcommands (see [Technical Reference][3] Chapter 4.1.1 - 4.1.6):

```cpp
uint16_t getControlStatus();
uint16_t getDeviceType();
uint16_t getFWVersion();
uint16_t getDMCode();
uint16_t getPrevMacwrite();
uint16_t getChemID();
```

Since this library was designed as a simple interface to use software I2C to access battery status (e.g. voltage, current, temperature), other commands which configure or control the BQ27441 are left unimplemented.

The library also provides access to the underlying `SWI2C` oject and its [public methods][5]. This can be useful for debugging and other specialized situations:

```cpp
SWI2C*   getSWI2CObject();
```

## References

+ Texas Instruments [BQ27441 product page][1].
+ BQ27441 [Datasheet][2].
+ BQ27441 [User's Guide][6].
+ BQ27441 [Technical Reference][3].
+ [SparkFun BQ27441 library][4] implemented with hardware I2C.
+ [SWI2C library][5].

## License

The software and other files in this repository are released under what is commonly called the [MIT License][100]. See the file [`LICENSE`][101] in this repository.

[1]:http://www.ti.com/product/bq27441-g1
[2]:http://www.ti.com/lit/gpn/bq27441-g1
[3]:http://www.ti.com/lit/pdf/sluuac9
[4]:https://github.com/sparkfun/SparkFun_BQ27441_Arduino_Library
[5]:https://github.com/Andy4495/SWI2C
[6]:http://www.ti.com/lit/pdf/sluuap4
[100]: https://choosealicense.com/licenses/mit/
[101]: ./LICENSE
[//]: # ([200]: https://github.com/Andy4495/BQ27441_SWI2C)
