
#include <Arduino.h>
#define PKT_DATA_LENGTH 16

class SerialPkt
{
private:
  int id;
  int length;
  int data[PKT_DATA_LENGTH];

public:
  SerialPkt();
  bool read();
  int getId() {return id;}
  int getLength() {return length;}
  int * getData() {return data;}
};
