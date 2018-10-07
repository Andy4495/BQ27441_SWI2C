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

// Device definitions
#define BQ27441_I2C_ADDRESS 0x55 // Default I2C address of the BQ27441-G1A
#define BQ27441_DEVICE_ID	0x0421 // Default device ID
#define BQ27441_COMMAND_CONTROL			    0x00 // Control()
#define BQ27441_COMMAND_TEMP			      0x02 // Temperature()
#define BQ27441_COMMAND_VOLTAGE			    0x04 // Voltage()
#define BQ27441_COMMAND_FLAGS			      0x06 // Flags()
#define BQ27441_COMMAND_NOM_CAPACITY	  0x08 // NominalAvailableCapacity()
#define BQ27441_COMMAND_AVAIL_CAPACITY	0x0A // FullAvailableCapacity()
#define BQ27441_COMMAND_REM_CAPACITY	  0x0C // RemainingCapacity()
#define BQ27441_COMMAND_FULL_CAPACITY	  0x0E // FullChargeCapacity()
#define BQ27441_COMMAND_AVG_CURRENT		  0x10 // AverageCurrent()
#define BQ27441_COMMAND_STDBY_CURRENT	  0x12 // StandbyCurrent()
#define BQ27441_COMMAND_MAX_CURRENT		  0x14 // MaxLoadCurrent()
#define BQ27441_COMMAND_AVG_POWER		    0x18 // AveragePower()
#define BQ27441_COMMAND_SOC				      0x1C // StateOfCharge()
#define BQ27441_COMMAND_INT_TEMP		    0x1E // InternalTemperature()
#define BQ27441_COMMAND_SOH             0x20 // StateOfHealth()
#define BQ27441_COMMAND_REM_CAP_UNFL	  0x28 // RemainingCapacityUnfiltered()
#define BQ27441_COMMAND_REM_CAP_FIL		  0x2A // RemainingCapacityFiltered()
#define BQ27441_COMMAND_FULL_CAP_UNFL	  0x2C // FullChargeCapacityUnfiltered()
#define BQ27441_COMMAND_FULL_CAP_FIL	  0x2E // FullChargeCapacityFiltered()
#define BQ27441_COMMAND_SOC_UNFL		    0x30 // StateOfChargeUnfiltered()
#define BQ27441_CONTROL_DEVICE_TYPE     0x01

class BQ27441_SWI2C {
public:
  BQ27441_SWI2C(uint8_t sda_pin, uint8_t scl_pin, uint8_t deviceID);
  ~BQ27441_SWI2C();
  void begin();
  uint16_t readRegister(uint8_t regAddress);
  uint16_t readDeviceID();
private:
  SWI2C* myDevice;
};

#endif
