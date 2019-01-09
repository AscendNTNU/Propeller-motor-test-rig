#pragma once
#include <Arduino.h>

class VoltageSensor {
private:
  float gain;
  float voltage;
  int analog_pin;
public:
  VoltageSensor(int analog_pin_p, int upper_resistor, int lower_resistor);
  int sample();
  float getVoltage();
};
