/*************************************************************************
	> File Name: ercharshux.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月17日 星期四 20时05分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Stnode {
    pNode node;
    int x;
} Stnode, *pStnode;

typedef struct Stack {
    pStnode *data;
    int size, top;
} Stack, *pStack;
    
typedef struct Stack1 {
    pNode *data;
    int size, top;
} Stack1, *pStack1;

void init_stack(Stack *s, int len) {
    s->data = (pStnode *)malloc(sizeof(pStnode) * len);
    s->size = len;
    s->top = -1;
}

void init_stack1(Stack1 *s, int len) {
    s->data = (pNode *)malloc(sizeof(pNode) * len);
    s->size = len;
    s->top = -1;
}

int push_stack(Stack *s, pStnode e) {
    s->data[++(s->top)] = e;
}

int push_stack1(Stack1 *s, pNode e) {
    s->data[++(s->top)] = e;
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

int empty_stack1(Stack1 *s) {
    return s->top == -1;
}

int pop_stack(Stack *s) {
    --(s->top);
}

int pop_stack1(Stack1 *s) {
    --(s->top);
}

pStnode top_stack(Stack *s) {
    return s->data[s->top];
}

pNode top_stack1(Stack1 *s) {
    return s->data[s->top];
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}

void clear_stack1(Stack1 *s) {
    free(s->data);
    free(s);
}

pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

pNode build(char *str) {
    pNode p = NULL, last_p = NULL;
    Stack1 *stack1 = (Stack1 *)malloc(sizeof(Stack1));
    init_stack1(stack1, strlen(str));
    int k = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' :
                k = 0;
                push_stack1(stack1, p);
                p = NULL;
                break;
            case ')' :
                last_p = top_stack1(stack1);
                pop_stack1(stack1);
                break;
            case ',' :
                k = 1;
                p = NULL;
                break;
            case ' ':
                break;
            default :
                p = init(str[0]);
                if (!empty_stack1(stack1) && k == 0) {
                    top_stack1(stack1)->lchild = p;
                } else if (!empty_stack1(stack1) && k == 1) {
                    top_stack1(stack1)->rchild = p;
                }
                break;
        }
        ++str;
    }
    if (p && !last_p) last_p = p;
    clear_stack1(stack1);
    return last_p;
}

void res_node(pNode p, char c) {
    pStack s;
    init_stack(s, 100);           //zhan
    Stnode *temp = (Stnode *)malloc(sizeof(Stnode));
    temp->node = (pNode)malloc(sizeof(Node));
    temp->node = p;
    temp->x = 1;
   // printf("%c\n", p->data);
    //return ;
    push_stack(s, temp);
    while (top_stack(s)->node->data != c && !(empty_stack(s))) {
        if (top_stack(s)->node->lchild == NULL && top_stack(s)->node->rchild == NULL) {
            pop_stack(s);
            (top_stack(s)->x)++;
        }
        if (top_stack(s)->x == 1) {
            if (top_stack(s)->node->lchild != NULL) {
                temp->node = temp->node->lchild;
                temp->x = 1;
                push_stack(s, temp);
            } else {
                top_stack(s)->x = 2;
            }
        }
        if (top_stack(s)->x == 2) {
            if (top_stack(s)->node->rchild != NULL) {
                temp->node = temp->node->rchild;
                temp->x = 1;
                push_stack(s, temp);
            } else {
                top_stack(s)->x = 3;
            }
        }
        if (top_stack(s)->x == 3) {
            pop_stack(s);
            (top_stack(s)->x)++;
        }
    }
    if (!(empty_stack(s))) {
        printf("%c ", top_stack(s)->node->data);
        pop_stack(s);
    }
    free(temp->node);
    free(temp);
    clear_stack(s);
}

int main() {
    char str[35], ch;
    int ind = 0;
    while (scanf("%c", &ch)) {
        if (ch == '\n') break;
        str[ind++] = ch;
    }
    str[ind] = 0;
    scanf("%c", &ch);
    pNode p = build(str);
    res_node(p, ch);
    clear(p);
    return 0;
}
