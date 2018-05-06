#include "Arduino.h"
#include "SC18IS602B.h"

SC18IS602B spiBridge;

/* connect MISO and MOSI together with a wire.
 * This tests whether the sent out data equals the read-in data.
 * */

uint8_t spi_transf(uint8_t b) {
	Serial.println("SPI WRITE: " + String(b, HEX));
	uint8_t ret = spiBridge.spiTransfer(0, b);
	Serial.println("SPI READ: " + String(ret, HEX));
	return ret;
}

void selftest() {
	for(int i=0; i <= 0xff; i++) {
		if(spi_transf((uint8_t)i) != (uint8_t)i ) {
			Serial.println("FAIL, VALUES DON'T MATCH");
			while(1) delay(1000);
		} else {
			Serial.println("SPI TEST GOOD");
		}
	}
	Serial.println("SPI TEST PASSED!!");
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
	selftest();
}

void loop() { }
