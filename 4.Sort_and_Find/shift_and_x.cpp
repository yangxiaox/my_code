/*************************************************************************
	> File Name: fuck.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月15日 星期二 12时55分18秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_M 500

void shift_and(char *s, char *t) {
    int l = strlen(t);
    int *p = (int *)calloc((MAX_M / 32 + 1), sizeof(int));
    int **str = (int **)malloc(sizeof(int *) * 256);
    for (int i = 0; i < 256; ++i) {
        str[i] = (int *)calloc((MAX_M / 32 + 1), sizeof(int));
    }
    int len = 0, times = 0;
    for (int i = 0; t[i]; ++i) {
        str[t[i]][i / 32] |= (1 << (i % 32));
        ++len;
        ++times;
    }
    int *head = (int *)malloc(sizeof(int) * (MAX_M / 32 + 1));
    long long x = pow(2, 31);
    for (int i = 0; s[i]; ++i) {
        for (int j = 0; j < (l / 32); ++j) {
            head[j] = p[j] & x;
            head[j] = !!(head[j]);
        }
        p[0] = (p[0] << 1 | 1) & str[s[i]][0];
        for (int j = 1; j < (l / 32 + 1); ++j) {
            p[j] = (p[j] << 1 | head[j - 1]) & str[s[i]][j];
        }
        //p = (p << 1 | 1) & str[s[i]];
        ++times;
        if (p[l / 32] & (1 << ((len - 1) % 32))) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", times);
    free(p);
    return ;
}

int main () {
    int next[100];
    char s[] = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdaasdqweqweasdadadqweqraasdadasdqwqeqewqeqwqeaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb";
    //char s[] = "aecaeaecaef";
    char t[] = "aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb";
    shift_and(s, t);
    
    return 0;
}
