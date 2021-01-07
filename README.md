# RubberJogi


An arduino connected with its serial line (not USB-Serial) to a USB2RSR232-converter.  
* The Arduino is a USB-HID-Keyboard
* on the serial line you can send RubberDucky - Script - Syntax
* This is converted to USB-HID to the connected PC.


## The idea

* You want to control a PC from another PC.
* Even down to the BIOS 
* ssh etc not an option
* you need to be independant from any "client" on the controlled machine
* only solution is USB HID
* Therefore you connect from PC I with USB-Serial to PC II as USB-Keyboard


## Incredients HW


* Arduino ( with USB-Keyboard capability)
* USB2RS232-Converter 
* some cables

## Software 

* shall be compatible to the famous RubberDucky
* Parser needed for that scripting language
* based on https://github.com/Creased/arducky/blob/master/arducky.ino


