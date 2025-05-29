#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//char* longestCommonPrefix(char** strs, int strsSize)
//{
//    int i = 0, j = 0, size = strsSize, y = 1;
//    char* re = strs[0];
//    for (j = 0;j < 200;j++)
//    {
//        for (i = 0;i < size;i++)
//        {
//            if (re[j] != strs[i][j])
//            {
//                re[j] = '\0';
//                return re;
//            }
//        }
//    }
//}


char* longestCommonPrefix(char** strs, int strsSize) 
{
    char* s0 = strs[0];
    for (int j = 0; s0[j]; j++) 
    {
        for (int i = 0; i < strsSize; i++) 
        {
            if (strs[i][j] != s0[j]) 
            {
                s0[j] = '\0';
                return s0;
            }
        }
    }
    return s0;
}




int main()
{
    char* mstrs[3] = {"flower","flow","flight"};
    printf("%s\n", longestCommonPrefix(mstrs, 3));
    return 0;
}

//char* longestCommonPrefix(char** strs, int strsSize) {
//    if (strsSize == 0) return "";
//
//    char* s0 = strs[0];
//    int length = 0;
//    while (*s0) {
//        char c = *s0++;
//        for (int i = 1; i < strsSize; i++) {
//            while (*strs[i] != c && *strs[i]) {
//                strs[i]++;
//            }
//            if (!*strs[i]) {
//                return strs[0];
//            }
//        }
//        strs[0][length++] = c;
//    }
//    strs[0][length] = '\0';
//    return strs[0];
//}
//
//int main() {
//    char mstrs[3][200] = { "flower", "flow", "flight" };
//    char* commonPrefix = longestCommonPrefix(mstrs, 3);
//    printf("%s\n", commonPrefix);
//    return 0;
//}


//// 函数声明
//char* longestCommonPrefix(char** strs, int strsSize);
//
//int main() {
//    // 创建一个字符指针数组来存储字符串数组的地址
//    char* mstrs[] = { "flower", "flow", "flight" };
//    int strsSize = sizeof(mstrs) / sizeof(mstrs[0]);
//    printf("%s\n", longestCommonPrefix(mstrs, strsSize));
//    return 0;
//}
//
//// 函数定义
//char* longestCommonPrefix(char** strs, int strsSize) {
//    if (strsSize == 0) return "";
//
//    char* s0 = strs[0];
//    for (int j = 0; s0[j]; j++) {
//        for (int i = 1; i < strsSize; i++) { // 从第二个字符串开始比较
//            if (strs[i][j] != s0[j] || strs[i][j] == '\0') {
//                s0[j] = '\0';
//                return s0;
//            }
//        }
//    }
//    return s0;
//}