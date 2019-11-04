# An implementation of Free RTOS

To show up the basics of how the an RTOS works, we are using the platform LPCExpresso 1796 that features an ARM cortex M3 LPC1769FBD100 processor and some IO to use it as the core of any applicaiton where it might be useful.

The idea is to test the implementation of a very simple application to feature the FreeRTOS.

The application is implemented on the code exposed on the file src/BlinkLights.c.

The most important part is how a task is described:

In this delivery of the project,we are using Mutex to make resource management, so that the protected resource is not used by any other task
at the same time as it is beeing used by the task who holds the key.

To feature the Mutex functionality, the code has been modified to protect the LED state changing right of the application. It is achieved by using the functions:

```C
static void toggleLED(int * ledNum,bool * state)
{
	xSemaphoreTake(xMutex, portMAX_DELAY);
	{
		Board_LED_Set(*ledNum, *state);
	}
	xSemaphoreGive(xMutex);
}

```

This function blocks the ussage of the function Board_LED_Set by any other task on the system.


This implementation features only one model process with three different instances running at the same time. The next is the model of the single task. Please note the ussage of the function toggleLED(&ledNumber,&LedState), where the fucntion that contains the MUTEX is contained. 

```C

static void GeneralLed_Task(void  *taskConfig1)
{
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


```

And how it is later initialized, inside the main function it is necesary to call the method:

```C
int main(void)
{

xMutex = xSemaphoreCreateMutex();

.
.
.
if(xMutex != NULL)
	{

		xTaskCreate(GeneralLed_Task, (signed char *) "Red_Task", configMINIMAL_STACK_SIZE, &redConf, (tskIDLE_PRIORITY + 3UL),(xTaskHandle *) NULL);

		xTaskCreate(GeneralLed_Task, (signed char *) "Green_Task", configMINIMAL_STACK_SIZE, &greenConf, (tskIDLE_PRIORITY + 2UL),(xTaskHandle *) NULL);

		xTaskCreate(GeneralLed_Task, (signed char *) "Blue_Task", configMINIMAL_STACK_SIZE, &blueConf, (tskIDLE_PRIORITY + 1UL),(xTaskHandle *) NULL);

		vTaskStartScheduler();
	}
.
.
.
}
```

The objective of the implementation is to make the LEDs on the board to blink in sequence as it is stated on the following task operation graph.


![image](https://user-images.githubusercontent.com/25968721/68079771-56505280-fdc5-11e9-89b1-5065a1ff3837.png)
