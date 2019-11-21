/*
===============================================================================
 Name        : BlinkLights.c
 Author      : Andres Cordoba
 Version     :
 Copyright   : This software is provided as is for learning purposes
 Description : main definition
===============================================================================
*/


#include "FreeRTOS.h"
#include "board.h"
#include "task.h"
#include "taskConfig.h"
#include "semphr.h"

//Define a mutex to access the GPIOs
xSemaphoreHandle xMutex;


static void setHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}

static void toggleLED(int * ledNum,bool * state)
{
	xSemaphoreTake(xMutex, portMAX_DELAY);
	{
		Board_LED_Set(*ledNum, *state);
	}
	xSemaphoreGive(xMutex);
}

static void GeneralLed_Task(void  *taskConfig1)
{toggleLED
	LedConfig *taskConfig = (LedConfig*)taskConfig1;

		bool LedState = false;
		bool redLed = false;
		int ledNumber;
		int delay1 = (int)taskConfig->tick_One;
		int delay2 = (int)taskConfig->tick_Two;
		int delay3 = (int)taskConfig->tick_Three;
		if(taskConfig->LedRed == true)
		{
			ledNumber = 0;
			redLed = true;

		}
		else if(taskConfig->LedGreen == true)
		{
			ledNumber = 2;
			redLed = false;

		}
		else if(taskConfig->LedBlue == true)
		{
			ledNumber = 1;
			redLed = false;
		}
		while(1)
		{
			if(redLed == 1)
			{
				LedState = false;
			}
			else
			{
				LedState = true;
			}
			toggleLED(&ledNumber,&LedState);
			vTaskDelay(configTICK_RATE_HZ*(delay1));
			LedState = (bool)!LedState;
			toggleLED(&ledNumber,&LedState);
			vTaskDelay(configTICK_RATE_HZ*(delay2));
			LedState = (bool)!LedState;
			toggleLED(&ledNumber,&LedState);
			vTaskDelay(configTICK_RATE_HZ*(delay3));
		}
}


int main(void)
{
	setHardware();

	//Start the mutex
	xMutex = xSemaphoreCreateMutex();

	LedConfig redConf =
	{
		.LedRed = true,
		.LedGreen = false,
		.LedBlue = false,
		.tick_One = 1,
		.tick_Two = 2,
		.tick_Three = 0
	};

	LedConfig greenConf =
	{
		.LedRed = false,
		.LedGreen = true,
		.LedBlue = false,
		.tick_One = 1,
		.tick_Two = 1,
		.tick_Three = 1
	};

	LedConfig blueConf =
	{
		.LedRed = false,
		.LedGreen = false,
		.LedBlue = true,
		.tick_One = 2,
		.tick_Two = 1,
		.tick_Three = 0
	};

	Board_LED_Set(0, true);
	Board_LED_Set(1, true);
	Board_LED_Set(2, true);

	if(xMutex != NULL)
	{

		xTaskCreate(GeneralLed_Task, (signed char *) "Red_Task", configMINIMAL_STACK_SIZE, &redConf, (tskIDLE_PRIORITY + 3UL),(xTaskHandle *) NULL);

		xTaskCreate(GeneralLed_Task, (signed char *) "Green_Task", configMINIMAL_STACK_SIZE, &greenConf, (tskIDLE_PRIORITY + 2UL),(xTaskHandle *) NULL);

		xTaskCreate(GeneralLed_Task, (signed char *) "Blue_Task", configMINIMAL_STACK_SIZE, &blueConf, (tskIDLE_PRIORITY + 1UL),(xTaskHandle *) NULL);

		vTaskStartScheduler();
	}

	while(1);
    return 0 ;
}
