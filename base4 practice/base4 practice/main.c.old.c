#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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
			strcat(y, "啊");
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

	for (int i = 0;i < 4;i++)
	{
		temp[0] = x[2 * i];
		temp[1] = x[2 * i + 1];
		if (strcmp(temp, "哦") == 0)
			r = 0x00;
		else if (strcmp(temp, "齁") == 0)
			r = 0x01;
		else if (strcmp(temp, "嗯") == 0)
			r = 0x02;
		else if (strcmp(temp, "啊") == 0)
			r = 0x03;


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
	char result[1000] = { '\0' };
	for (int i = 0;ustring[i] != '\0';i++)
	{
		strcat(result, charTOBase4(ustring[i]));
	}

	return result;
}

char* charTurner(const char* rstring)
{
	char result[1000] = { '\0' };
	char temp[2] = { '\0' };
	for (int i = 0;rstring[i] != '\0';i += 8)
	{
		temp[0] = base4ToChar((rstring + i));
		strcat(result, temp);

	}
	return result;
}


int main()
{
	int chioce = 0;
	char new[3] = "~";
	char user_input[1000] = {};
	do
	{
		printf("请输入数字以选择模式，1是加密，2是解密，0是退出\n\n");
		scanf("%d", &chioce);
		switch (chioce)
		{
		case 1:
			printf("请输入需要加密的文字：\n\n");
			scanf("%s", user_input);

			printf("先生你的密文是：\n\n%s\n\n", base4Turner(user_input));
			break;
		case 2:
			printf("请输入需要解密的文字：\n\n");
			scanf("%s", user_input);

			printf("先生你的原文是：\n\n%s\n\n", charTurner(user_input));
			break;
		default:
			break;
		}


	}

	while (chioce);

	return 0;
}