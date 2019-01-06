#include <Arduino.h>
#include "printf.h"


void setup() {
  Serial.begin(9600);

  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }
  randomSeed(analogRead(0));
}

void loop() {
    static int rand_walker = 0;
    rand_walker += random(-10, 10);
    //p("%i\n", rand_walker);
    Serial.println(rand_walker);
    delay(100);
}
