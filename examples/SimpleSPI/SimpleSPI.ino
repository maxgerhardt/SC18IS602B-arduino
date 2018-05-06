#include "Arduino.h"
#include "SC18IS602B.h"

SC18IS602B spiBridge;

uint8_t spi_transf(uint8_t b) {
	Serial.println("SPI WRITE: " + String(b, HEX));
	uint8_t ret = spiBridge.spiTransfer(0, b);
	Serial.println("SPI READ: " + String(ret, HEX));
	return ret;
}

void setup() {
	Serial.begin(115200);

	//Startup I2C interface on D1 (SDA) and D2 (SCL)
	//for the ESP8266
#ifdef ARDUINO_ARCH_ESP8266
	spiBridge.begin(D1, D2);
#else
	spiBridge.begin();
#endif

	spiBridge.configureSPI(true, SC18IS601B_SPIMODE_0, SC18IS601B_SPICLK_1843_kHz);

	//Send some test data.
	uint8_t spiRead = spi_transf(0x05);

	const int slaveNum = 0;
	const uint8_t spiData[] = { 0xab, 0xcd, 0xde };
	uint8_t spiReadBuf[sizeof(spiData)];

	bool ok = spiBridge.spiTransfer(slaveNum, spiData, sizeof(spiData), spiReadBuf);

	if(ok) {
		for(size_t i = 0; i < sizeof(spiData); i++) {
			Serial.println("SPI readBuf[" + String(i) + "] = 0x" + String(spiReadBuf[i], HEX));
		}
	} else {
		Serial.println("SPI transfer failed");
	}
}

void loop() {
}
