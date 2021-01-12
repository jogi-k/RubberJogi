/*   
 *  RubberJogi
 *  ==========
 *  
 *  Receives Data on the serial (NOT USB-serial), parses it according to RubberDucky-Language-definition and "executes" then 
 *  on the USB-HID , keyboard and mouse.
 *  Use together with an USB TTL UART - connector to control a PC with a simulated keyboard. 
 *  Use it like its name-patron the RubberDucky, but:
 *  Instead of reading the RubberDucky-Script from SD-card, RubberJogi receives its commands from the Controller-PC
 *  
 */



#include <Keyboard.h>
#include <Mouse.h>

String action = "";
boolean complete = false;


void setup() {
  Serial1.begin(9600);
  Serial1.print("Hi from Arduino"); 
  Keyboard.begin();
  delay( 2000 );
  Keyboard.print("Hello from Arduino");
  // reserve 100 bytes for the inputString, attention, this might need to be improved? Need to check String-Class
  action.reserve(100);

}

// Only stupid demo-stuff, playing around needs to be removed finally Hello from Arduino 

void ShowMouseMove( void )
{
   int i;
   for ( i = 0; i < 200; ++i )
   {
      Mouse.move(-1, 0);
      delay( 5 );
   }
   for ( i = 0; i < 200; ++i )
   {
      Mouse.move( 1, 0 );
      delay( 5 );
   }
}



void loop() {

  serial1Event();

  // put your main code here, to run repeatedly:
  if (complete) {

    Serial1.println("Action: ");
    Serial1.println(action);

    if (action.equals("reboot")) {
      //trigger(10000); // shutdown
      //delay(2000);    // wait 1s
      //trigger(1500);  // boot up
      Serial1.println( "done");
    }
    else if (action.equals("boot")) {
      ShowMouseMove();
      //trigger(1500);  // boot up
      Serial1.println( "done");
    }
    else if (action.equals("aten")) {
      //switch_aten(1500);  // switch aten-switch
      Serial1.println( "done");
    }

    else {
      Serial1.println( "n/a");
    }
    action = "";
    complete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serial1Event() {
  while (Serial1.available()) {

    // get the new byte:
    char inChar = (char)Serial1.read();

    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      complete = true;
    } else {
      // add it to the inputString:
      action += inChar;
    }
  }
}
