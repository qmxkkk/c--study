#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 9

//int maxArea(int* height, int heightSize) {
//
//    int i = 0, j = heightSize - 1;
//    int len = 0;
//    int mid = 0;
//    int log = 0;
//    int ret = 0, mret = 0;
//    for (; i < j; ) {
//        len = j - i;
//        ret = len * (height[i] < height[j] ? height[i] : height[j]);
//        mret = ret > mret ? ret : mret;
//        log = 0;
//
//        if (height[i + 1] > height[i]) {
//            mid = height[i + 1] < height[j] ? height[i + 1] : height[j];
//            if (len * height[i] <= (len - 1) * mid) {
//                i++;
//                log++;
//
//            }
//
//        }
//
//
//        else if (height[j - 1] > height[j]) {
//            mid = height[j - 1] < height[i] ? height[j - 1] : height[i];
//            if (len * height[j] <= (len - 1) * mid) {
//
//                j--;
//                log++;
//
//            }
//        }
//
//        if (!log) {
//            height[i] < height[j] ? i++ : j--;
//            continue;
//        }
//
//
//    }
//    return mret;
//
//}


int maxArea(int* height, int heightSize) {

    int i = 0, j = heightSize - 1;
    int len = 0;
    int mid = 0;
    int log = 0;
    int ret = 0, mret = 0;
    for (; i < j; ) {
        len = j - i;
        ret = len * (height[i] < height[j] ? height[i] : height[j]);
        mret = ret > mret ? ret : mret;
        if (height[j] > height[i]) {
            i++;
        }
        else {
            j--;
        }
    }
    return mret;

}

int main() {
    int arr[NUM] = { 1,8,6,2,5,4,8,3,7 };
    
    int ret = maxArea(arr, NUM);
    printf("%d", ret);
	return 0;
}