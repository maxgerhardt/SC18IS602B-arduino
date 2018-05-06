#include "Arduino.h"
#include "SC18IS602B.h"

SC18IS602B spiBridge;

/* Connect SS0/GPIO0 to a push button with external pull-up resistor. */

void setup() {
	//Startup I2C interface on D1 (SDA) and D2 (SCL)
	//for the ESP8266
#ifdef ARDUINO_ARCH_ESP8266
	spiBridge.begin(D1, D2);
#else
	spiBridge.begin();
#endif

	//Set SS0 / GPIO0 to GPIO and put in input mode
	spiBridge.enableGPIO(0, true);
	spiBridge.setupGPIO(0, SC18IS601B_GPIO_MODE_INPUT_ONLY);
}

void loop() {
	bool val = spiBridge.readGPIO(0);
	Serial.println("GPIO0: " + String(val));
}
