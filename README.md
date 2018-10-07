BQ27441_SWI2C Library
====================

This library allows use of the Texas Instruments BQ27441 Battery [Fuel Gauge][1] using software I2C. This allows the device to be connected to any two available I/O pins instead of the hardware-specific I2C peripheral pins on your microcontroller.

SparkFun has a [library][4] available when using hardware I2C.

This library depends on a specific [SWI2C library][5].

Usage
-----

_Be sure to review the example sketch included with the library._

First, **include** the library header file:

    #include <SWI2C.h>
    #include <BQ27441_SWI2C.h>

Note that `<SWI2C.h>` is required, since this library depends on the SWI2C library.

Next, **instantiate** a BQ27441_SWI2C object.

`sda_pin` is the pin number for the SDA signal, `scl_pin` is the pin number for the SCL signal.

    BQ27441_SWI2C myBQ27441(uint8_t sda_pin, uint8_t scl_pin);


#### Library Methods ####

To read a status value, use `readRegister`. This method can be used for the various "Standard Commands" listed in the [Technical Reference][3] (with the exception of the "Control" command). Note that some of these commands actually return a signed value, so you may need to caste the return value as signed.

    uint16_t myBQ27441.readRegister(uint8_t register);

To read the Device ID, use the following:

    uint16_t myBQ27441.readDeviceID();

Since this library was designed as a simple interface to use software I2C to access battery voltage, power draw, and temperature, other control commands are left unimplemented.

Be sure to consult the [Technical Reference][3] to understand the units of the various values returned by the Standard Commands.


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
