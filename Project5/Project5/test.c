#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  isValid(char* s) 
{
	int i = 0, re1 = 0, re2 = 0, re3 = 0;
	int ret1 = 0, ret2 = 0, ret3 = 0;
	for (i = 0;(s[i])&&(re1>=0)&&(re2>=0)&&(re3>=0);i++)
	{
		if (s[i] == '(')
		{
			ret1 = 1;
			re1++;
			switch (s[i + 1])
			{
			case ']':
				return 0;
			case '}':
				return 0;

			}
		}
		else if (s[i] == '[')
		{
			ret2 = 1;
			re2++;
			switch (s[i + 1])
			{
			case ')':
				return 0;
			case '}':
				return 0;

			}
		}
		else if (s[i] == '{')
		{
			ret3 = 1;
			re3++;
			switch (s[i + 1])
			{
			case ')':
				return 0;
			case ']':
				return 0;

			}
		}
		else
		{
			switch (s[i])
			{
			case ')':
				re1--;
				if (ret1 == 1 && re1 == 0)
				{
					ret1 = 0;
					if (re2 != 0 || re3 != 0)
						return 0;
				}
				break;
			case ']':
				re2--;
				if (ret2 == 1 && re2 == 0)
				{
					ret2 = 0;
					if (re1 != 0 || re3 != 0)
						return 0;
				}
				break;
			case '}':
				re3--;
				if (ret3 == 1 && re3 == 0)
				{
					ret3 = 0;
					if (re2 != 0 || re1 != 0)
						return 0;
				}
				break;

			}
		}

	}
	if (re1 == 0 && re2 == 0 && re3 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	char* s = { "[({(())}[()])]" };
	int a = 0;
	a = isValid(s);
	printf("%d\n", a);
	return 0;
}