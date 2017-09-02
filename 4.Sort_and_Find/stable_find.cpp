/*************************************************************************
	> File Name: wendingpaixu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月12日 星期六 09时12分04秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
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

void insert_sort(Data *arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (arr[j].val < arr[j - 1].val) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
    return ;
}

void bubble_sort(Data *arr, int n) {
    int times = 1;
    for (int i = n; i >= 1 && times; --i) {
        times = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j].val > arr[j + 1].val) {
                swap(arr[j], arr[j + 1]);
                times++;
            }
        }
    }
    return ;
}

void mergee_sort(Data *arr, int l, int r) {
    if (r < l) return ;
    if (r == l) return ;
    if (r - l == 1) {
        if (cmp_data(arr[r], arr[l])){
           swap(arr[r], arr[l]);
        }
        return ;
    }
    int mid = (l + r) / 2;
    mergee_sort(arr, l, mid);
    mergee_sort(arr, mid + 1, r);
    Data *temp = (Data *)malloc((r - l + 1) * sizeof(Data));
    int ind1 = l, ind2 = mid + 1, k = 0;
    while (ind1 <= mid || ind2 <= r) {
        if (ind2 > r) {
            temp[k++] = arr[ind1++];
        } else if (ind1 > mid) {
            temp[k++] = arr[ind2++];
        } else if (cmp_data(arr[ind2], arr[ind1])) {
            temp[k++] = arr[ind2++];
        } else {
            temp[k++] = arr[ind1++];
        }
    }
    for (int i = l; i <= r; ++i) {
        arr[i] = temp[i - l];
    }
    free(temp);
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
    int n;
    scanf("%d", &n);
    Data *arr = (Data *)malloc(sizeof(Data) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &(arr[i].val));
        arr[i].index = i;
    }
    //insert_sort(arr, n);
    //bubble_sort(arr, n);
    mergee_sort(arr, 0, n - 1);
    output(arr, n);
    free(arr);
    return 0;
}


/*
TEST() {

}*/
