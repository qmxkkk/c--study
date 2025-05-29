#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	register int  l = 2, d = 0, b = 1, c = 0, y = 6, k = 0, p = 0;//l是层数，d是总结果，b是子层自变量，y是数字自变量，k是子层因变量，p是总结果
//	register int di = 0;
//	int x = 6;
//	printf("请输入：");
//	scanf("%d", &x);
//	while (y <= x) {
//		l = 2;
//		k = (y / (3 * l));
//		while (k >= 1) 
//		{
//			b = 1;
//			c = ((y - (b * l)) / 2) - (l - 1);
//			while (c >= 1) 
//			{
//				d += c;
//				b += 1;
//				c = ((y - (b * l)) / 2) - (l - 1);
//			}
//			l += 1;
//			k = y / (3 * l);
//		}
//		y += 1;
//	}
//
//	di = x*x / 4;
//	p = d + di;
//
//	printf("%d", p);
//	int t = scanf("%d");
//	return 0;
//}


int main()
{
	int  l = 2, zl = 2, d = 0, b = 1, c = 0, y = 6, k = 0, p = 0,n=1;//l是层数，d是总结果，b是子层自变量，y是数字自变量，k是子层因变量，p是总结果
	int di = 0;
	int x = 0;
	printf("请输入：");
	scanf("%d", &x);
	if (x >= 6)
	{
		while (y <= x)
		{
			zl = 2;
			while (zl <= y / 3)
			{
				l = zl;
				c = ((y - (zl * n) -  l) / 2) - (l - 1);

				while (c>=1)
				{
					c = ((y - (zl * n) - l) / 2) - (l - 1);

					while (l <= y / 3)
					{
						b = 0;
						if (l > zl)
							b = 1;
						c = ((y - (zl * n) - (b * l)) / 2) - (l - 1);
						while (c >= 1)
						{
							d += c;
							b += 1;
							c = ((y - (zl * n) - (b * l)) / 2) - (l - 1);
						}
						l += 1;
					}
					n++;
				}
				
				zl++;
			}
			
			y += 1;
		}
	}


	di = (x*x) / 4;
	p = d + di;

	printf("%d", p);
	int t = scanf("%d");
	return 0;
}