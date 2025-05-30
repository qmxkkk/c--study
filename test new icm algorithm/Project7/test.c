#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//实现最大公因数和最小公倍数的算法


int icm_algorithm(int a, int b)
{
	int min = (a < b ? a : b);
	int tmin = min;
	int max = (a > b ? a : b);
	for (;min % max != 0;min += tmin);
	return min;
}

int new_icm_algorithm(int a, int b)
{
	int gcd = new_gcd_algorithm(a, b);
	return (a * b) / gcd;
}

int new_gcd_algorithm(int a, int b)
{
	int min = (a < b ? a : b);
	int max = (a > b ? a : b);
	return new_gcd_algorithm_in(max, min);

}

int new_gcd_algorithm_in(int a, int b)
{
	if (a % b == 0 || a / b == 0)
		return b;
	new_gcd_algorithm_in(b, a % b);
}

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", icm_algorithm(a, b));
	printf("%d\n", new_icm_algorithm(a, b));
	return 0;
}