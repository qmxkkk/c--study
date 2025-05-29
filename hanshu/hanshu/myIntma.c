#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int mynum(int x)
{
	if (x > 0)
	{
		int cout = 1;
		int ret = x / 10;
		cout = cout + mynum(ret);
		return cout;
	}
	return 0;


}

int oboprint(int x)
{
	if (x > 9)
	{
		oboprint(x / 10);
	}

	printf("%d ", x / 10);
		return x;


}

int mydirnum(int x, int dir)
{
	if (x > 9)
	{
		int max = mynum(x);
		int ret = 0;
		int last = x % 10;
		int con = x / 10;
		if (dir < max)
		{
			ret = mydirnum(con, dir);
		}
		if (dir == max)
		{
			return last;
		}
		return ret;

	}
	else
	{
		return x;

	}

}

int isPalindrome(int x)
{
	int ret = 1;
	if (x < 0)
	{
		return 0;
	}
	else if (x >= 0 && x < 10)
	{

		return 1;
	}
	else
	{
		int max = mynum(x);
		for (int i = 1;i <= max / 2;i++)
		{
			if (mydirnum(x, i) != mydirnum(x, max + 1 - i))
			{
				ret = 0;
			}

		}
		return ret;
	}
}