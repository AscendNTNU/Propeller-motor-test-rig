#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <Arduino.h>

void p(char *fmt, ... );
void p(const __FlashStringHelper *fmt, ... );
void pln(char *fmt, ... );

#endif //PRINTF_H
