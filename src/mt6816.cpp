/*
This program based by https://github.com/eborghi10/AS5048A.git
*/

#include "Arduino.h"

#include <MT6816.h>

static const uint16_t MT6816_CLEAR_ERROR_FLAG = 0x0001;
static const uint16_t MT6816_PROGRAMMING_CONTROL = 0x0003;
static const uint16_t MT6816_OTP_REGISTER_ZERO_POS_HIGH = 0x0016;
static const uint16_t MT6816_OTP_REGISTER_ZERO_POS_LOW = 0x0017;
static const uint16_t MT6816_DIAG_AGC = 0x3FFD;
static const uint16_t MT6816_MAGNITUDE = 0x3FFE;
static const uint16_t MT6816_ANGLE = 0x3FFF;

static const uint8_t MT6816_AGC_FLAG = 0xFF;
static const uint8_t MT6816_ERROR_PARITY_FLAG = 0x04;
static const uint8_t MT6816_ERROR_COMMAND_INVALID_FLAG = 0x02;
static const uint8_t MT6816_ERROR_FRAMING_FLAG = 0x01;

static const uint16_t MT6816_DIAG_COMP_HIGH = 0x2000;
static const uint16_t MT6816_DIAG_COMP_LOW = 0x1000;
static const uint16_t MT6816_DIAG_COF = 0x0800;
static const uint16_t MT6816_DIAG_OCF = 0x0400;

static const double MT6816_MAX_VALUE = 8191.0;