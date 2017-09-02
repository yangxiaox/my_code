/*************************************************************************
	> File Name: haxibiao.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月13日 星期日 08时37分31秒
 ************************************************************************/


#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T))

#define ERROR 0
#define OK 1

typedef struct HshTable {
    char **data;
    int size;
} HashTable;

void init(HashTable *h, int n) {
    h->data = MC(char *, n);
    memset(h->data, 0, sizeof(char *) *n);
    h->size = n;
}

int hash_code(HashTable *h,const char *value) {
    unsigned int code = 0;
    for (int i = 0; value[i]; ++i) {
        code = (code << 3) ^ value[i] ^ (code >> 5);
    }
    return (int)(code % h->size);
}

int search(HashTable *h, char *value) {
    int index = hash_code(h, value);
    int times = 0;
    while (h->data[index] != NULL) {
        if (strcmp(h->data[index], value) == 0) {
            return OK;
        }
        times++;
        index += times * times;
        index %= h->size;
    }
    return ERROR;
}

int insert(HashTable *h, char *value) {
    int index = hash_code(h, value);
    int times = 0;
    while (h->data[index] != NULL) {
        if (strcmp(h->data[index], value) == 0) {
            return ERROR;
        }
        times++;
        index += times * times;
        index %= h->size;
    }
    h->data[index] = strdup(value);
    return OK;
}


void clear(HashTable *h) {
    for (int i = 0; i < h->size; ++i) {
        if (h->data[i] != NULL) {
            free(h->data[i]);
        }
    }
    free(h);
}

int zobrist_hash_num[26][30] = {0};

void init_zobrist_hash_num() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 30; ++j) {
            zobrist_hash_num[i][j] = rand();
        }
    }
}

int hash_code_zobrist(HashTable *h, const char *value) {
    printf("%s = ", value);
    unsigned int code = 0;
    for (int i = 0; value[i]; ++i) {
        printf("%x", zobrist_hash_num[value[i] - 'a'][i]);
        if (value[i + 1]) {
            printf(" ^ ");
        }
        code ^= zobrist_hash_num[value[i] - 'a'][i];
    }
    printf(" = %d\n",code);
    return (int)(code % 26);
}

int main () {
    srand(time(0));
    HashTable *h = MC(HshTable, 1);
    init_zobrist_hash_num();
    printf("%s = %d\n", "ab", hash_code_zobrist(h, "ab"));
    printf("%s = %d\n", "ba", hash_code_zobrist(h, "ba"));
    
    
    
    return 0;
}
