#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myIntma.h"
#include "romanNumToInt.h"
#include "myMath.h"


//void Swap(int *px,int *py)
//{
//	*px = *px ^ *py;
//	*py = *px ^ *py;
//	*px = *px ^ *py;
//
//}



//int numarr(int arr[])
//{
//	int num = sizeof(arr) / sizeof(arr[0]);
//	return num;
//}

int main()
{
	//int a = 0, b = 0;
	//scanf("%d\n%d", & a, &b);
	//printf("交换前 a=%d b=%d", a, b);
	//Swap(&a, &b);
	//printf("交换前 a=%d b=%d", a, b);
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//int k = numarr(arr);
	/*printf("%d", k);*/


	//printf("请输入数字：\n");
	//int a = 0;
	//scanf("%d", &a);
	//int dir = 0;
	//scanf("%d", &dir);

	//int b = mynum(a);
	//printf("位数为：%d\n", b);
	//int ret = mydirnum(a,dir);
	//printf("第%d位为%d\n", dir,ret);
	//oboprint(a);
	//if (isPalindrome(a))
	//{
	//	printf("\n是回文！");
	//}
	//else
	//{
	//	printf("\n不是回文！");
	//}

	//char input[] = "ici";
	//int lenght = strleng(input);
	//int a = isTwoSame(input,1);
	//int b = sameNum(input, 0);
	//int c = anyRomanToInt(input);
	//printf("\033[38;2;57;197;187m");
	//printf("%d\n", a);
	//printf("%d\n", b);

	//printf("%d\n", lenght);

	//printf("%d\n", c);


	//五位数内的水仙数
	//int n = 1461;
	//int is = 0;
	//int i = 0;
	//for (i = 1; i < 100000; i++)
	//{
	//	is = isLilynum(i);
	//	if (is)
	//		printf("%d ",i);
	//}
	
	int a = 0;
	int pa = &a;
	int* pb = &a;
	printf("%p\n", pb);
	printf("%p", pa);





	return 0;
}