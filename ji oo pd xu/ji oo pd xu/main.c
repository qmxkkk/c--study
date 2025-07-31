#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int printInt(int* target,int num) 
{
	int i = 0;
	for (;i < num;i++)
	{
		printf("%d ", target[i]);

	}
	return i;
}


void inputInt(int* target,int num)
{
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &target[i]); // 使用&运算符获取数组元素的地址
	}
}

int paritySeparation(int* target,int num)
{
	int j = num - 1;
	int i = 0;
	int temp = 0;
	while (i < j)
	{
		if (!(target[i] % 2))
		{
			if (target[j] % 2)
			{
				temp = target[i];
				target[i] = target[j];
				target[j] = temp;
				i++;
			}
			else
				j--;

		}
		else
			i++;

	}

	
}

int main()
{
	int num_1[10] = {6,5,9,3,4,1,1,6,7,2};
	int o = 2;
	int num[10] = { 0 };
	inputInt(num, 10);
	paritySeparation(num, 10);
	printInt(num, 10);
	return 0;
}