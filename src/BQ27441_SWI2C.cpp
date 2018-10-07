/* -----------------------------------------------------------------
   BQ27441_SWI2C Library
   https://gitlab.com/Andy4495/BQ27441_SWI2C

   This library requires that the following library also be installed:
   https://gitlab.com/Andy4495/SWI2C


   10/06/2018 - A.T. - Original

*/

#include "BQ27441_SWI2C.h"
BQ27441_SWI2C::BQ27441_SWI2C(uint8_t sda_pin, uint8_t scl_pin) {
  myDevice = new SWI2C(sda_pin, scl_pin, BQ27441_I2C_ADDRESS);
  myDevice->begin();
}

BQ27441_SWI2C::~BQ27441_SWI2C() {
  delete myDevice;
}

void BQ27441_SWI2C::begin(){
  // Empty function defined for compatibility
}

uint16_t BQ27441_SWI2C::readRegister(uint8_t regAddress){
  uint16_t result;

  myDevice->read2bFromRegister(regAddress, &result);
  return result;
}

uint16_t BQ27441_SWI2C::getControlWord(uint8_t subCommand) {
  uint16_t result;

  myDevice->startBit();
  myDevice->writeAddress(0);
  myDevice->checkAckBit();
  myDevice->writeRegister(BQ27441_COMMAND_CONTROL);   // Control command
  myDevice->checkAckBit();
  myDevice->writeByte(subCommand);   // Device type LSB
  myDevice->checkAckBit();
  myDevice->writeByte(0);                             // Device type MSB
  myDevice->checkAckBit();
  myDevice->stopBit();
  myDevice->read2bFromRegister(BQ27441_COMMAND_CONTROL, &result);

  return result;
}
