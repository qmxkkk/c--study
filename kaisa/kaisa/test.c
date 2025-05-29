#define _CRT_SECURE_NO_WARNINGS
#include "kaisa.h"

void memu()
{	
	printf("1.加密    2.解密    0.退出\n");
}


int main()
{
	int arr[500] = {0};
	int key = 0;
	int sz = 500;
	int input = 0;

	do
	{
		memu();
		scanf("%d%*c", &input);
		switch (input)
		{
		case 1:
			printf("请输入原文：\n");
			scanf("%[^\n]", arr);
			printf("请输入密钥：");
			scanf("%d", &key);
			kaisa(arr, sz, key);
			printf("这是密文，请拿好：\n%s\n", arr);
			break;
		case 2:
			printf("请输入密文：\n");
			scanf("%[^\n]", arr);
			printf("请输入密钥：");
			scanf("%d", &key);
			kaisa(arr, sz, -key);
			printf("这是原文，请拿好：\n%s\n", arr);
			break;
		case 0:
			printf("正在退出程序......\n");
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}

	} while (input);

	
	return 0;
}