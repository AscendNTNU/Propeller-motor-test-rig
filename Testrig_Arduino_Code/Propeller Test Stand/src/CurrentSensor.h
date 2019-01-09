#pragma once
#include <Arduino.h>

//Made to work with the ACS758 current sensor
//The sensor mesures current and outputs voltage
class CurrentSensor {
private:
  float current;
  float offset;
  float gain;
  int analog_pin;
public:

  //Initialize currentsensor on set analog pin
  CurrentSensor(int analog_pin_p);

  //Reads the analog inputs, updates the current value and returns the raw data
  int sample();

  //Returns the value of the current
  float getCurrent();

  //Takes two datapoints and sets the gain of the currentsensor
  void calibrate(int raw_1, float real_1, int raw_2, float real_2);
};
