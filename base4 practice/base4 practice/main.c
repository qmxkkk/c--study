#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char b_result[2000] = { '\0' };

char c_result[2000] = { '\0' };


char* charTOBase4(char x)
{
	unsigned char temp;
	char y[9] = { '\0' };
	for (int i = 0;i < 4;i++)
	{
		switch (i)
		{
		case 0:
			temp = x & 0xc0;
			temp >>= 6;
			break;
		case 1:
			temp = x & 0x30;
			temp >>= 4;
			break;
		case 2:
			temp = x & 0x0c;
			temp >>= 2;
			break;
		case 3:
			temp = x & 0x03;
			break;
		default:
			break;
		}
		switch (temp)
		{
		case 0x00:
			strcat(y, "哦");
			break;
		case 0x01:
			strcat(y, "齁");
			break;
		case 0x02:
			strcat(y, "嗯");
			break;
		case 0x03:
			strcat(y, "~");
			break;
		default:
			break;
		}

	}
	

	return y;
}


char base4ToChar(const char* x)
{
	unsigned char r = 0;
	char y = '\0';
	char temp[3] = { '\0' };
	int count = 0;

	for (int i = 0;i < 4;i++)
	{
		temp[0] = x[2 * i + count];
		temp[1] = x[2 * i + 1 + count];
		if (strcmp(temp, "哦") == 0)
			r = 0x00;
		else if (strcmp(temp, "齁") == 0)
			r = 0x01;
		else if (strcmp(temp, "嗯") == 0)
			r = 0x02;
		else if (temp[0] == 0x7E)
		{
			r = 0x03;
			count--;
		}
			
		switch (i)
		{
		case 0:
			r <<= 6;
			break;
		case 0x01:
			r <<= 4;
			break;
		case 0x02:
			r <<= 2;
			break;
		case 0x03:
			break;
		default:
			break;
		}
		y |= r;

	}
	


	return y;
}


char* base4Turner(const char* ustring)
{
	
	for (int i = 0;ustring[i] != '\0';i++)
	{
		strcat(b_result, charTOBase4(ustring[i]));
	}

	return b_result;
}

int counter(char* string)
{
	int count = 0;
	for (int i = 0;string != '\0' && i < 4;i++)
	{
		if (string[2 * i - count] == 0x7E )
		{
			count++;
		}
	}
	return count;
}

char* charTurner(const char* rstring)
{
	char temp[2] = { '\0' };
	for (int i = 0;rstring[i] != '\0';i += (8 - counter(rstring + i)))
	{
		temp[0] = base4ToChar((rstring + i));
		strcat(c_result, temp);

	}
	return c_result;
}


int main()
{
	int chioce = 0;
	char new[100] = "我是小羊，快来草饲我";
	char user_input[1000] = {'\0'};
	char test[1473] = "nihcsjodfisdjf";

	printf("%s\n", test);
	do
	{
		printf("请输入数字以选择模式，1是加密，2是解密，0是退出\n\n");
		scanf("%d", &chioce);
		switch (chioce)
		{
		case 1:
			printf("\n请输入需要加密的文字：\n\n");
			scanf("%s", user_input);

			printf("\n先生你的密文是：\n\n%s\n\n", base4Turner(user_input));
			break;
		case 2:
			printf("\n请输入需要解密的文字：\n\n");
			scanf("%s", user_input);

			printf("\n先生你的原文是：\n\n%s\n\n", charTurner(user_input));
			break;
		default:
			break;
		}


	}

	while (chioce);

	return 0;
}