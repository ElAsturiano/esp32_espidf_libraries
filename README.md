# esp32_espidf_libraries

## Introduction
A collection of self-made libraries for using stepper and servo motors, ultrasonic rangefinders and more peripheral devices on the ESP32 microcontroller.
This library collection is made for a project on an ESP32 where a couple of servo motors, stepper motors and ultrasonic range finders have to operate at the same time.
Please feel free to use them as you need. I will try to document the functions as best as I can.

## Contents
At the moment this collection includes:
- A library for controlling microservos: >custom_servo

## How to use
In general: To use x library, just copy the `library_x` folder in `lib` into the `lib`folder of your project. Then include the library header in your main c file with `#include library_x.h`.

### Controlling microservos with >custom_servo
There are basic parameters for the servos, which are set in the header file `custom_servo.h`:
- `f`:		The frequency of the used esp-timer in hertz. Normally microservos listen to PWM signals with this frequency.
- `T_us`:	The duration of a PWM signal period in microseconds. This number is the inverse of the frequency.
- `min_us`:	The duration of the PWM pulse in microseconds for 0 degrees.
- `max_us`:	The duration of the PWM pulse in microseconds for 180 degrees.
- `pwmbits`:	The resolution of the PWM signal.

After including the library you can use the following commands in your code:
- `add_servo(int pin, int ID)`:			This adds a servo on pin `pin` to a list of max. 8 servos (restricted by the max. number of timer channels on the ESP) with the ID `ID`. It returns 0 if everything went fine and -1 if there was an error.
- `delete_servo(int ID)`:			This deletes the servo with the ID `ID` from the list of servos. It returns 0 if everything went fine and -1 if there was an error.
- `servo_setPosition(int degree, int ID)`:	This sets the degrees (0-180) specified in `degree` on the servo with the ID `ID`. It returns 0 if everything went fine and -1 if there was an error.
- `servo_getPosition(int ID)`:			This returns the position in degrees (0-180) of the servo with the ID `ID`. It returns -1 if there was an error.