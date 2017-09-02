/*************************************************************************
	> File Name: fen_jie_di_gui.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月18日 星期五 08时16分47秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define MC(T, n) ((T *)malloc(sizeof(T) * n))
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

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct PreorderArgs {
    Node *root;
    int status;
} PreorderArgs;

int __preorder(Node *root) {
    //if (root == NULL) return 1;
    printf("%d ", root->val);
    //root->lchild ** preorder(root->lchild);
    //root->rchild ** preorder(root->rchild);
    return 1;
}

int preorder(Node *root) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, PreorderArgs);
    PreorderArgs pa;
    pa.root = root;
    pa.status = 0;
    push_stack(s, pa);
    while (!empty_stack(s)) {
        PreorderArgs *tpa = &top_stack(s, PreorderArgs);
        switch (tpa->status) {
            case 0:
                if (tpa->root == NULL) {
                    tpa->status = 4;
                } else {
                    tpa->status = 1;
                }
            break;
            case 1:
                __preorder(tpa->root);
                tpa->status = 2;
                break;
            case 2:
                if (tpa->root->lchild) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 3;
                break;
            case 3:
                if (tpa->root->rchild) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 4;
                break;
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
                break;
        }
    }
    return 1;
}

int __postorder(Node *root) {
    //if (root == NULL) return 1;
    //root->lchild != NULL && __postorder(root->lchild);
    //root->rchild != NULL && __postorder(root->rchild);
    printf("%d ",root->val);
    return 1;
}

int postorder(Node *root) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, PreorderArgs);
    PreorderArgs pa;
    pa.root = root;
    pa.status = 0;
    push_stack(s, pa);
    while (!empty_stack(s)) {
        PreorderArgs *tpa = &top_stack(s, PreorderArgs);
        switch (tpa->status) {
            case 0:
                if (tpa->root == NULL) {
                    tpa->status = 4;
                } else {
                    tpa->status = 1;
                }
                break;
            case 1:
                if (tpa->root->lchild != NULL) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 2;
                break;
            case 2:
                if (tpa->root->rchild != NULL) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 3;
                break;
            case 3:
                __postorder(tpa->root);
                tpa->status = 4;
                break;
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
                break;
        }
    }
}

typedef struct QuickSortArgs {
    int *arr;
    int l, r;
    int x;
    int status;
} QuickSortArgs;

int __qsort(int *data, int l, int r) {
    // 0 : if (l >= r) return ;
    int x = l, y = r, z = data[l];
    while (x < y) {
        while (x < y && data[y] >= z) --y;
        if (x < y) data[x++] = data[y];
        while (x < y && data[x] <= z) ++x;
        if (x < y) data[y--] = data[x];
    }
    data[x] = z;
    return x;
    // 2 : qsort(data, l, x - 1);
    // 3 : qsort(data, x + 1, r);
    // 4 : return ;
}

void init_quick_sort_args(QuickSortArgs *qsa, int *arr, int l, int r, int status) {
    qsa->arr = arr;
    qsa->l = l;
    qsa->r = r;
    qsa->status = status;
    return ;
}

void q_sort(int *arr, int n) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, QuickSortArgs);
    QuickSortArgs qsa;
    init_quick_sort_args(&qsa, arr, 0, n - 1, 0);
    push_stack(s, qsa);
    while (!empty_stack(s)) {
        QuickSortArgs *tqsa = &top_stack(s, QuickSortArgs);
        switch(tqsa->status) {
            case 0:
                if (tqsa->l >= tqsa->r) {
                    tqsa->status = 4;
                } else {
                    tqsa->status = 1;
                }
                break;
            case 1:
                tqsa->x = __qsort(tqsa->arr, tqsa->l, tqsa->r);
                tqsa->status = 2;
                break;
            case 2:
                init_quick_sort_args(&qsa, tqsa->arr, tqsa->l, tqsa->x - 1, 0);
                push_stack(s, qsa);
                tqsa->status = 3;
                break;
            case 3:
                init_quick_sort_args(&qsa, tqsa->arr, tqsa->x + 1, tqsa->r, 0);
                push_stack(s, qsa);
                tqsa->status = 4;
                break;
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
                break;
        }
        
        
    }
}



int __cmp(int x, int y) {
    return x < y;
}

void __swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y =temp;
    return ;
}

typedef struct MergeesortArgs {
    int *arr;
    int l, r;
    int status;
    int mid;
} MergeesortArgs;

void init_mergee_sort_args(MergeesortArgs *msa, int *arr, int l, int r) {
    msa->arr = arr;
    msa->l = l,
    msa->r = r;
    msa->mid = (l + r) / 2;
    msa->status = 0;
}

void __mergee_sort(int *arr, int l, int r) {
    // 0 : if (r < l) return ;
    //  if (r == l) return ;
    //  if (r - l == 1) {
    //    if (__cmp(arr[r], arr[l])){
     //      __swap(&arr[r], &arr[l]);
    //    }
    //    return ;
    //}
    int mid = (l + r) / 2;
    // 1 : mergee_sort(arr, l, mid);
    // 2 : mergee_sort(arr, mid + 1, r);
    int *temp = (int *)malloc((r - l + 1) * sizeof(int));
    int ind1 = l, ind2 = mid + 1, k = 0;
    while (ind1 <= mid || ind2 <= r) {
        if (ind2 > r) {
            temp[k++] = arr[ind1++];
        } else if (ind1 > mid) {
            temp[k++] = arr[ind2++];
        } else if (__cmp(arr[ind2], arr[ind1])) {
            temp[k++] = arr[ind2++];
        } else {
            temp[k++] = arr[ind1++];
        }
    }
    for (int i = l; i <= r; ++i) {
        arr[i] = temp[i - l];
    }
    free(temp);
    // 4 : return ;
}

void mergee_sort(int *arr, int n) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, MergeesortArgs);
    MergeesortArgs msa;
    init_mergee_sort_args(&msa, arr, 0, n - 1);
    push_stack(s, msa);
    while (!empty_stack(s)) {
        MergeesortArgs *pmsa = &top_stack(s, MergeesortArgs);
        switch (pmsa->status) {
            case 0:
                if (pmsa->r <= pmsa->l) {
                    pmsa->status = 4;
                } else if (pmsa->r == pmsa->l - 1) {
                    if (__cmp(pmsa->arr[pmsa->r], pmsa->arr[pmsa->l])){
                        __swap(&(pmsa->arr[pmsa->r]), &(pmsa->arr[pmsa->l]));
                    }
                    pmsa->status = 4;
                } else {
                    pmsa->status = 1;
                }
                break;
            case 1:
                init_mergee_sort_args(&msa, pmsa->arr, pmsa->l, pmsa->mid);
                push_stack(s, msa);
                pmsa->status = 2;
                break;
            case 2:
                init_mergee_sort_args(&msa, pmsa->arr, pmsa->mid + 1, pmsa->r);
                push_stack(s, msa);
                pmsa->status = 3;
                break;
            case 3:
                __mergee_sort(pmsa->arr, pmsa->l, pmsa->r);
                pmsa->status = 4;
                break;
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
                break;
            
            
        }
        
        
        
    }
    
    
    
    
    
    
}






int main () {
    /*
    Stack *s = MC(Stack, 1);
    init_stack(s, 100, double);
    push_stack(s, 3.677);
    push_stack(s, 7.856);
    push_stack(s, 5.634);
    push_stack(s, 4.372);
    while (!empty_stack(s)) {
        printf("%lf\n", top_stack(s, double));
        pop_stack(s);
    }
    clear_stack(s);
    s = MC(Stack, 1);
    init_stack(s, 100, int); 
    push_stack(s, 4);
    push_stack(s, 5);
    push_stack(s, 7);
    push_stack(s, 8);
    push_stack(s, 1);
    while (!empty_stack(s)) {
        printf("%d\n", top_stack(s, int));
        pop_stack(s);
    }*/
    int data[10] = {2, 3, 8, 9, 10, 1, 7, 5, 6, 4};
    mergee_sort(data, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    
    
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

