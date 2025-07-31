#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int lengthOfLongestSubstring(char* s) 
{
    int len = 1, len_max = 1;
    int l = 0, r = 1;
    unsigned short bitmap[127] = { 0 }; //应该叫shortmap，因为题目说s可能有五万个字符，u_short可存入65535个位置
    if (!(s[0]))
        return 0;
    bitmap[s[l]] = l + 1; //地址的存入要加1,以免与数组第一个数的下标（或叫偏移量）0，与字符的不存在的0混淆
    while (s[r])
    {
        if (bitmap[s[r]] - 1 >= l) //判断右标要大于0即重复过，且要大于左标，小于左标在子串左边即外面没有意义
        {
            l = bitmap[s[r]];
            len = r - l + 1;
        }
        else
            len++;
        bitmap[s[r]] = r + 1;

        if (len > len_max)
            len_max = len;
        r++;
    }

    return len_max;
}


int main()
{
    short bitmap[257] = { 0 };
    int a = 2;
    char s[50001] = { "dskljfhskdjbfiwseuyr" };
    bitmap[s[a]] = a;
    printf("%d\n", (int)s[a]);
    printf("%d", lengthOfLongestSubstring(s));


	return 0;
}
