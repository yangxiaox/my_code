/*************************************************************************
	> File Name: shift_and.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月15日 星期二 14时36分45秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 500

typedef struct {
    int *head;
    int **str;
    long long x;
    int length;
} Strzz;

void init(Strzz *st, int n) {
    st->str = (int **)malloc(sizeof(int *) * 256);
    st->x = pow(2, 31);
    st->length = (n / 32) + 1;
    st->head = (int *)malloc(sizeof(int) * (st->length - 1));
    for (int i = 0; i < 256; ++i) {
        st->str[i] = (int *)calloc(st->length, sizeof(int));
    }
    return ;
}

void mest_head(Strzz *st, int *p, int l) {
    for (int i = 0; i < l; ++i) {
        st->head[i] = p[i] & st->x;
        st->head[i] = !!(st->head[i]);
    }
    return ;
}

void cur_len(Strzz *st, int *p, char c) {
    p[0] = (p[0] << 1 | 1) & st->str[c][0];
    for (int i = 1; i < (st->length); ++i) {
        p[i] = (p[i] << 1 | st->head[i - 1]) & st->str[c][i];
    }
    return ;
}

void shift_and(char *s, char *t) {
    int l = strlen(t);
    Strzz *st;
    init(st, l);
    int *p = (int *)calloc(st->length, sizeof(int));
    int len = 0, times = 0;
    for (int i = 0; t[i]; ++i) {
        st->str[t[i]][i / 32] |= (1 << (i % 32));
        ++len;
        ++times;
    }
    for (int i = 0; s[i]; ++i) {
        mest_head(st, p, l);
        cur_len(st, p, s[i]);
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
