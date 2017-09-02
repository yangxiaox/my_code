/*************************************************************************
	> File Name: 7.20.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月20日 星期四 15时02分18秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[20];
    int age;
    char gender;
    int height;
};

int main() {
    printf("%lu\n", sizeof(struct person));
    return 0;
}
