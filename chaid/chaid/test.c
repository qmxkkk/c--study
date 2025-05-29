#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int input = 0, layer = 2, temp = 0, c = 0, d = 0/*sum*/, di = 0, ret = 0;
	temp = input;
	layer = temp / 3;
	c = temp / 2 - layer + 1;
	while (c >= 1)
	{

	}
	

	di = input * input % 4;
	ret = di + d;
	printf("%d", ret);
	return 0;
}

//int main()
//{
//	char a[50];
//	for (int x=0;x < 50;x++)
//	{
//		printf("%p", a[x]);
//	}
//}