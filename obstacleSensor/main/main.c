//#include "freertos/FreeRTOS.h"
//#include "esp_wifi.h"
//#include "esp_system.h"
//#include "esp_event.h"
//#include "esp_event_loop.h"
//#include "nvs_flash.h"
#include "driver/gpio.h"
//#include<stdio.h>


#define BLINK_GPIO 2
#define SENSOR_GPIO 26

void app_main(void)
{
	gpio_pad_select_gpio(BLINK_GPIO); 
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

	//GIO pin number 26 for obstacle sensor 
	gpio_pad_select_gpio(SENSOR_GPIO); 
  	gpio_set_direction(SENSOR_GPIO, GPIO_MODE_INPUT);
    

    while (true) {
      
		//reading values on GPIO 26
    	if(gpio_get_level(SENSOR_GPIO))
    	{
    		gpio_set_level(BLINK_GPIO, 1);
    	}
    	else
    	{
    		gpio_set_level(BLINK_GPIO, 0);
    	}
    }
}