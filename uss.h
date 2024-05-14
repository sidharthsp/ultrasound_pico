#ifndef USS_H
#define USS_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

typedef struct sensor_t
{
    int echo;
    int trigger;
} sensor_t;

void uss_init(sensor_t *sensor, int trigger, int echo);
float uss_read(sensor_t *sensor);
#endif