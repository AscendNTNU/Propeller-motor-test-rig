#pragma once
#include <Arduino.h>

//Mesures voltage on a analog pin
class VoltageSensor {
private:
  float gain;
  float voltage;
  int analog_pin;
public:
  //Initialize with voltage divider on the analog pin
  VoltageSensor(int analog_pin_p, int upper_resistor, int lower_resistor);

  //Initialize without voltage divider
  VoltageSensor(int analog_pin_p);

  //Reads the analog inputs, updates the voltage value and returns the raw data
  int sample();

  //Returns the voltage
  float getVoltage();
};
