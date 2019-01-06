#include <Arduino.h>
#include "printf.h"
#include "SerialPkt.h"

SerialPkt msg;
void setup() {
  Serial.begin(9600);

  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }
}
int data[8];
void loop() {
  if(msg.read()) {
    for(int i = 0; i < msg.getLength(); i++) {
        Serial.println(msg.getData()[i]);
    }
  }
  delay(10);
  /*
    static int rand_walker = 0;
    rand_walker += random(-10, 10);
    //p("%i\n", rand_walker);
    Serial.println(rand_walker);
    delay(100);
    */
}
