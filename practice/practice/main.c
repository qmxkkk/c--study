#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const int a = 0;
	int* p = &a;
	*p = 20;
	printf("%d\n", a);
	return 0;
}