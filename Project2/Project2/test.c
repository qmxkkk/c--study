#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() 
{
	//char arr[] = "abcdef";
	//char arr2[] = { 'a','b','c','d','e','f',' '};
	//int len = strlen("a bc");
	//printf("%d\n", len);
	//printf("%s\n", arr);
	//printf("%s\n", arr2);
	//printf("\a");
	//int arr[3] = { 1,2,3,4 };
	//printf("     **\n     **\n************\n************\n    *  *\n    *  *");
	//EOF
	//char arr[] = { 'b','i','t',0 };
	//printf("%d\n", LENGTH(arr));
	////char arr2[10] = "hello bit";
	//int a = 5, b = 6;
	//int c = a > b ? a : b;
	//printf("%d\n",c);


	//c���Բ������������ִ���ģ�����úñ������õĴ���д��
	//if��else���Ӵ����ŵĻ���ֻʶ�����һ������
	//int a = 5;
	//if (a<4)
	//printf("������");
	//printf("̫������");
	//else
	//printf("5>4Ŷ��");
	//while (1)
	//{
	//	printf("1");
	//}


	char arr[100] = { 0 };
	int i = 0;
	int a = 0;
	while (a < 6)
	{
		scanf("%d", &arr[a]);
		a++;
	}
	int sz = sizeof(arr) / sizeof(arr[0]);
	while (i < sz)
	{
		printf("%c", arr[i]);
		i++;
	}



	return 0;
}