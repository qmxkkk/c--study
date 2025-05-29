#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    printf("Enter the number of arrays: ");
    scanf("%d", &x); // 获取用户输入的数组个数

    // 动态分配指针数组
    int** arrays = (int**)malloc(x * sizeof(int*));
    if (arrays == NULL) {
        printf("Memory allocation failed for pointer array!\n");
        return 1; // 如果内存分配失败，则退出程序
    }

    // 为每个数组分配内存
    int total_elements = 0;
    for (int i = 0; i < x; i++) {
        int size;
        printf("Enter the size of array %d: ", i + 1);
        scanf("%d", &size);
        arrays[i] = (int*)malloc(size * sizeof(int));
        if (arrays[i] == NULL) {
            printf("Memory allocation failed for array %d!\n", i + 1);
            // 释放之前已分配的内存
            for (int j = 0; j < i; j++) {
                free(arrays[j]);
            }
            free(arrays);
            return 1; // 如果内存分配失败，则退出程序
        }
        total_elements += size;
        printf("Enter elements for array %d:\n", i + 1);
        for (int j = 0; j < size; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    // 使用数组
    printf("You entered the following arrays:\n");
    for (int i = 0; i < x; i++) {
        printf("Array %d: ", i + 1);
        for (int j = 0; j < total_elements; j++) {
            if (j % total_elements == 0) {
                printf("\nArray %d: ", i + 1);
            }
            printf("%d ", arrays[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < x; i++) {
        free(arrays[i]);
    }
    free(arrays);

    return 0;
}
