/*************************************************************************
	> File Name: hafuman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月09日 星期三 08时17分14秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int fre;
}XX;

typedef struct Node {
    XX xx;
    struct Node *lchild, *rchild;
}Node; 

Node *init(XX xx) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->lchild = NULL;
    node->rchild = NULL;
    node->xx = xx;
    return node;
}

Node *build(Node *node1, Node *node2) {
    XX xx;
    xx.ch = '@';
    xx.fre = node1->xx.fre + node2->xx.fre;
    Node *node = init(xx);
    node->lchild = node1;
    node->rchild = node2;
    return node;
}

void sort(Node **node, int n) {
    for (int i = 0; i < n; ++i) {
        int k = i;
        int j;
        for(j = i + 1; j < n - 1; ++j) {
            if (node[k]->xx.fre < node[j]->xx.fre) {
                k = j;
            }
        }
        if (node[k]->xx.fre <= node[j]->xx.fre) {
            k = j;
        }
        /*if (k != i) {
            Node *l;
            l = node[k];
            node[k] = node[i];
            node[i] = l;
        }*/
    }
}

int seek(Node *node, char x, int y, char ch[]) {
    if (node->xx.ch == x) {
        ch[y] = '\0';
        return 1;
    } else if (node->lchild == NULL && node->rchild == NULL) {
        return 0;
    }
    if (node->lchild != NULL) {
        ch[y] = '0';
        if (seek(node->lchild, x, y + 1, ch)) {
            return 1;
        }
    }
    if (node->rchild != NULL) {
        ch[y] = '1';
        if (seek(node->rchild, x, y + 1, ch)) {
            return 1;
        }
    }
    return 0;
}

void clear(Node *node) {
    if (node) return ;
    if (node->rchild) clear(node->rchild);
    if (node->lchild) clear(node->lchild);
    free(node);
}

/*

void get_encode(Node *tree, char encode[][28], char *buffer) {

        if (tree == NULL) return ;
    if (tree->xx.ch != '@') {
        for (int i = 1; i <= buffer[0]; i++) {
                        encode[get_ind(tree->xx.ch)][i] = buffer[i];
                    
        }
                encode[get_ind(tree->xx.ch)][0] = buffer[0];
                return ;
            
    }
        buffer[++buffer[0]] = '0';
        get_encode(tree->lchild, encode, buffer);
        buffer[0]--;
        buffer[++buffer[0]] = '1';
        get_encode(tree->rchild, encode, buffer);
        buffer[0]--;
        return ;

}

*/


int main () {
    XX *pxx = (XX *)malloc(sizeof(XX));
    char q;
    for (int i = 0; i < 27; ++i) {
        scanf("%d", &pxx[i].fre);
        pxx[i].ch = i + 'a';
        if (i == 26)
            pxx[i].ch = ' ';
    }
    Node **node = (Node **)malloc(sizeof(Node *) * 27);
    for (int i = 0; i < 27; ++i) {
        node[i] = init(pxx[i]);
    }
    sort(node, 27);
    for (int l = 26; l > 0; --l) {
        node[l - 1] = build(node[l], node[l - 1]);
        sort(node, l);
    }
    char ch[28][28];
    for (int i = 0; i < 26; ++i) {
        seek(node[0], i + 'a', 0, ch[i]);
    }
    seek(node[0], ' ', 0, ch[26]);
    for (int i = 0; i < 26; ++i) {
        printf("%c : %s\n", i + 'a', ch[i]);
    }
    printf("  : %s\n", ch[26]);
  /*      char encode[28][28] = {0};
        Node *halfman_tree_root = node[0];
        get_encode(halfman_tree_root, encode, encode[27]);
    for (int i = 0; i < 26; i++) {
                printf("%c : %s\n", i + 'a', encode[i] + 1);
            
    }
    printf("  : %s\n", encode[26] + 1);*/
    for (int i = 0; i < 27; ++i)
    clear(node[i]);
    free(pxx);
    return 0;
}
