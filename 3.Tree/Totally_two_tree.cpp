/*************************************************************************
	> File Name: wqerchashu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月08日 星期二 09时07分12秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void preorder(char *p, int x, int n) {
    if (x > n) {
        return ;
    }
    printf("%c ", p[x]);
    preorder(p, 2 * x, n);
    preorder(p, 2 * x + 1, n);
}

void inorder(char *p, int x, int n) {
    if (x > n) {
        return ;
    }
    inorder(p, 2 * x, n);
    printf("%c ", p[x]);
    inorder(p, 2 * x + 1, n);
}

void postorder(char *p, int x, int n) {
    if (x > n) {
        return ;
    }
    postorder(p, 2 * x, n);
    postorder(p, 2 * x + 1, n);
    printf("%c ", p[x]);
}

int main () {
    int n;
    while (scanf("%d", &n) != EOF) {
        char *p = (char *)malloc(sizeof(char) * (n + 1));
        for (int i = 1; i<= n; ++i) {
            p[i] = i + 64;
        }
        preorder(p, 1, n);
        printf("\n");
        inorder(p, 1, n);
        printf("\n");
        postorder(p, 1, n);
        printf("\n");
        free(p);
    }
    return 0;
}
