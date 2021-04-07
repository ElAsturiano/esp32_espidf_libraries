#ifndef CUSTOM_SERVO_H
#define CUSTOM_SERVO_H

#include <stdio.h>
#include "driver/ledc.h"

// The following parameters can be adapted to certain kinds of servos and wished resolutions
static int f = 50;
static double T_us = 20000;
static double min_us = 500;
static double max_us = 2500;
static int pwmbits = LEDC_TIMER_14_BIT;

static bool timer_already_set;
static int n_o_servos;

static ledc_channel_config_t servo_channels[8];

int add_servo(int pin, int ID); // adds a servo to the list of servos and sets up timer and ledc pwm channel if necessary
int delete_servo(int ID); // deletes a servo from the list
int servo_setPosition(int degree, int ID); // sets a position in degrees for a certain servo
int servo_getPosition(int ID);  // returns a position in degrees for a certain servo
static void set_timer();
static void delete_timer();

#endif