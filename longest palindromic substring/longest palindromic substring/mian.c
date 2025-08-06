#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* longestPalindrome(char* s) 
{
	int count = 0, maxCount = 0;
	int left = 0, right = 1;
	int ewLeft = left, ewRight = right;
	int aLeft = 0, aRight = 0;
	for (;s[right];)
	{
		count = 0;
		if (s[left] == s[right + 1])
			count = 1;
		for (int eLeft = left, eRight = right + 1;eLeft >= 0 && s[eLeft] == s[eRight];)
		{
			count += 2;
			ewLeft = eLeft;
			ewRight = eRight;
			eLeft--;
			eRight++;

		}
		
		if (count > maxCount)
		{
			maxCount = count;
			aLeft = ewLeft;
			aRight = ewRight;
		}
		count = 0;
		for (int eLeft = left, eRight = right;eLeft >= 0 && s[eLeft] == s[eRight];)
		{
			count += 2;
			ewLeft = eLeft;
			ewRight = eRight;
			eLeft--;
			eRight++;

		}
		if (count > maxCount)
		{
			maxCount = count;
			aLeft = ewLeft;
			aRight = ewRight;
		}
		left++;
		right++;
	}
	s[aRight+1] = '\0';
	return s+aLeft;

}

int main()
{
	char s[10] = { "aadddd" };
	printf("%s", longestPalindrome(s));
	return 0;
}