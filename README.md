# CLI-atmega328PB-programming
This repo shows how to program in C any atmega328pb from CLI (iOS and Linux)

<h1>1.0) Installing AVR library:</h2>

For linux
  
Install the libraries

```
sudo apt install avr-libc avrdude binutils-avr gcc-avr
```
  
For ios 
 
Install the packet manager if not present
  
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
install home-brew
```
  
Install now avr libraries

  
```
brew tap osx-cross/avr
brew install avr-gcc
brew install avrdude
```  
Use then the following commands to flash the .c program into your mcu
  
```
avr-gcc -Os -DF_CPU=16000000 -mmcu=atmega328p -c -o blink_nano.o blink_nano.c
avr-gcc -o blink_nano.bin blink_nano.o
avr-objcopy -O ihex -R .eeprom blink_nano.bin blink_nano.hex
sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/tty.usbserial-1D1110 -b 57600 -U flash:w:blink_nano.hex
```
First line:
Where -O is for optimizing
-DF_CPU clock speed
-mmcu name of the chip you are programming
-c -o respectively name of the objectd file and file you programmed

Second line:
outputs the compiled file .bin

Fourth line:
Flashes the device using arduino programming process 
-p  is the port 

-b baud rate (use 57600 for arduino nano)

You can find at what port is your device with the following commands:

On linux
```
ls /dev/ | grep ACM
```
On ios
```
ls /dev/ | grep tty.usb
```
Lastly is possible to compile the program and flash it at once using the command ``` make ``` after creating a file named ``` Makefile ``` containing the previous commands.


Code understanding and registers
This is the schematic for the arduino nano. If we want to use the pin D2 we have to refer to the PD2 or Port D pin 2.

![alt text](https://github.com/Mattiachi/CLI-atmega328PB-programming/blob/main/images/arduino%20nano%20schematic.png)
  
In order to set PD2 as an output we have to set a bit high on the register "Data Direction Register D".

![alt text](https://github.com/Mattiachi/CLI-atmega328PB-programming/blob/main/images/DDRD.png)
 
In order to pull the PD2 to a high or low logical value we have to set a 1 or 0 on the register "Port D data register"

![alt text](https://github.com/Mattiachi/CLI-atmega328PB-programming/blob/main/images/PORTD.png)
