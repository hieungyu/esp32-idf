#ifndef LED_7_SEGMENT_H
#define LED_7_SEGMENT_H
#include "stdint.h"

#define NUMBER_SEGMENTS 7

extern int seg_pins[NUMBER_SEGMENTS];

extern const uint8_t seg_code[10];

void display_digit(uint8_t num);

#endif // LED_7_SEGMENT_H
