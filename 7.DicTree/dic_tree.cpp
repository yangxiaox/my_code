/*************************************************************************
	> File Name: zidianshu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月21日 星期一 09时44分53秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define MC(T, n) (T*)malloc(sizeof(T) * n)
#define CC(T, n) (T*)calloc(n, sizeof(T))

#define ERROR 0
#define OK 1

typedef struct Node{
    int flag;
    struct Node *next[26];
} Node;

Node *get_new_node() {
    /*
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    for (int i = 0; i < 26; ++i) {
        p->next[i] = NULL;
    }
    return p;*/
    Node *p =CC(Node, 1);
    return p;
}

int insert(Node *tree, char *str) {
    Node *p = tree;
    while (str[0]) {
        if (p->next[str[0] - 'a'] == NULL) {
            p->next[str[0] - 'a'] = get_new_node();
        } 
        p = p->next[str[0] - 'a'];
        str++;
    }
    p->flag = 1;
    return OK;
}

void output(Node *tree, int i, char *str) {
    /*str[i] = '\0';
    if (tree->flag) {
        printf("%s\n", str);
    }*/
    for (int j = 25; j >= 0; --j) {
        if (tree->next[j] == NULL) continue;
        str[i] = j + 'a';
        output(tree->next[j], i + 1, str);
    } 
    str[i] = '\0';
    if (tree->flag) {
        printf("%s\n", str);
    }
    return ;
}

void clear(Node *tree) {
    if (tree == NULL) return ;
    for (int i = 0; i < 26; ++i) {
        clear(tree->next[i]);
    }
    free(tree);
    return ;
}






int main() {
    Node *tree = get_new_node();
    int n;
    char str[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(tree, str);
    }
    output(tree, 0, str);
    
    clear(tree);
    return 0;
}

