#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

char* convert(char* s, int numRows) 
{
	char* a;
	
	int nowRol = 1, i = 0, j = 0, jo = 1, k = 0;
	if (numRows == 1)
		return s;
	for (;s[k];k++)
	{
	}
	a = (char*)malloc(k + 1);
	for (;nowRol<=numRows;nowRol++)
	{
		for (;nowRol == 1 && i < k;j++)
		{
			a[j] = s[i];
			i += 2 * (numRows - 1);
		}
		for (i = nowRol - 1, jo = 1;1 < nowRol && nowRol < numRows && i < k;j++)
		{
			if (jo)
			{
				a[j] = s[i];
				i += 2 * (numRows - nowRol);
				jo--;
			}
			else
			{
				a[j] = s[i];
				i += 2 * nowRol - 2;
				jo++;
			}
		}
		for (i = nowRol - 1;nowRol == numRows && i < k;j++)
		{
			a[j] = s[i];
			i += 2 * (numRows - 1);
		}
	}
	a[k] = '\0';
	return a;
	free(a);

}

int main()
{	
	char s[] = {"PAYPALISHIRING"};
	int numsize = sizeof(s) / sizeof(int);
	printf("%s", convert(s, 3));
	return 0;
}