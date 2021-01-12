# RubberJogi

## What is the idea / the usecase ?

* You want to control a PC from another PC, making keystrokes, eventually mouse-moves.
* Even when starting up and e.g. entering the BIOS 
* => ssh etc not an option
* you need to be independant from any "client" on the controlled machine
* only solution which comes to mind is USB HID
* Therefore you connect from PC I somehow to PC II, on PC II as USB-Keyboard


## Solution : RubberJogi

+----------------+                                  +----------------+
|                |                                  |                |
|    PC I        |                                  |    PC II       |
|                |          +-------------+         |                |
|  (Controller)  |          |             |         |  (Worker)      |
|                +----------+ RubberJogi  +-------->+                |
|                |          |             |  USB    |                |
|                |          +-------------+         |                |
|                |                                  |                |
+----------------+                                  +----------------+



## Incredients Hardware


* Arduino ( with USB-Keyboard capability), e.g. Leonardo, Micro, etc
* USB-TTL UART Converter 
* some cables

## Incredients Software 

* Unfortunately : Work in Progress , WIP
* shall be compatible to the famous RubberDucky
* Parser needed for that scripting language
* based on https://github.com/Creased/arducky/blob/master/arducky.ino
* will be extended for also sending MOUSE-Movements
* will be extended to control two additional GPIO-Switches 



