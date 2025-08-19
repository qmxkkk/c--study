#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int old_romanToInt(char* s)
{
	int sum = 0;
	int i = 0;
	while (*s != '\0')
	{
		int jump = 0;
		if (*s == 'I')
		{
			jump = sameNum(s, i);
			if (*(s + 1) == 'V')
			{
				s += 1 + jump;
				sum += (5 - jump);
			}
			else if (*(s + 1) == 'X')
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
			if (*(s + 1) == 'L')
			{
				s += 1 + jump;
				sum += (50 - 10 * jump);
			}
			else if (*(s + 1) == 'C')
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
			if (*(s + 1) == 'D')
			{
				s += 1 + jump;
				sum += (500 - 100 * jump);
			}
			else if (*(s + 1) == 'M')
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

int isTwoSame(char str[], int x)
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

int sameNum(char* s, int x)
{
	int count = 0;
	for (int i = x;isTwoSame(s, i);i++)
	{
		++count;
	}
	return count + 1;
}

int strleng(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}
//
//#define I 1
//#define V 5
//#define X 10
//#define L 50
//#define C 100
//#define D 500
//#define M 1000
//#define ADDIN(arr,fu) (arr=fu)


//
//int romanToInt(char* s) {
//	int arr[100] = { 0 };
//	int ret = 0, sum = 0;
//	for (int i = 0;s[i];i++)
//	{
//		ADDIN(arr[i], s[i]);
//		sum += ret;
//	}
//	return sum;
//}

int romanToInt(char* s) {
	int arr[100] = { 0 };
	int ret = 0, sum = 0;
	for (int i = 0;s[i];i++)
	{
		ret = charTONum(s[i]);
		if (ret < charTONum(s[i + 1]))
			ret = -ret;
		sum += ret;
	}
	return sum;
}

int charTONum(char x) {
	switch (x)
	{
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
		break;
	case 'M':
		return 1000;
		break;
	default:
		return 0;
		break;
	}
}


char* intToRoman(int num) {
	char* ret = (char*)malloc(20);
	short arr[7] = { 1000,500,100,50,10,5,1 };
	int i = 0, count = 0, j = 0;
	for (;i < 7 || num > 0;i++) {

		for (;num > 0;) {
			 num -= arr[i];
			 if (num >= 0) {
				 count++;
			 }
			 else {
				 if (num + 1 >= 0 && i < 6 && i >= 4) {
					 for (;count > 0;count--) {
						 ret[j++] = 'X';
					 }
					 ret[j++] = 'I';
					 ret[j++] = (i == 4) ? 'X' : 'V';
					 num += 1;
					 count = 0;

				 }
				 else if (num + 10 >= 0 && i < 4 && i >= 2) {
					 for (;count > 0;count--) {
						 ret[j++] = 'C';
					 }
					 ret[j++] = 'X';
					 ret[j++] = (i == 2) ? 'C' : 'L';
					 num += 10;
					 count = 0;

				 }
				 else if (num + 100 >= 0 && i<2) {
					 for (;count>0;count--) {
						 ret[j++] = 'M';
					 }
					 ret[j++] = 'C';
					 ret[j++] = (i == 0) ? 'M' : 'D';
					 num += 100;
					 count = 0;
				 }
				 else {
					 num += arr[i];
				 }
				 break;
			 }

			
		}
		if (count <= 3 && count > 0) {
			for (;count > 0;count--, j++) {
				switch (arr[i]) {

				case 1000:
					ret[j] = 'M';
					break;
				case 500:
					ret[j] = 'D';
					break;
				case 100:
					ret[j] = 'C';
					break;
				case 50:
					ret[j] = 'L';
					break;
				case 10:
					ret[j] = 'X';
					break;
				case 5:
					ret[j] = 'V';
					break;
				case 1:
					ret[j] = 'I';
					break;
				default:
					break;
				}
			}
		}
	}
	ret[j] = '\0';
	return ret;
	
}


int main() {

	char arr[50] = { "DXIX" };
	char n_arr[50] = { 0 };
	int x = romanToInt(arr);
	char* p = intToRoman(x);
	printf("%d\n", x);
	printf("%s\n", p);
	free(p);
	p = NULL;
	return 0;
}