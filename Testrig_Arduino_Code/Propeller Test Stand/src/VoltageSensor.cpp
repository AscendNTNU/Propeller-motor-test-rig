#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int analog_pin_p, int upper_resistor, int lower_resistor) {
  gain = lower_resistor/(upper_resistor+lower_resistor);
  voltage = 0;
  analog_pin = analog_pin_p;
}

int
VoltageSensor::sample() {
   int raw = analogRead(analog_pin);
   voltage = gain * analogRead(analog_pin);
   return  raw;
 }

float
VoltageSensor::getVoltage() {
  return voltage;
}
