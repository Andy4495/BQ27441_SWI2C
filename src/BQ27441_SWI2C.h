/* -----------------------------------------------------------------
   BQ27441_SWI2C Library
   https://gitlab.com/Andy4495/BQ27441_SWI2C

   This library requires that the following library also be installed:
   https://gitlab.com/Andy4495/SWI2C


   10/06/2018 - A.T. - Original

*/

#ifndef BQ27441_SWI2C_H
#define BQ27441_SWI2C_H

#include "Arduino.h"
#include <SWI2C.h>

/*****************************************************************************/
// BQ27441 Device definitions
//
// Default I2C Address
#define BQ27441_I2C_ADDRESS 0x55
// Default Device ID -- expect this value to be returned from readDeviceID()
#define BQ27441_DEVICE_ID	0x0421
// Registers (aka commands) that can be used with readRegister()
// See sections 4.2 - 4.20 and 5.1 - 5.2 in Technical Reference (SLUUAC9A)
#define BQ27441_COMMAND_TEMP			      0x02 // 0.1 Kelvins
#define BQ27441_COMMAND_VOLTAGE			    0x04 // mV
#define BQ27441_COMMAND_FLAGS			      0x06 // See section
#define BQ27441_COMMAND_NOM_CAPACITY	  0x08 // mAh
#define BQ27441_COMMAND_AVAIL_CAPACITY	0x0A // mAh
#define BQ27441_COMMAND_REM_CAPACITY	  0x0C // mAh
#define BQ27441_COMMAND_FULL_CAPACITY	  0x0E // mAh
#define BQ27441_COMMAND_AVG_CURRENT		  0x10 // mA
#define BQ27441_COMMAND_STDBY_CURRENT	  0x12 // mA
#define BQ27441_COMMAND_MAX_CURRENT		  0x14 // mA
#define BQ27441_COMMAND_AVG_POWER		    0x18 // mW
#define BQ27441_COMMAND_SOC				      0x1C // %
#define BQ27441_COMMAND_INT_TEMP		    0x1E // 0.1 Kelvins
#define BQ27441_COMMAND_SOH             0x20 // %
#define BQ27441_COMMAND_REM_CAP_UNFL	  0x28 // mAh
#define BQ27441_COMMAND_REM_CAP_FIL		  0x2A // mAh
#define BQ27441_COMMAND_FULL_CAP_UNFL	  0x2C // mAh
#define BQ27441_COMMAND_FULL_CAP_FIL	  0x2E // mAh
#define BQ27441_COMMAND_SOC_UNFL		    0x30 // %
#define BQ27441_EXTENDED_OPCONFIG	      0x3A // See section 5.1
#define BQ27441_EXTENDED_CAPACITY	      0x3C // See section 5.2
// Command opcode. Used internally by  getControlWord()
// See section 4.1 in Technical Reference (SLUUAC9A)
#define BQ27441_COMMAND_CONTROL			    0x00 //
// Subcommands used with getControlWord
// See sections 4.1.1 - 4.1.6 in Technical Reference (SLUUAC9A)
#define BQ27441_CONTROL_STATUS          0x00 // See section 4.1.1
#define BQ27441_CONTROL_DEVICE_TYPE     0x01 // Shouild always return 0x0421
#define BQ27441_CONTROL_FW_VERSION      0x02 // See section 4.1.3
#define BQ27441_CONTROL_DM_CODE         0x04 // See section 4.1.4
#define BQ27441_CONTROL_PREV_MACWRITE   0x07 // See section 4.1.5
#define BQ27441_CONTROL_CHEM_ID         0x08 // bq27441-G1A should return 0x0128 and bq27441-G1B should return 0x0312.
/*****************************************************************************/

class BQ27441_SWI2C {
public:
  BQ27441_SWI2C(uint8_t sda_pin, uint8_t scl_pin);
  ~BQ27441_SWI2C();
  void begin();
  uint16_t readRegister(uint8_t regAddress);
  uint16_t getControlWord(uint8_t subCommand);
private:
  SWI2C* myDevice;
};

#endif
