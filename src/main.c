#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "driver/gpio.h"
#include <custom_servo.h>

void app_main() {
    int servo0_pin = 14;
    int servo1_pin = 33;
    int servo2_pin = 26;
    add_servo(servo0_pin,0);
    add_servo(servo1_pin,1);
    add_servo(servo2_pin,2);
    servo_setPosition(0,0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(45,1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(90,2);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    servo_setPosition(90,0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(90,1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(135,2);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    servo_setPosition(160,0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(135,1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(160,2);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    servo_setPosition(90,0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(160,1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(0,2);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    servo_setPosition(0,0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(90,1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    servo_setPosition(90,2);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    delete_servo(0);
    delete_servo(1);
    delete_servo(2);
}