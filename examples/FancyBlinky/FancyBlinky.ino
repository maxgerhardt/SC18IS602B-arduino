#include "Arduino.h"
#include "SC18IS602B.h"

SC18IS602B spiBridge;

/* Connect all SS/GPIO pins to LEDs and current limiting resistors.
 * Blinks each LED once, then does a binary counter.
 * */

void setup() {
	Serial.begin(115200);

	//Startup I2C interface on D1 (SDA) and D2 (SCL)
	//for the ESP8266
#ifdef ARDUINO_ARCH_ESP8266
	spiBridge.begin(D1, D2);
#else
	spiBridge.begin();
#endif

	spiBridge.enableGPIO(0, true);
	spiBridge.enableGPIO(1, true);
	spiBridge.enableGPIO(2, true);
	spiBridge.enableGPIO(3, true);

	spiBridge.setupGPIO(0, SC18IS601B_GPIO_MODE_PUSH_PULL);
	spiBridge.setupGPIO(1, SC18IS601B_GPIO_MODE_PUSH_PULL);
	spiBridge.setupGPIO(2, SC18IS601B_GPIO_MODE_PUSH_PULL);
	spiBridge.setupGPIO(3, SC18IS601B_GPIO_MODE_PUSH_PULL);
}

void loop() {
	spiBridge.writeGPIO(0, HIGH);
	delay(500);
	spiBridge.writeGPIO(0, LOW);
	delay(500);

	spiBridge.writeGPIO(1, HIGH);
	delay(500);
	spiBridge.writeGPIO(1, LOW);
	delay(500);

	spiBridge.writeGPIO(2, HIGH);
	delay(500);
	spiBridge.writeGPIO(2, LOW);
	delay(500);

	spiBridge.writeGPIO(3, HIGH);
	delay(500);
	spiBridge.writeGPIO(3, LOW);
	delay(500);

	for(uint8_t i = 0; i < (1 << 4); i++) {
		spiBridge.writeGPIOBank(i);
		delay(500);
	}
	delay(2000);
	spiBridge.writeGPIOBank(0x00);
}
