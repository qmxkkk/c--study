#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	a = rand()%10+1;
	printf("%d", a);
}