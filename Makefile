default:
	avr-gcc -Os -DF_CPU=16000000 -mmcu=atmega328p -c -o blink.o blink.c
	avr-gcc -o blink.bin blink.o
	avr-objcopy -O ihex -R .eeprom blink.bin blink.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/tty.usbserial-1D1110 -b 57600 -U flash:w:blink.hex
