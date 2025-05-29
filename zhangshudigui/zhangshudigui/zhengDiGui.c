#define _CRT_SECURE_NO_WARNINGS

int zhengDiGui(int x,int y)
{
	int i = 0;
	int sum = 0;
	i = y;
	//if (x > y)
	//{
	//	x
	//}
	if (y >= x)
	{
		y = x-1;
	}
	if (y == 1)
		return 1;
	if (x == 1||y==0)
		return 0;
	for (i = 1;i <= y;i++)
	{
		sum += zhengDiGui(x - i, i);
		if (x-i <= i)
			sum += 1;

	}
	return sum;
}