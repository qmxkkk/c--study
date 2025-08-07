#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//int reverse(int x) 
//{
//	if (x == 0x80000000)
//		return 0;
//	int a = 0, log = 0, i = 0, eLog = 0;
//	if (x <= 0)
//		log = 1;
//	eLog = log;
//	for (int k = 1;k != 0;i++)
//	{
//		k = x / pow(10, i);
//	}
//	i-=2;
//	for (int o=0,k=0;i < 10 && x / pow(10, i) && i>=0;i--)
//	{
//		k = (x / pow(10, i));
//		a +=  k * pow(10, o);
//		x %= (int)pow(10, i);
//		o++;
//		if (a <= 0)
//			log = 1;
//		if (eLog != log)
//			return 0;
//	}
//	if (a == 0x80000000)
//		return 0;
//	return a;
//
//}

int reverse(int x)
{
	int a = 0;
	for (;x != 0;)
	{
		if (a < -214748364 || a > 214748364)
			return 0;
		a = a * 10 + (x % 10);
		x /= 10;
	}
	return a;

}

int main()
{
	int x = -15638412;
	printf("%d", reverse(x));
	int p = pow(10, 0);
	//printf("%d", p);
	return 0;
}