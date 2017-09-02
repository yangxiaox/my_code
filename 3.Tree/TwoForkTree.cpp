/*************************************************************************
	> File Name: TwoForkTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月08日 星期二 09时25分55秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "xtest.h"
#include <time.h>

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
} Node, *Tree;

Node* init(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

Node *insert(Tree bt, int data) {
    if (bt == NULL) {
        bt = init(data);
    }
    if (bt->data > data) {
        bt->lchild = insert(bt->lchild, data);
    } else if (bt->data < data) {
        bt->rchild = insert(bt->rchild, data);
    }
    return bt;
}

Node *search(Tree bt, int data) {
    if (bt ==NULL || bt->data == data) {
        return bt;
    }
    if (bt->data >data) {
        return search(bt->lchild, data);
    } else {
        return search(bt->rchild, data);
    }
}

void preorder(Tree bt) {
    if (bt == NULL) return;
    printf("%d ", bt->data);
    preorder(bt->lchild);
    preorder(bt->rchild);
}

void inorder(Tree bt) {
    if (bt == NULL) return ;
    inorder(bt->lchild);
    printf("%d ", bt->data);
    inorder(bt->rchild);
}

void postorder(Tree bt) {
    if (bt == NULL) return ;
    postorder(bt->lchild);
    postorder(bt->rchild);
    printf("%d ", bt->data);
}

void clear(Tree bt) {
    if (bt == NULL) return ;
    clear(bt->lchild);
    clear(bt->rchild);
    free(bt);
} 


int main () {
    /*Tree tree = NULL;
    int opr, n;
    while (scanf("%d", &opr) != EOF) {
        switch (opr) {
            case 0 :
                scanf("%d", &n);
                tree = insert(tree, n);
                break;
            case 1:
                scanf("%d", &n);
                printf("searcj result : %p\n", search(tree, n));
                break;
            case 2 :
                preorder(tree);
                printf("\n");
                break;
            case 3 :
                inorder(tree);
                printf("\n");
                break;
            case 4 :
                postorder(tree);
                printf("\n");
                break;
        }
    }
    free(tree);*/
    return 0;
}

TEST(binarytree, insert_r) {
    Tree tree = NULL;
    Tree test = NULL;
    int j;
    for (int i = 0; i < 10; ++i) {
        test = tree = insert(tree, i);
        j = i;
        while (j--) {
            test = test->rchild;
        }
        ASSERT_EQ(i, test->data);
    }
    clear(tree);
    //clear(test);
}

TEST(binarytree, insert_l) {
    Tree tree = NULL;
    Tree test = NULL;
    int j;
    for (int i = 9; i >= 0; --i) {
        test = tree = insert(tree, i);
        j = 9 - i;
        while (j--) {
            test = test->lchild;
        }
        ASSERT_EQ(i, test->data);
    }
    clear(tree);
} 

TEST(binarytree, insert_x) {
    srand(time(0));
    Tree tree = NULL;
    int n = 10;
    while (n--) {
        
    }
}


TEST()
