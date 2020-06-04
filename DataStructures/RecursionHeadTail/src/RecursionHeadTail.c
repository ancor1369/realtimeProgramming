/*
 ============================================================================
 Name        : RecursionHeadTail.c
 Author      : Andres Cordoba
 Version     :
 Copyright   : This is free software
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void fun(int n)
{
	if(n>0)
	{
		printf("%d ", n);
		fun(n-1);
	}
}

void fun1(int n)
{
	if(n>0)
	{
		fun1(n-1);
		printf("%d ", n);
	}
}



int main(void) {

	int x=3;

	printf("Way one\n");
	fun(x);
	printf("\nWay two\n");
	x=3;
	fun1(x);
	return EXIT_SUCCESS;
}
