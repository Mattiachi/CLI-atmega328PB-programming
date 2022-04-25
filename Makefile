###############################################################################
# Author: M. Chiappalone						      #
# Date: April 2022							      #
# This Makefile compiles the .c file and generates the files necessary        #
# to flash the .hex into the bootloader then it deletes the .bin and .o file  #
###############################################################################

# Defining Variables

file_name = blink		# Must match with the name of the .c file
baud_rate = 57600		# Use 57600 for arduino nano, Use 115200 for arduino Uno

default:
	avr-gcc -Os -DF_CPU=16000000 -mmcu=atmega328p -c -o $(file_name).o $(file_name).c
	avr-gcc -o $(file_name).bin $(file_name).o
	avr-objcopy -O ihex -R .eeprom $(file_name).bin $(file_name).hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/tty.usbserial-1D1110 -b $(baud_rate) -U flash:w:$(file_name).hex
	rm $(file_name).bin $(file_name).o rm$(file_name).hex
