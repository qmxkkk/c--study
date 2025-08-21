#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};


//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//
//    if (l1->val == 0 && l1->next==NULL && l2->val == 0 && l2->next==NULL)
//        return l1;
//    long  long n1 = 0, n2 = 0;
//    long  long k1 = 1;
//    for (;;l1 = l1->next) {
//        n1 += k1 * l1->val;
//        k1 *= 10;
//        if (l1->next == NULL)
//            break;
//    }
//    k1 = 1;
//    for (;;l2 = l2->next) {
//        n2 += k1 * l2->val;
//        k1 *= 10;
//        if (l2->next == NULL)
//            break;
//    }
//    struct ListNode ret = { 0,NULL };
//    struct ListNode* p = &ret;
//    struct ListNode* pnew = NULL;
//    struct ListNode* pold = &ret;
//    long long sum = n1 + n2;
//    //int n = 1;
//    //for (; sum / n;n *= 10)
//    //{
//    //}
//    //n /= 10;
//    for (int k = 1;sum;) {
//        k = sum % 10;
//        sum /= 10;
//        //n /= 10;
//        pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
//        pnew->next = NULL;
//        pnew->val = k;
//        pold->next = pnew;
//        pold = pnew;
//    }
//    return p->next;
//}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    if (l1->val == 0 && l1->next == NULL && l2->val == 0 && l2->next == NULL)
        return l1;
    int n1 = 0, c = 0;
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = 0;
    ret->next = NULL;
    struct ListNode* head = ret, * tail = ret;


    for (;;) {
        n1 = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
        c = n1 / 10;
        n1 %= 10;

        tail->val = n1;

        if (l1)
            l1 = l1->next;

        if (l2)
            l2 = l2->next;

        if (!l1 && !l2) {
            if (c != 0) {
                tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tail->next->val = c;
                tail->next->next = NULL;
            }
            else {
                tail->next = NULL;
            }

            break;
        }
        tail->next= (struct ListNode*)malloc(sizeof(struct ListNode));
        tail = tail->next;

    }
    
    return head;
}

struct ListNode* putIn(int* arr, int numsSize,struct ListNode* m1) {

    struct ListNode* head = m1, * tail = m1;
    //for (;;) {
    //    p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //    p2->val = arr[i];
    //    p2->next = NULL;
    //    p3->next = p2;
    //    p3 = p2;
    //}
    head->next = NULL;
    for (int i = 0;i<numsSize-1;i++) {
        tail->val = arr[i];
        tail->next= (struct ListNode*)malloc(sizeof(struct ListNode));
        tail = tail->next;
    }
    tail->val = arr[numsSize - 1];
    tail->next = NULL;
    return head;
}

int printReLN(struct ListNode* pLn) {
    int i = 0, ret = 0;
    struct ListNode* head = pLn, * tail = pLn;
    for (;tail;i++) {
        tail = tail->next;
    }
    tail = head;
    char* arr = (char*)malloc((i+1) * (sizeof(char)));
    arr[i] = '\0';
    ret = i;
    i--;
    for (;0 <= i;i--) {
        arr[i] = (char)(tail->val + (int)'0');
        tail = tail->next;
    }
    printf("%s\n", arr);
    return ret;
}

int main() {
    struct ListNode n1 = { 0,NULL };


    struct ListNode n2 = { 0,NULL };

    int arr[3] = { 2,4,7 };
    int arr2[3] = { 5,6,4 };
    struct ListNode* nn = putIn(arr, 3, &n1);
    struct ListNode* nn2 = putIn(arr2, 3, &n2);
    

    struct ListNode* test = addTwoNumbers(nn, nn2);
    printReLN(test);
    return 0;
}