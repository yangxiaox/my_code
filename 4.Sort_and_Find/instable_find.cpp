/*************************************************************************
	> File Name: feiwendingpaixu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月12日 星期六 10时18分38秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h> 
#include <time.h>
#include "xtest.h"

#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = __temp; \
}

typedef struct Data {
    int val, index;
} Data;

int cmp_data(Data data1, Data data2) {
    return data1.val < data2.val;
} 

void quick_sort(Data *arr, int l, int r) {
    while (r - l > 0) {
        int x = l, y = r;
        int rand_index = l + rand() % (r - l + 1);
        swap(arr[rand_index], arr[l]);
        Data z = arr[l];
        while (x < y) {
            while (x < y && cmp_data(z, arr[y])) --y;
            if (x < y ) arr[x++] = arr[y];
            while (x < y && cmp_data(arr[x], z)) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort(arr, x + 1, r);
        r = x - 1;
    }
    return ;
}

void select_sort(Data *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (cmp_data(arr[j], arr[k])) {
                k = j;
            }
        }
        if (i != k) {
            swap(arr[i], arr[k]);
        }
    }
    return ;
}



void output(Data *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d(%d) ", arr[i].val, arr[i].index);
    }
    printf("\n");
    return ;
}

int main () {
    /*
    srand(time(0));
    int n;
    scanf("%d", &n);
    Data *arr = (Data *)malloc(sizeof(Data) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &(arr[i].val));
        arr[i].index = i;
    }
   // select_sort(arr, n);
    quick_sort(arr, 0, n - 1);
    output(arr, n);
    free(arr);*/
    return 0;
}


TEST(quick_sort, test) {
    srand(time(0));
    int n = 11;
    Data *arr = (Data *)malloc(sizeof(Data) * n);
    for (int i = 0; i < n; ++i) {
        arr[i].val = rand() % 100;
        arr[i].index = i;
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 1; i < n; ++i) {
        ASSERT_LE(arr[i - 1].val, arr[i].val);
    }
    free(arr);
}

