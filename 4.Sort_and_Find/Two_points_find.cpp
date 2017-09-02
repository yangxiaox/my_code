/*************************************************************************
	> File Name: erfenchazhao.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月12日 星期六 11时19分17秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


int binary_search(int *arr, int n, int value) {
    int head = 0, tail = n -1;
    int mid;
    while (head < tail) {
        mid = (head + tail + 1) / 2;
        if (arr[mid] == value) {
            head = mid;
        } else if (arr[mid] < value) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return arr[head] == value ? head : -1;
}


int main () {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
    int n, index, ret, ret1;
    while (scanf("%d", &n) != EOF) {
        index = binary_search(arr, 10, n);
        
    }
    
    return 0;
}
