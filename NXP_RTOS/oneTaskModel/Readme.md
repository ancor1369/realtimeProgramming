# How to implement a single task with multiple instances 

To show up the basics of how the an RTOS works, we are using the platform LPCExpresso 1796 that features an ARM cortex M3 LPC1769FBD100 processor and some IO to use it as the core of any application where it might be useful.

This implementation is an extension of the blinking LED where the intention is to create a sequence of colors where no color overlaps each other.

This time, the challenge was to make the implementation with a single definition of task and three different instances of the same, so that it is possible to see how three different instances interact in the system.

This time the definition of the task is show in the following code:

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
	if(taskConfig->LedRed == 1)
	{
		ledNumber = 0;
		redLed = true;

	}
	else if(taskConfig->LedGreen == 1)
	{
		ledNumber = 2;
		redLed = false;

	}
	else if(taskConfig->LedBlue == 1)
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
		Board_LED_Set(ledNumber, LedState);
		vTaskDelay(configTICK_RATE_HZ*(delay1));
		LedState = (bool)!LedState;
		Board_LED_Set(ledNumber, LedState);
		vTaskDelay(configTICK_RATE_HZ*(delay2));
		LedState = (bool)!LedState;
		Board_LED_Set(ledNumber, LedState);
		vTaskDelay(configTICK_RATE_HZ*(delay3));

	}
}
```

Since the task is generic, It accepts an object containing the information needed to configure three different delaus and to figure out which is the LED that needs to be set.

An Struct was defined to pass the information in an organized way to the task.

```C


struct taskConfiguration
{
	bool LedRed;
	bool LedGreen;
	bool LedBlue;
	int tick_One;
	int tick_Two;
	int tick_Three;
};

typedef struct taskConfiguration LedConfig;

```

Finally the three instances of the task. Each instance is inteded to manage each one of the LEDS to form the three colors on the board.

```C
int main(void)
{
.
.
.

xTaskCreate(GeneralLed_Task, (signed char *) "Red_Task", configMINIMAL_STACK_SIZE, &redConf, (tskIDLE_PRIORITY + 3UL),(xTaskHandle *) NULL);

xTaskCreate(GeneralLed_Task, (signed char *) "Green_Task", configMINIMAL_STACK_SIZE, &greenConf, (tskIDLE_PRIORITY + 2UL),(xTaskHandle *) NULL);

xTaskCreate(GeneralLed_Task, (signed char *) "Blue_Task", configMINIMAL_STACK_SIZE, &blueConf, (tskIDLE_PRIORITY + 1UL),(xTaskHandle *) NULL);

.
.
.
}
```

The following image describes the timing diagram implemented.It is a Rate monotonic approach. 

![image](https://user-images.githubusercontent.com/25968721/68079771-56505280-fdc5-11e9-89b1-5065a1ff3837.png)

This is the result on the hardware.

![image](https://user-images.githubusercontent.com/25968721/68079908-ef806880-fdc7-11e9-9079-e689684e9782.png)

![image](https://user-images.githubusercontent.com/25968721/68079917-0cb53700-fdc8-11e9-88c1-88f25ae747df.png)


![image](https://user-images.githubusercontent.com/25968721/68079921-28204200-fdc8-11e9-9178-107d9ef4d0a0.png)


