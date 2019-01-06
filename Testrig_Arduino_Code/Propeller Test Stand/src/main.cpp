#include <Arduino.h>
#include "printf.h"


int i;
void setup() {
  Serial.begin(9600);

  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }
  pln("Begin Transmition");
  i = 0;
}

void loop() {
    pln("Numb: %i", i++);
    delay(200);

}
