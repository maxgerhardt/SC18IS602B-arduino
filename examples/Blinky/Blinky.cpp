#include "Arduino.h"
#include "SC18IS602B.h"

SC18IS602B spiBridge;

void setup() {
	//Startup I2C interface on D1 (SDA) and D2 (SCL)
	//for the ESP8266
#ifdef ARDUINO_ARCH_ESP8266
	spiBridge.begin(D1, D2);
#else
	spiBridge.begin();
#endif

	//Setup SS0 / GPIO0 to be a GPIO pin, set to push-pull output
	spiBridge.enableGPIO(0, true);
	spiBridge.setupGPIO(0, SC18IS601B_GPIO_MODE_PUSH_PULL);
}

void loop() {
	spiBridge.writeGPIO(0, HIGH);
	delay(500);
	spiBridge.writeGPIO(0, LOW);
	delay(500);
}
