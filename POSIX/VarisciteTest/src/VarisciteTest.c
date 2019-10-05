/*
 ============================================================================
 Name        : VarisciteTest.c
 Author      : Andres Cordoba
 Version     :
 Copyright   : This is provided as an example, can be used for other purposes
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int number = 0;
int stop = 1;
int set[3];

void showNumbers(void *array)
{
	int *conv = (int*)array;
	for(int i = 0; i<3; i++)
	{
		printf("Number: %d \n",conv[i]);
	}
}

void *theRecurrentFunciton(void *aVariable)
{
	int *casted = (int*)aVariable;
	while(stop)
	{
		casted++;
		usleep(10000);
	}
}

int main(void)
{
	pthread_t handleThread1;

	if(pthread_create(&handleThread1,NULL,&theRecurrentFunciton,&number)!=0)
	{
		printf("Thread not correctly created");
		return 0;
	}

	printf("This is a sample program for 3005\n");

	for(int i = 0; i<3; i++)
	{
		printf("Please enter a number\n");
		scanf("%d",&set[i]);
	}
	stop = 0;
	pthread_cancel(handleThread1);
	showNumbers(&set);
	return EXIT_SUCCESS;
}
;
