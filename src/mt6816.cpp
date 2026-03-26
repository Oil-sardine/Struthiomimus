#include "Arduino.h"

#include "MT6816.h"

#define MT6816_READ_REG_03                  0x8300
#define MT6816_READ_REG_04                  0x8400

#define MT6816_NO_MAGNET_WARNING_BIT        0x0002

MT6816::MT6816(SPISettings settings, int nCS) : settings(settings), nCS(nCS) {
};

MT6816::MT6816(int nCS) : nCS(nCS) {
    settings = MT6816SPISettings;
};

MT6816::~MT6816() {
};

void MT6816::init(SPIClass* _spi) {
    spi = _spi;
    if (nCS >= 0) {
        pinMode(nCS, OUTPUT);
        digitalWrite(nCS, HIGH);
        spi->begin();
    }
};