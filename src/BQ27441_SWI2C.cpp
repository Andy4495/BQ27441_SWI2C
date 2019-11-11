/* -----------------------------------------------------------------
   BQ27441_SWI2C Library
   https://github.com/Andy4495/BQ27441_SWI2C

   This library requires that the following library also be installed:
   https://github.com/Andy4495/SWI2C


   10/06/2018 - A.T. - Original
   10/17/2018 - A.T. - Use the new SWI2C library method "write2write2bToRegister()"
                     - Implement specific methods for each command opcode

*/

#include "BQ27441_SWI2C.h"
BQ27441_SWI2C::BQ27441_SWI2C(uint8_t sda_pin, uint8_t scl_pin, uint8_t addr) {
  // addr is optional, and defaults to BQ27441_I2C_ADDRESS
  myDevice = new SWI2C(sda_pin, scl_pin, addr);
  myDevice->begin();
}

BQ27441_SWI2C::~BQ27441_SWI2C() {
  delete myDevice;
}

void BQ27441_SWI2C::begin(){
  // Empty method defined for compatibility
}

// Standard Commands
uint16_t BQ27441_SWI2C::getTemperature() {  // Result in 0.1 Kelvins
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_TEMP, &result);
  return result;
}

int16_t BQ27441_SWI2C::getTemperatureC() {  // Result in 0.1 Celcius
  int16_t result;
  uint16_t raw;

  myDevice->read2bFromRegister(BQ27441_COMMAND_TEMP, &raw);
  // Convert to 0.1 Celsius using integer math
  result = (int16_t) raw - 2731;
  return result;
}

int16_t BQ27441_SWI2C::getTemperatureF() {  // Result in 0.1 Fahrenheit
  int16_t result;
  uint16_t raw;

  myDevice->read2bFromRegister(BQ27441_COMMAND_TEMP, &raw);
  // Convert to 0.1 Fahrenheit using integer math
  result = ((((int16_t)raw - 2731) * 9) / 5) + 320;
  return result;
}

uint16_t BQ27441_SWI2C::getVoltage() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_VOLTAGE, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getFlags() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_FLAGS, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getNominalAvailableCapacity() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_NOM_CAPACITY, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getFullAvailableCapacity() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_AVAIL_CAPACITY, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getRemainingCapacity() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_REM_CAPACITY, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getFullChargeCapacity() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_FULL_CAPACITY, &result);
  return result;
}

int16_t  BQ27441_SWI2C::getAverageCurrent() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_AVG_CURRENT, &result);
  return (int16_t) result;
}

int16_t  BQ27441_SWI2C::getStandbyCurrent() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_STDBY_CURRENT, &result);
  return (int16_t) result;
}

int16_t  BQ27441_SWI2C::getMaxLoadCurrent() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_MAX_CURRENT, &result);
  return (int16_t) result;
}

int16_t  BQ27441_SWI2C::getAveragePower() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_AVG_POWER, &result);
  return (int16_t) result;
}

uint16_t BQ27441_SWI2C::getStateOfCharge() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_SOC, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getInternalTemperature() {   // Result in 0.1 Kelvins
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_INT_TEMP, &result);
  return result;
}

int16_t  BQ27441_SWI2C::getInternalTemperatureC() {  // Result in 0.1 Celsius
  int16_t result;
  uint16_t raw;

  myDevice->read2bFromRegister(BQ27441_COMMAND_INT_TEMP, &raw);
  // Convert to 0.1 Celsius using integer math
  result = (int16_t) raw - 2731;
  return result;
}

int16_t  BQ27441_SWI2C::getInternalTemperatureF() {  // Result in 0.1 Fahrenheit
  int16_t result;
  uint16_t raw;

  myDevice->read2bFromRegister(BQ27441_COMMAND_INT_TEMP, &raw);
  // Convert to 0.1 Fahrenheit using integer math
  result = ((((int16_t)raw - 2731) * 9) / 5) + 320;
  return result;
}

uint16_t BQ27441_SWI2C::getStateOfHealth() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_SOH, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getRemainingCapacityUnfiltered() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_REM_CAP_UNFL, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getRemainingCapacityFiltered() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_REM_CAP_FIL, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getFullChargeCapacityUnfiltered() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_FULL_CAP_UNFL, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getFullChargeCapacityFiltered() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_FULL_CAP_FIL, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getStateOfChargeUnfiltered() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_COMMAND_SOC_UNFL, &result);
  return result;
}

// Extended Data Commands
uint16_t BQ27441_SWI2C::getOpConfig() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_EXTENDED_OPCONFIG, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getDesignCapacity() {
  uint16_t result;

  myDevice->read2bFromRegister(BQ27441_EXTENDED_CAPACITY, &result);
  return result;
}

// Control Subcommands
uint16_t BQ27441_SWI2C::getControlStatus() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_STATUS);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

uint16_t BQ27441_SWI2C::getDeviceType() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_DEVICE_TYPE);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

uint16_t BQ27441_SWI2C::getFWVersion() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_FW_VERSION);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

uint16_t BQ27441_SWI2C::getDMCode() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_DM_CODE);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

uint16_t BQ27441_SWI2C::getPrevMacwrite() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_PREV_MACWRITE);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

uint16_t BQ27441_SWI2C::getChemID() {
  uint16_t result;

  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) BQ27441_CONTROL_CHEM_ID);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}

// The following two methods are generic versions of the above command
// and probably wouldn't be used in most sketches

uint16_t BQ27441_SWI2C::readRegister(uint8_t regAddress){
  uint16_t result;

  myDevice->read2bFromRegister(regAddress, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getControlWord(uint8_t subCommand) {
  uint16_t result;

  // Since the MSB of all the CONTROL subcommands is zero, an unsigned 8-bit
  // value is unchanged when casting to a 16-bit value.
  myDevice->write2bToRegister(BQ27441_COMMAND_CONTROL, (uint16_t) subCommand);
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}
