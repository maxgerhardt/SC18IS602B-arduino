# SC18IS602B-arduino

### Description

This is an Arduino library for the SC18IS602B I2C to SPI bridge. It features 4 slave-selects and a 200 byte data buffer with a maximum SPI speed of 1.8 MBit/s.

It offers the following functionality:

* GPIO configuration (input, output, open drain, quasi-bidirectional)
* GPIO reading and writing 
* SPI configuration
   * SPI clock choosable from 58 kHz to 1.843 MHz
   * SPI mode 0 to 3 supported
* SPI transfers in chunks of at maximum 200 byte
* Putting the chip into low-power mode

It is compatible with various Arduino cores, such as:

* Arduino Uno / Nano
* ESP8266
* ESP32

### Wireup

All I/O levels are 3.3V! Make sure you have a level-shifter if you connect it to 5V devices.

* VSS to GND
* VDD to 3.3V
* SDA and SCL to your board's I2C bus
* MISO, MOSI, SCLK and SS0 to SS3 to your target device's SPI bus(ses) **or** SS0 to SS3 as GPIOs to wherever your like
* RESET to some pin on your microcontroller (optional)
* INT is not used, data buffer is polled instead

### Troubleshooting 

Run the [I2C scanner sketch](https://playground.arduino.cc/Main/I2cScanner) to check if your device can see the I2C device and whether the address is the expected one.

### Technical documents

* datasheet: https://www.nxp.com/docs/en/data-sheet/SC18IS602B.pdf

### Other resources

* Buyable module: http://sandboxelectronics.com/?product=sc18is602-i2c-to-spi-bridge-module
* Datasheet for that module: http://sandboxelectronics.com/?p=485

### Credits

All code was written by me only with the help of the datasheet.