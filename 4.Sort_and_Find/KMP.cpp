/*************************************************************************
	> File Name: KMP.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月15日 星期二 09时39分08秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

void get_next(char *t, int *next) {
    next[0] = -1;
    int j = 1, match = -1;
    while (t[j]) {
        while (match != -1 && t[match + 1] != t[j]) {
            match = next[match];
        }
        if (t[match + 1] == t[j]) {
            next[j] = match + 1;
            match++;
        } else {
            next[j] = match;;
        }
        ++j;
    }
    return ;
}

void kmp_match(char *s, char *t, int *next) {
    int i = 0, j = -1, times = 0;
    while (s[i]) {
        while (j != -1 && t[j + 1] != s[i]) {
            ++times;
            j = next[j];
        }
        if (t[j + 1] == s[i]) {
            ++times;
            ++j;
        }
        if (t[j + 1] == '\0') {
            printf("%d : KMP YES\n", times);
            return ;
        }
        ++times;
        ++i;
    }
    printf("%d : KMP NO\n", times);
    return ;
}

void shift_and(char *s, char *t) {
    int str[256] = {0};
    int p = 0, len = 0, times = 0;
    for (int i = 0; t[i]; ++i) {
        str[t[i]] |= (1 << i);
        ++len;
        ++times;
    }
    for (int i = 0; s[i]; ++i) {
        p = (p << 1 | 1) & str[s[i]];
        ++times;
        if (p & (1 << (len - 1))) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", times);
    return ;
}

void sunday(char *s, char *t) {
    int str_index[256] = {0};
    int len = strlen(t);
    int s_len = strlen(s);
    for (int i = 0; i < 256; ++i) {
        str_index[i] = len + 1;
    }
    for (int i = 0; t[i]; ++i) {
        str_index[t[i]] = len - i;
    }
    int i = 0, j = 0;
    while (i + len <= s_len) {
        if (s[i + j] != t[j]) {
            i += str_index[s[i + len]];
            j = 0;
        } else {
            ++j;
        }
        if (t[j] == '\0') {
            printf("Sunday OK\n");
            return ;
        }
    }
    printf("sunday not OK\n");
    return ;
}

int main () {
    int next[100];
    char s[] = "aecaeaecaef";
    char t[] = "aecaef";
    get_next(t, next);
    printf("{ ");
    for (int i = 0; t[i]; ++i) {
        printf("%d ", next[i]);
    }
    printf("}\n");
    kmp_match(s, t, next);
    shift_and(s, t);
    
    return 0;
}
