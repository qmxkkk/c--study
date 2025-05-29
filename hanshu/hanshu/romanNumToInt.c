#define _CRT_SECURE_NO_WARNINGS

int turnStr(char s[],int x)//将输入的字符串全部转换成大写或者全部转换成小写，1大，0小
{

	while (*s != '\0')
	{
		if (x == 1 && (*s>'a' && *s<'z'))
		{
			*s -= 32;
		}
		if (x == 0 && (*s>'A' && *s<'Z'))
		{
			*s += 32;
		}
		++s;
	}
	return s;
}

int isTwoSame(char str[], int x)//判断字符串中的某个字符是否与下一个相同
{
	if (str[x] == str[x + 1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int sameNum(char* s,int x)
{
	int count = 0;
	for (int i = x;isTwoSame(s, i);i++)
	{
		++count;
	}
	return count+1;
}

int strleng(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

int romanToInt(char* s)
{
	int sum = 0;
	int i = 0;
	while (*s != '\0')
	{
		int jump = 0;
		if (*s == 'I')
		{
			jump = sameNum(s, i);
			if (*(s+ jump) == 'V')
			{
				s += 1 + jump;
				sum += (5 - jump);
			}
			else if (*(s + jump) == 'X')
			{
				s += 1 + jump;
				sum += (10 - jump);
			}
			else
			{
				s += jump;
				sum += jump;
			}

		}
		else if (*s == 'V')
		{
			jump = sameNum(s, i);
			sum += (5 * jump);
			s += jump;
		}

		else if (*s == 'X')
		{
			jump = sameNum(s, i);
			if (*(s + jump) == 'L')
			{
				s += 1 + jump;
				sum += (50 - 10 * jump);
			}
			else if (*(s + jump) == 'C')
			{
				s += 1 + jump;
				sum += (100 - 10 * jump);
			}
			else
			{
				s += jump;
				sum += 10 * jump;
			}

		}
		else if (*s == 'L')
		{
			jump = sameNum(s, i);
			sum += (50 * jump);
			s += jump;
		}

		else if (*s == 'C')
		{
			jump = sameNum(s, i);
			if (*(s + jump) == 'D')
			{
				s += 1 + jump;
				sum += (500 - 100 * jump);
			}
			else if (*(s + jump) == 'M')
			{
				s += 1 + jump;
				sum += (1000 - 100 * jump);
			}
			else
			{
				s += jump;
				sum += 100 * jump;
			}

		}

		else if (*s == 'D')
		{
			jump = sameNum(s, i);
			sum += (500 * jump);
			s += jump;
		}

		else if (*s == 'M')
		{
			jump = sameNum(s, i);
			sum += (1000 * jump);
			s += jump;
		}
	}
	return sum;
}

int anyRomanToInt(char s[])
{
	turnStr(s, 1);
	int ret= romanToInt(s);
	return ret;
}