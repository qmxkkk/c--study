#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void jingdu(int i, int sum);

int main()
{
	srand((unsigned int)time(NULL));
	int ranNum = 0;
	int xz = 0, axz = 0;
	int i = 0,sum = 10000000;
	int s = 0;
	int min = 0, max = 0;
	int a = 0, b = 0, c = 0;
	int pa = 0, pb = 0, pc = 0;
	int cishu = 10;
	for (int x = 0;x < cishu;x++)
	{
		a = 0;
		b = 0;
		c = 0;
		for (i = 0;i < sum;i++)
		{
			ranNum = rand() % 3 + 1;
			//xz = rand() % 3 + 1;
			//if (xz == ranNum)
			//{
			//	a++;
			//}
			switch (ranNum)
			{
			case 1:
				a++;
				break;
			case 2:
				b++;
				break;
			case 3:
				c++;
				break;
			}
			jingdu(i, sum-1);

			/*if (xz == ranNum)
			{
				s = rand() % 2;
				switch (ranNum)
				{
				case 1:
					min = 2;
					max = 3;
					break;
				case 2:
					min = 1;
					max = 3;
					break;
				case 3:
					min = 1;
					max = 2;
					break;
				}
				switch (s)
				{
				case 0:
					axz = min;
					break;
				case 1:
					axz = max;
					break;
				}
				if (axz == ranNum)
				{
					a++;
				}

			}
			else
			{
				a++;
			}*/
			
			/*printf("%d\n", a);*/

		}
		//printf("%d\n", a);
		printf("%d %d %d\n", a, b, c);
		pa += a;
		pb += b;
		pc += c;
	}
	printf("\n%d %d %d\n", pa / cishu, pb / cishu, pc / cishu);
	
	//printf("%f %f %f\n", a / 100000.0f, b / 100000.0f, c / 100000.0f);
	return 0;
}

void jingdu(int i, int sum)
{
	int bianl = i;
	int y = (sum + 1) / 10;
	if (bianl % y == 0)
	{
		printf("0");
	}
	else if (bianl == sum)
	{
		printf("\n");
	}
}