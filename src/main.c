// USER INCLUDE
#include <LiquidCrystal_I2C.h>

// SDK INCLUDE
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <hardware/i2c.h>


// GLOBAL DECLARATIONS -------------------
const unsigned long I2C_CLOCK = 100000;
const uint8_t LCD_I2C_ADDRESS = 0x27;


void setup(void)
{
	stdio_init_all();

	/* Initialize LED for status indicator */
	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
	gpio_put(PICO_DEFAULT_LED_PIN, 0);
	
	/* Initiate I2C-0 Bus 
		LiquidCrystal API I created also provides auto 
		initialization in case user forgot to initialize the I2C bus.

		The code below is also the same one used for I2C auto initialization.
	*/
	// gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
	// gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
	// gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
	// gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
	// i2c_init(i2c_default, I2C_CLOCK );

	/* Initialize LCD I2C module */
	lcd_init(i2c_default, LCD_I2C_ADDRESS);
	lcd_set_cursor(3,0);
	lcd_print("Hello world!");
}

void main1(void)
{
	while(1)
	{
		gpio_put(PICO_DEFAULT_LED_PIN, 1);
		sleep_ms(70);
		gpio_put(PICO_DEFAULT_LED_PIN, 0);
		sleep_ms(300);
	}
	return;
}


int main(void){

	setup();

	/* 
		Launch core 1 to blink status LED
		indicating that we succeeded in entering main loop 
	*/
	multicore_launch_core1(main1);
	int count = 0;

	while(1)
	{
		lcd_clear();
		sleep_ms(1500);

		lcd_set_cursor(count,count*5);
		lcd_print("Hello World");
		sleep_ms(1500);

		count++;
		if(count > 3) count = 0;
	}
	return 0;
}