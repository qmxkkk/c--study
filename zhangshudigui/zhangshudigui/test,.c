#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "zhengDiGui.h"


int main()
{
	int a = 0,c=0;
	int b = 0;
	scanf("%d%d", &a,&c);
	b = zhengDiGui(a,c);
	printf("%d", b);
	int t = scanf("%d");
	return 0;
}