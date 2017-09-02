/*************************************************************************
	> File Name: shift_and_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月17日 星期四 15时49分43秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct Bit_and {
    int *data;
    int size;
} Bit_and;

Bit_and *init(int n = 1) {
    Bit_and *b = (Bit_and *)malloc(sizeof(Bit_and));
    b->data = (int *)calloc(n, sizeof(int));
    b->size = n;
    return b;
}

Bit_and *expan(Bit_and *b, int n = 1) {
    b->size += n;
    Bit_and *a = (Bit_and *)malloc(sizeof(Bit_and));
    a->data = (int *)calloc(b->size, sizeof(int));
    for (int i = 0; i < b->size - 1; ++i) {
        a->data[i] = b->data[i];
    }
    a->size = b->size;
    free(b->data);
    free(b);
    return a;
}

void one_copy(Bit_and *b, int n) {
    if (b->size <= (n / 30)) {
        b = expan(b, (n / 30) - b->size + 1);
    }
    b->data[n / 30] |= (1 << (n % 30));
    return ;
}

void formula1(Bit_and *p, Bit_and *b) {
    if (p->size < b->size) {
        p = expan(p, b->size - p->size);
    }
    p->data[0] = (p->data[0] << 1 | 1) & b->data[0];
    for (int i = 1; i < b->size; ++i) {
        p->data[i] = (p->data[i] << 1 | !!(p->data[i - 1] & (1 << 30))) & b->data[i];
    }
    return ;
}

int formula2(Bit_and *p, int n) {
    return (p->data[n / 30] & (1 << (n % 30)));
}

void clear(Bit_and *b) {
    free(b->data);
    free(b);
}

void shift_and(char *s, char *t) {
    Bit_and **str_encode = (Bit_and **)malloc(sizeof(Bit_and *) * 256);
    for (int i = 0; i < 256; ++i) {
        str_encode[i] = init();
    }
    Bit_and *p = init();
    int n;
    int times = 0;
    for (n = 0; t[n]; n++) {
        one_copy(str_encode[t[n]], n);
    }
    for (int i = 0; s[i]; i++) {
        times++;
        formula1(p, str_encode[s[i]]);
        if (formula2(p, n - 1)) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", times);
    return ;
}



int main () {
    int next[100];
    char s[] = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdaasdqweqweasdadadqweqraasdadasdqwqeqewqeqwqeaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb";
    //char s[] = "aecaeaecaef";
    //char t[] = "aecaef";
    char t[] = "aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb";
    shift_and(s, t); 
    return 0;
}
