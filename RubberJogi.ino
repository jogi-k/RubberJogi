// RubberJogi
// ==========
//
// Use it like its name-patron the RubberDucky, but:
// Instead of reading the RubberDucky-Script from SD-card, RubberJogi receives
// its commands from the Controller-PC
//
// Receives Data on the serial1 (NOT USB-serial), parses it according to
// RubberDucky-Language-definition and "executes" then on the USB-HID , keyboard
// and mouse. Use together with an USB TTL UART - connector to control a PC with
// a simulated keyboard.
//
// Thanks very much to Baptiste M. (Creased) , who created arducky (
// https://github.com/Creased/arducky ) from where I have taken 90% of the base
// of this tool,

#include "RubberJogi.h"

RubberJogi rj;

void setup() { rj.printVersion(); }

void loop() {
  if (rj.readCommand()) {
    rj.parseCommand();
  }
}
