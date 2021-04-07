#include <custom_servo.h>


int add_servo(int pin, int ID){
    if ((ID < 0) || (ID > 7)){
        return -1;
    }
    
    // if no timer is set, set up a timer and initialize servo
    if (timer_already_set != true){
        set_timer();
        timer_already_set = true;
        n_o_servos = 0;
    }

    ledc_channel_config_t temp_channel = {
            .channel    = ID,
            .duty       = 0,
            .gpio_num   = pin,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_TIMER_0
    };
    servo_channels[ID] = temp_channel;
    ledc_channel_config(&servo_channels[ID]);
    n_o_servos++;
    printf("Adding servo no. %d on pin %d. Now tracking %d servos.\n", ID, pin, n_o_servos);
    return 0;
}
int delete_servo(int ID){
    if ((ID < 0) || (ID > 7)){
        return -1;
    }
    ledc_stop(LEDC_HIGH_SPEED_MODE,ID,0);
    n_o_servos--;
    printf("Deleting servo no. %d. Now tracking %d servos.\n", ID, n_o_servos);
    if (n_o_servos == 0){
        // if the last servo has been removed, the timer has to be deleted
        delete_timer();
        timer_already_set = false;
    }
    return 0;
}

int servo_setPosition(int degree, int ID){
    if (((ID < 0) || (ID > 7)) || ((degree < 0) || (degree > 180))){
        return -1;
    }
    double factor_delta = (max_us-min_us)/T_us;
    double factor_min = min_us/T_us;
    double percent = (((double)degree)/180)*factor_delta + factor_min;
    int temp_duty = percent*((1<<pwmbits) - 1);
    printf("Channel Duty set to %d.\n", temp_duty);
    printf("Duty percentage set to %f.\n", percent);
    printf("Degrees set to %d.\n", degree);
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,ID,temp_duty);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE,ID);
    return 0;
}
int servo_getPosition(int ID){
    if ((ID < 0) || (ID > 7)){
        return -1;
    }
    double factor_delta = (max_us-min_us)/T_us;
    double factor_min = min_us/T_us;
    int temp_duty = ledc_get_duty(LEDC_HIGH_SPEED_MODE,ID);
    double percent = ((double)temp_duty)/((1<<pwmbits) - 1);
    int degree = (percent - factor_min)*180/factor_delta;
    return degree;
}

static void set_timer(){
    // Configuration for timer0
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = pwmbits,   // resolution of PWM duty
        .freq_hz = f,                          // frequency of PWM signal (50Hz equals 20ms duty cycle)
        .speed_mode = LEDC_HIGH_SPEED_MODE,             // timer mode
        .timer_num = LEDC_TIMER_0,             // timer index
        .clk_cfg = LEDC_AUTO_CLK,               // Auto select the source clock
    };
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer);
    printf("Setting timer.\n");
}
static void delete_timer(){
    // Delete Timer 0 in HS mode
    ledc_timer_rst(LEDC_HIGH_SPEED_MODE, LEDC_TIMER_0);
    printf("Deleting timer.\n");
}