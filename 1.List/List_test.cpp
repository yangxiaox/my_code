/*************************************************************************
	> File Name: ggsxbylb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月02日 星期三 08时23分42秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "xtest.h"

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size;
    int length;
    int *data;
} Vector;

void init(Vector *vec, int n = 100) {
    vec->data = (int *)malloc(n * sizeof(int));
    vec->size = n;
    vec->length = 0;
}

int expand(Vector *vec) {
    int * temp = vec->data;
    vec->data = (int *)realloc(vec->data, 2 * vec->size * sizeof(int));
    if (vec->data == NULL) {
        vec->data = temp;
        return ERROR;
    }
    vec->size *= 2;
    return OK;
}

int insert(Vector *vec, int n, int index) {
    if (index < 0 || index > vec->length) {
        return ERROR;
    }
    if (vec->size == vec->length) {
        if (!expand(vec)) {
            return ERROR;
        }
    }
    for (int i = vec->length; i > index; --i) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[index] = n;
    vec->length++;
    return OK;
}

int delete_node(Vector *vec, int index) {
    if (index < 0 || index >= vec->length) {
        return ERROR;
    }
    for (int i = index; i < vec->length - 1; ++i) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length--;
    return OK;
}

void output(Vector *vec) {
    if (vec->length) {
        printf("%d", vec->data[0]);
    }
    for (int i = 1; i < vec->length; ++i) {
        printf(" %d", vec->data[i]);
    }
    printf("\n");
} 

void clear(Vector *vec) {
    if (vec->size == 0) {
        return ;
    }
    free(vec->data);
    free(vec);
}



int main() {
    return 0;
}


TEST(order, insert_head) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    init(vec);
    int index;
    for (int i = 0; i < 10; ++i) {
        insert(vec, i + 1, 0);
        index = vec->data[0];
        ASSERT_EQ(index, i + 1);
    }
    clear(vec);
}

TEST(order, insert_tail) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    init(vec);
    int index;
    for (int i = 0; i < 10; ++i) {
        insert(vec, i + 1, i);
        index = vec->data[i];
        ASSERT_EQ(index, i + 1);
    }
    clear(vec);
}

TEST(order, delete_head) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    init(vec);
    for (int i = 0; i < 10; ++i) {
        insert(vec, i + 1, i);
    }
    int i = 0;
    while (i != 10) {
        delete_node(vec, 0);
        if (i == 9) {
            ASSERT_EQ(0, vec->length);
            break;
        }
        ASSERT_NE(++i, vec->data[0]);
    }
    clear(vec);
}

TEST(order, delete_tail) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    init(vec);
    for (int i = 0; i < 10; ++i) {
        insert(vec, i + 1, i);
    }
    for (int i = 9; i >= 0; --i) {
        delete_node(vec, i);
        ASSERT_EQ(i, vec->length);
    }
    clear(vec);
}


