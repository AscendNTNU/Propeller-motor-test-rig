#include "SerialPkt.h"

SerialPkt::SerialPkt() {
  id = 0;
  length = 0;
}

bool
SerialPkt::read() {
  if(Serial.available()) {
    char r = Serial.read();
    if(r == 't') {
      while (!Serial.available()) {}
      id = Serial.read();
      while (!Serial.available()) {}
      length = Serial.read();
      for(int i = 0; i < length; i++) {
        while (!Serial.available()) {}
        data[i] =  Serial.read();
      }
        return true;
    }
  }
  return false;
}
