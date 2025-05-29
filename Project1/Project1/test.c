#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main()
{
	int  l = 2, d = 0, b = 1, c = 0, y = 6, k = 0, p = 0;//l是层数，d是总结果，b是子层自变量，y是数字自变量，k是子层因变量，p是总结果
	double di = 0;
	int x = 6;
	printf("请输入：");
	scanf("%d", &x);
	while (y <= x) {
		l = 2;
		k = (int)floor(y / (3 * l));
		while (k >= 1) {
			b = 1;
			c = (int)floor(((y - (b * l)) / 2)) - (l - 1);
			while (c >= 1) {
				d += c;
				b += 1;
				c = (int)floor(((y - (b * l)) / 2)) - (l - 1);
			}
			l += 1;
			k = (int)floor(y / (3 * l));
		}
		y += 1;
	}
	if (x%2==0)
	{
		di = pow(x, 2) / 4;
	}
	else
	{
		di = (pow(x, 2) - 1) / 4;
	}
	di = (int)floor(di);
	p = d + di;
	printf("%d", p);


	return 0;
}