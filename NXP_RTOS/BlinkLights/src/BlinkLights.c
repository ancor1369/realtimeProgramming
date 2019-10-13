/*
===============================================================================
 Name        : BlinkLights.c
 Author      : Andres Cordoba
 Version     :
 Copyright   : This software is provided as is for learning purposes
 Description : main definition
===============================================================================
*/


#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

#define timeCnt 3;

static void setHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}

/*This is the Task for LED 1*/
static void LED1_Task(void *pvParameters)
{
	bool LedState = false;
	while (1)
	{
		LedState = false;
		Board_LED_Set(0, LedState);
		vTaskDelay(configTICK_RATE_HZ);
		LedState = true;
		Board_LED_Set(0, LedState);
		vTaskDelay(3*configTICK_RATE_HZ);
	}
}

///*This is the thread for LED 2*/
static void LED2_Task(void *pvParameters)
{
	bool LedState = false;
	while(1)
	{
		LedState = true;
		Board_LED_Set(1, LedState);
		vTaskDelay(configTICK_RATE_HZ);
		LedState = false;
		Board_LED_Set(1, LedState);
		vTaskDelay(2*configTICK_RATE_HZ);
		LedState = true;
		Board_LED_Set(1, LedState);
		vTaskDelay(configTICK_RATE_HZ);
	}
}
//
///*This is the thread for LED 2*/
static void LED3_Task(void *pvParameters)
{
	bool LedState = false;
	while(1)
	{
		LedState = true;
		Board_LED_Set(2, LedState);
		vTaskDelay(3*configTICK_RATE_HZ);
		LedState = false;
		Board_LED_Set(2, LedState);
		vTaskDelay(configTICK_RATE_HZ);
	}

}


int main(void)
{
	setHardware();
	//Create the first version of the code
	xTaskCreate(LED1_Task, (signed char *) "LED1_Task",
					configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL);

	xTaskCreate(LED2_Task,(signed char *) "LED2_Task",
					configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY + 2UL),
					(xTaskHandle *)NULL);

	xTaskCreate(LED3_Task,(signed char *) "LED3_Task",
					configMINIMAL_STACK_SIZE,NULL,(tskIDLE_PRIORITY + 3UL),
					(xTaskHandle * )NULL);

    vTaskStartScheduler();
    return 0 ;
}
