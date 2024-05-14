#include"uss.h"


static int timeout = 26100;
void uss_init(sensor_t *sensor, int trigger, int echo){
    sensor->echo = echo;
    sensor->trigger = trigger;
    gpio_init(sensor->echo);
    gpio_init(sensor->trigger);
    gpio_set_dir(sensor->echo, GPIO_IN);
    gpio_set_dir(sensor->trigger, GPIO_OUT);
    }

float  uss_read(sensor_t *sensor){
    
    

    gpio_put(sensor->trigger, 1);
    printf("triggered! \n");
   
    sleep_us(10);
    gpio_put(sensor->trigger, 0);

    uint64_t width = 0;
    



    while (!gpio_get(sensor->echo))
    {
        tight_loop_contents();
    }
    
    absolute_time_t startTime = get_absolute_time(); 

    while (gpio_get(sensor->echo))
    {
        width++;
        sleep_us(1);
        if (width > timeout) return 0;
    }
    
    
    absolute_time_t endTime = get_absolute_time(); 


    // printf("%d is high! \n", sensor->echo);
    return absolute_time_diff_us(startTime, endTime)/29/2;
    // return 0.00;

    }

