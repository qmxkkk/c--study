#define _CRT_SECURE_NO_WARNINGS
#include "kaisa.h"

void memu()
{	
	printf("1.����    2.����    0.�˳�\n");
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
			printf("������ԭ�ģ�\n");
			scanf("%[^\n]", arr);
			printf("��������Կ��");
			scanf("%d", &key);
			kaisa(arr, sz, key);
			printf("�������ģ����úã�\n%s\n", arr);
			break;
		case 2:
			printf("���������ģ�\n");
			scanf("%[^\n]", arr);
			printf("��������Կ��");
			scanf("%d", &key);
			kaisa(arr, sz, -key);
			printf("����ԭ�ģ����úã�\n%s\n", arr);
			break;
		case 0:
			printf("�����˳�����......\n");
			break;
		default:
			printf("�����������������룺\n");
			break;
		}

	} while (input);

	
	return 0;
}