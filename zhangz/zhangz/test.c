#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include <windows.h>

//void memu()
//{
//	printf("������ϲ���������޼䣬����������\n");
//	
//	Sleep(1000);
//	system("shutdown -s -t 75");
//
//}
//
//void game()
//{
//	unsigned int t1 = 0, t2 = 0;
//	t1 = (unsigned int)time(NULL);
//	int guess = 0;
//	int ret = rand() % 500 + 1;
//	//printf("%d\n", ret);
//	while (1)
//	{
//	shuru:
//		printf("������µ�����Ӵ��\n");
//		scanf("%d", &guess);
//		if (guess <= 0 || guess > 501)
//		{
//			printf("��������������1-500������Ŷ~\n");
//			goto shuru;
//		}
//		else if (guess == 501)
//		{
//			system("shutdown -a");
//			printf("�㿪�ң�����~~~\n");
//		}
//		if (guess > ret)
//		{
//			printf("����~���㣡̫����\n");
//		}
//		else if (guess < ret)
//		{
//			printf("���ӣ�������Ĳ�С����\n");
//		}
//		else
//		{
//			t2 = (unsigned int)time(NULL);
//			t1 = t2 - t1;
//			printf("Ŷ����࣡Ŷ�����~\n");
//			printf("������ʱ�ǣ�%d��Ŷ������أ�\n", t1);
//			system("shutdown -a");
//			break;
//		}
//	}
//
//
//
//}
//
//int main()
//{
//	int input = 1;
//	//���������
//	srand((unsigned int)time(NULL));
//	do
//	{
//		memu();
//		switch (input)
//		{
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		case 1:
//			printf("��ʼ��Ϸ��\n");
//			printf("�ð�����Ǹ������ֵ���Ϸ����Χ��1-500Ӵ����һ���ܿ������˰�");
//			Sleep(500);
//			printf(". ");
//			Sleep(500);
//			printf(". ");
//			Sleep(500);
//			printf(". \n");
//			Sleep(1000);
//			printf("����������˵����⣬��������\n");
//			Sleep(1500);
//			printf("��ϲ�㣡��ĵ��Խ���һ���Ӻ�ػ�ѽ~~\n");
//			printf("����¶��˲���ȡ���أ��ǾͿ������ж��ɣ�����Ŷ��\n");
//			Sleep(2000);
//			
//			printf("���ڿ�ʼ��ʱӴ~\n");
//
//			game();
//			break;
//		default:
//			printf("�����������������룺->\n");
//			break;
//
//		}
//	} while (input);
//
//	return 0;
//}

void memu()
{
	printf("��Ƿ����ϲ����ԭ��~~~~~������������\n");
	Sleep(1000);
	system("shutdown -s -t 75");

}

void game()
{
	unsigned int t1 = 0, t2 = 0;
	t1 = (unsigned int)time(NULL);
	int guess = 0;
	int ret = rand() % 500 + 1;
	//printf("%d\n", ret);
	while (1)
	{
	shuru:
		printf("������µ�����Ӵ��\n");
		scanf("%d", &guess);
		if (guess <= 0 || guess > 501)
		{
			printf("��������������1-500������Ŷ~\n");
			goto shuru;
		}
		else if (guess == 501)
		{
			system("shutdown -a");
			printf("�㿪�ң�����~~~\n");
		}
		if (guess > ret)
		{
			printf("����~���㣡̫����\n");
		}
		else if (guess < ret)
		{
			printf("���ӣ�������Ĳ�С����\n");
		}
		else
		{
			t2 = (unsigned int)time(NULL);
			t1 = t2 - t1;
			printf("Ŷ����࣡Ŷ�����~\n");
			printf("������ʱ�ǣ�%d��Ŷ������أ�\n", t1);
			system("shutdown -a");
			break;
		}
	}



}

int main()
{
	int input = 1;
	//���������
	srand((unsigned int)time(NULL));
	do
	{
		memu();
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		case 1:
			printf("��ʼ��Ϸ��\n");
			printf("�ð�����Ǹ������ֵ���Ϸ����Χ��1-500Ӵ����һ���ܿ������˰�");
			Sleep(500);
			printf(". ");
			Sleep(500);
			printf(". ");
			Sleep(500);
			printf(". \n");
			Sleep(1000);
			printf("����������˵����⣬��������\n");
			Sleep(1500);
			printf("��ϲ�㣡��ĵ��Խ���һ���Ӻ�ػ�ѽ~~\n");
			printf("����¶��˲���ȡ���أ��ǾͿ������ж��ɣ�����Ŷ��\n");
			Sleep(2000);

			printf("���ڿ�ʼ��ʱӴ~\n");

			game();
			break;
		default:
			printf("�����������������룺->\n");
			break;

		}
	} while (input);

	return 0;
}