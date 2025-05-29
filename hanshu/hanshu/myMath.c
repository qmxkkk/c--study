#define _CRT_SECURE_NO_WARNINGS

int isLilynum(int x)
{
	int i = 0;
	int sum = 0;
	for (i = 10;x / i > 0;i *= 10)
	{
		sum += (x / i) * (x % i);
	}
	if (sum == x)
		return 1;
	else
		return 0;
}