/*************************************************************************
	> File Name: gc.duilie.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月04日 星期五 08时43分41秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "gc.duilie.h"
#include <time.h>
#include <stdlib.h>
#ifdef TESTCASE
    #include "testcase.h"
#endif

int main() {
    srand(time(0));
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    char ch;
    while (scanf("%c", &ch) != EOF) {
        int opr, value;
        opr = rand() % 3;
        value = rand() % 100;
        if (opr != 0) {
            if (!push_queue(q, value)) {
                printf("OVERFLOW !!! ");
            }
            printf("push %d\n", value);
        } else {
            pop_queue(q);
            printf("pop queue\n");
        }
        output_queue(q);
    }
    clear_queue(q);
    return 0;
}


