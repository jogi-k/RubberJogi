#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial1.print("Hi from Arduino"); 
  Keyboard.begin();
  delay( 2000 );
  Keyboard.print("Hello from Arduino");
}


void loop() {
 int incoming; 
  // put your main code here, to run repeatedly:
 if (Serial1.available()) {      // If anything comes in Serial1 (pins 0 & 1),
    incoming = Serial1.read();
    if( incoming > 0 )   
      if( isPrintable(incoming) )
        Keyboard.write(incoming);

  }

}
