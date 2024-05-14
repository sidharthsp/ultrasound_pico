
#include"uss.h"

int main(){
    stdio_init_all();
    gpio_init(5);
    gpio_set_dir(5, GPIO_OUT);
    sensor_t sensor;
    uss_init(&sensor,3,4);
    float distance;
    while (1){
        // printf("LED on!!\n");
        // gpio_put(5, 1);
        distance = uss_read(&sensor);
        printf("Time : %f\n", distance);
        // sleep_ms(1000);
        // printf("LED off!!\n");
        // gpio_put(5, 0);
        sleep_ms(1000);
    }
}