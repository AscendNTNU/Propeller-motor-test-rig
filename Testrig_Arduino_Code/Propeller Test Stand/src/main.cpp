#include <Arduino.h>
#include "printf.h"
#include "SerialPkt.h"

SerialPkt msg;

double rand_walker[] = {0, 0};
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
    rand_walker[0] += (float)random(-10, 10)/10;
    rand_walker[1] += (float)random(-10, 10)/10;
    //p("%i\n", rand_walker);
    Serial.print(rand_walker[0], 3);
    Serial.print(" ");
    Serial.println(rand_walker[1], 3);
    //pln("%.2f %.2f %f %f", rand_walker[0],  rand_walker[1], rand_walker[0],  rand_walker[1]);
    delay(100);
}
