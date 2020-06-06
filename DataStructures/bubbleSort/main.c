/*
 * main.c
 *
 *  Created on: Jun. 6, 2020
 *      Author: andres
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;

}

void bubbleSort(int A[], int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-1;j++)
		{
			if(A[j]<A[j+1])
			{
				swap(&A[j], &A[j+1]);
			}
		}
	}
}


void printArray(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}


void main()
{
	int Arr[]={1,6,4,5,3,2,4,3,8,9,9,2,1,3};
	int n = 15;
	printArray(Arr,n);
	bubbleSort(Arr,n);
	printArray(Arr,n);
}

