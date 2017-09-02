/*************************************************************************
	> File Name: shunxubiao.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月26日 星期三 09时58分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {        //顺序表结构体
        int size, length;
        int *data;
} Vector;

void init(Vector *vector, int size) {           //创建顺序表
        vector->size = size;
        vector->length = 0;
        vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {                    //扩展顺序表
        int *old_data = vector->data;
        vector->size = vector->size * 2;
        vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; ++i) {
                vector->data[i] = old_data[i];
    }
        free(old_data);
}

int insert(Vector *vector, int loc, int value) {       //插入顺序表
    if (loc < 0 || loc > vector->length) {
                return ERROR;
    }
    if (vector->length >= vector->size) {
           expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
                vector->data[i] = vector->data[i - 1];
    }
        vector->data[loc] = value;
        vector->length++;
        return OK;
}

int search(Vector *vector, int value) {              //搜索顺序表单元
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
                        return i;
        }
    }
        return -1;
}

int delete_node(Vector *vector, int index) {              //删除顺序表一个单元
    if (index < 0 || index >= vector->length) {
                return ERROR;
    }
    for (int i = index + 1; i < vector->length; ++i) {
                vector->data[i - 1] = vector->data[i];
    }
        vector->length = vector->length - 1;
        return OK;
}

void print(Vector *vector) {                             //输出顺序表所有单元
    for (int i = 0; i < vector->length; ++i) {
        if (i > 0) {
                        printf(" ");
        }
                printf("%d", vector->data[i]);
    }
        printf("\n");
}

void clear(Vector *vector) {                         //释放整个顺序表
        free(vector->data);
        free(vector);
}

int main() {
        Vector *a = (Vector *)malloc(sizeof(Vector));
        init(a, 100);
        printf("%d\n", insert(a, 0, 1));
        printf("%d\n", insert(a, 0, 2));
        print(a);
        printf("%d\n", delete_node(a, 1));
        print(a);
        printf("%d\n", search(a, 0));
        printf("%d\n", search(a, 1));
        clear(a);
        return 0;
}
