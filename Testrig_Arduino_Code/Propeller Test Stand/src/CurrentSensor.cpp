#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(int analog_pin_p) {
    analog_pin = analog_pin_p;
    gain = 5/(1024*0.060);
}

int
CurrentSensor::sample() {
    int raw = analogRead(analog_pin);
    current = raw*gain-offset;
    return raw;
}

float
CurrentSensor::getCurrent() {
    return current;
}

void CurrentSensor::calibrate(int raw_1, float real_1, int raw_2, float real_2) {
    gain = (real_1-real_2)/(raw_1-raw_2);
    offset = real_1-gain*raw_1;
}
