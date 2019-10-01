
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define MAXNUMBERS 10

int set[MAXNUMBERS];
int num_ints = 0;
int done = 0;

void showArray(void *arr)
{
	int *x=(int *)arr;
	for(int i = 0;i<num_ints;i++)
	{
		printf("%d \n",x[i]);
	}
}

void	*threadInput(void *setNumbers)
{
	int *x = (int *)setNumbers; //I cast the set of numbers into another array set
	int temp;

	while(done == 1)
	{
		for(int i = num_ints; i>0;i--)
		{
			if(x[i]<x[i-1])
			{
				temp = x[i-1];
				x[i-1] = x[i];
				x[i]=temp;
			}
		}
	}
	showArray(setNumbers);
	return x;
}


int main()
{
	pthread_t sortThread;

	if(pthread_create(&sortThread,NULL,&threadInput,&set))
	{
		//Program failed to run and the application finishes
		printf("Error while creating the thread");
		return 1;
	}

	for(num_ints = 0 ; num_ints< MAXNUMBERS;num_ints++)
	{
		printf("Please enter an integer\n");
		scanf("%d",&set[num_ints]);
	}

	done = 1;

	/*for(int i = 0; i<MAXNUMBERS; i++)
	{
		printf("%d \n", set[i]);
	}*/
	return 0;
}
