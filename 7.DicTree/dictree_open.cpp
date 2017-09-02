/*************************************************************************
	> File Name: zidianshu_zhankai.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月21日 星期一 20时49分55秒
 ************************************************************************/


#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define MC(T, n) (T*)malloc(sizeof(T) * n)
#define CC(T, n) (T*)calloc(n, sizeof(T))

#define init_stack(s, n, T) (__init_stack(s, n, sizeof(T)))
#define push_stack(s, value) ({ \
    __typeof(value) __temp = (value); \
    __push_stack(s, (const char *)(&(__temp))); \
})
#define empty_stack(s) (__empty_stack(s))
#define pop_stack(s) (__pop_stack(s))
#define top_stack(s, T) (*((T *)__top_stack(s)))
#define clear_stack(s) (__clear_stack(s))


#define ERROR 0
#define OK 1

typedef struct Stack {
    char *data;
    int top, size;
    int value_size;
} Stack;

void __init_stack(Stack *s, int n, int value_size);
int __push_stack(Stack *s, const char *value);
int __empty_stack(Stack *s);
int __pop_stack(Stack *s);
char *__top_stack(Stack *s);
void __clear_stack(Stack *s);


typedef struct Node{
    int flag;
    struct Node *next[26];
    struct Node *fail;
    struct Node *father;
    int index;
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
            p->next[str[0] - 'a']->father = p;
            p->next[str[0] - 'a']->index = str[0] - 'a';
        } 
        p = p->next[str[0] - 'a'];
        str++;
    }
    p->flag = 1;
    return OK;
}

void __output(Node *tree, int i, char *str) {
    str[i] = '\0';
    if (tree->flag) {
        printf("%s\n", str);
    }
    for (int j = 0; j < 26; ++j) {
        if (tree->next[j] == NULL) continue;
        str[i] = j + 'a';
        __output(tree->next[j], i + 1, str);
    }
    return ;
   /* str[i] = '\0';
    if (tree->flag) {
        printf("%s\n", str);
    }
    return ;*/
}

typedef struct OpArgs {
    Node *tree;
    int i, j;
    int status;
} OpArgs;

void output(Node *tree, int i, char *str) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, OpArgs);
    OpArgs opa = {tree, i, 0, 0};
    push_stack(s, opa);
    OpArgs *popa;
    while (!(empty_stack(s))) {
        popa = &top_stack(s, OpArgs);
        switch (popa->status) {
            case 0 :
                str[popa->i] = '\0';
                if (popa->tree->flag) {
                    printf("%s\n", str);
                }
                popa->status = 1;
                break;
            case 1 : {
                while (popa->j < 26) {
                    if (popa->tree->next[(popa->j)++] != NULL) break;
                }
                if (popa->tree->next[popa->j - 1] != NULL) {
                    str[popa->i] = popa->j - 1 + 'a';
                    OpArgs opa1 = {popa->tree->next[popa->j - 1], popa->i + 1, 0, 0};
                    push_stack(s, opa1);
                }
                if (popa->j == 26) {
                    popa->status = 2;
                }
            }
                break;
            case 2 :
                pop_stack(s);
                break;
        }
        
        
    }
    clear_stack(s);
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

Node *__get_automaton_fail(Node *father, int index, Node *root) {
    if (father == root) return root;
    if (father->fail == NULL) {
        father->fail = __get_automaton_fail(father->father, father->index, root);
    }
    if (father->fail->next[index] != NULL) {
        return father->fail->next[index];
    }
    return __get_automaton_fail(father->fail, index, root);
}

void __build_automaton(Node *node, Node *root) {
    for (int i = 0; i < 26; ++i) {
        if (node->next[i] == NULL) continue;
        node->next[i]->fail = __get_automaton_fail(node, i, root);
        __build_automaton(node->next[i], root);
    }
    return ;
}

void build_automaton(Node *tree) {
    __build_automaton(tree, tree);
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
    //tree.fail = NULL;
    build_automaton(tree);
    
    
    
    clear(tree);
    return 0;
}




void __init_stack(Stack *s, int n, int value_size) {
    s->data = (char *)malloc(value_size * n);
    s->top = -1;
    s->size = n;
    s->value_size = value_size;
    return ;
}

int __push_stack(Stack *s, const char *value) {
    if (s->top == s->size -1) {
        return ERROR;
    }
    ++(s->top);
    memcpy(s->data + s->top * s->value_size, value, s->value_size);
    return OK;
}

int __empty_stack(Stack *s) {
    return s->top == -1;
}

int __pop_stack(Stack *s) {
    if (empty_stack(s)) {
        return ERROR;
    }
    --(s->top);
    return OK;
}

char *__top_stack(Stack *s) {
    if (empty_stack(s)) {
        return NULL;
    }
    return s->data + s->top * s->value_size;
}

void __clear_stack(Stack *s) {
    free(s->data);
    free(s);
    return ;
}

