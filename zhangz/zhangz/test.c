#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include <windows.h>

//void memu()
//{
//	printf("张政最喜欢的永劫无间，启动！！！\n");
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
//		printf("请输入猜的数字哟：\n");
//		scanf("%d", &guess);
//		if (guess <= 0 || guess > 501)
//		{
//			printf("输入有误请输入1-500的数字哦~\n");
//			goto shuru;
//		}
//		else if (guess == 501)
//		{
//			system("shutdown -a");
//			printf("你开挂，呜呜~~~\n");
//		}
//		if (guess > ret)
//		{
//			printf("打咩~打咩！太大啦\n");
//		}
//		else if (guess < ret)
//		{
//			printf("周子，你他娘的猜小啦！\n");
//		}
//		else
//		{
//			t2 = (unsigned int)time(NULL);
//			t1 = t2 - t1;
//			printf("哦咩跌多！哦咩跌多~\n");
//			printf("您的用时是：%d秒哦，真快呢！\n", t1);
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
//	//生成随机数
//	srand((unsigned int)time(NULL));
//	do
//	{
//		memu();
//		switch (input)
//		{
//		case 0:
//			printf("退出游戏！\n");
//			break;
//		case 1:
//			printf("开始游戏！\n");
//			printf("好吧这就是个猜数字的游戏，范围是1-500哟，你一定很快就完成了吧");
//			Sleep(500);
//			printf(". ");
//			Sleep(500);
//			printf(". ");
//			Sleep(500);
//			printf(". \n");
//			Sleep(1000);
//			printf("诶！好像出了点问题，我来修修\n");
//			Sleep(1500);
//			printf("恭喜你！你的电脑将在一分钟后关机呀~~\n");
//			printf("好像猜对了才能取消呢，那就看看你有多快吧，加油哦！\n");
//			Sleep(2000);
//			
//			printf("现在开始计时哟~\n");
//
//			game();
//			break;
//		default:
//			printf("输入有误，请重新输入：->\n");
//			break;
//
//		}
//	} while (input);
//
//	return 0;
//}

void memu()
{
	printf("张欠操最喜欢的原神~~~~~，启动！！！\n");
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
		printf("请输入猜的数字哟：\n");
		scanf("%d", &guess);
		if (guess <= 0 || guess > 501)
		{
			printf("输入有误请输入1-500的数字哦~\n");
			goto shuru;
		}
		else if (guess == 501)
		{
			system("shutdown -a");
			printf("你开挂，呜呜~~~\n");
		}
		if (guess > ret)
		{
			printf("打咩~打咩！太大啦\n");
		}
		else if (guess < ret)
		{
			printf("周子，你他娘的猜小啦！\n");
		}
		else
		{
			t2 = (unsigned int)time(NULL);
			t1 = t2 - t1;
			printf("哦咩跌多！哦咩跌多~\n");
			printf("您的用时是：%d秒哦，真快呢！\n", t1);
			system("shutdown -a");
			break;
		}
	}



}

int main()
{
	int input = 1;
	//生成随机数
	srand((unsigned int)time(NULL));
	do
	{
		memu();
		switch (input)
		{
		case 0:
			printf("退出游戏！\n");
			break;
		case 1:
			printf("开始游戏！\n");
			printf("好吧这就是个猜数字的游戏，范围是1-500哟，你一定很快就完成了吧");
			Sleep(500);
			printf(". ");
			Sleep(500);
			printf(". ");
			Sleep(500);
			printf(". \n");
			Sleep(1000);
			printf("诶！好像出了点问题，我来修修\n");
			Sleep(1500);
			printf("恭喜你！你的电脑将在一分钟后关机呀~~\n");
			printf("好像猜对了才能取消呢，那就看看你有多快吧，加油哦！\n");
			Sleep(2000);

			printf("现在开始计时哟~\n");

			game();
			break;
		default:
			printf("输入有误，请重新输入：->\n");
			break;

		}
	} while (input);

	return 0;
}