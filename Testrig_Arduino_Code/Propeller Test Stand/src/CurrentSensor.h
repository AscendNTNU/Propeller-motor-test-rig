#pragma once
#include <Arduino.h>

class CurrentSensor {
private:
  float current;
  float offset;
  float gain;
  int analog_pin;
public:
  CurrentSensor(int analog_pin_p);
  int sample();
  float getCurrent();
  void calibrate(int raw_1, float real_1, int raw_2, float real_2);
};
