/*************************************************************************
	> File Name: duipaixu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月10日 星期四 09时43分50秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "xtest.h"

#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = __temp; \
}

void heap_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int current = i;
        int father = (current - 1) / 2;
        while (arr[current] > arr[father]) {
            swap(arr[current], arr[father]);
            current = father;
            father = (current - 1) / 2;
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[i], arr[0]);
        int l, r, max_index = 0;
        while (true) {
            l = 2 * max_index + 1;
            r = 2 * max_index + 2;
            if (l < i && arr[l] > arr[max_index]) {
                max_index = l;
            }
            if (r < i && arr[r] > arr[max_index]) {
                max_index = r;
            }
            if (max_index == r || max_index == l) {
                swap(arr[max_index], arr[(max_index - 1) / 2]);
            } else {
                break;
            }
        }
    }
    return ;
}



int main () {
   /* int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    heap_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);*/
    return 0;
}

TEST(heap, sortt) {
    int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = n - i;
    }
    heap_sort(arr, n);
    for (int i = 0 ; i < n; ++i) {
        //printf("%d ", arr[i]);
        ASSERT_EQ(i + 1, arr[i]);
    }
    free(arr);
}







