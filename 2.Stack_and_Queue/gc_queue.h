/*************************************************************************
	> File Name: gc.duilie.h
	> Author: 
	> Mail: 
	> Created Time: 2017年08月04日 星期五 08时28分23秒
 ************************************************************************/

#ifndef _GC_QUEUE_H
#define _GC_QUEUE_H

#define ERROR 0
#define OK 1

typedef struct Queue {
    int *data;
    int head, tail;
    int length, count;
} Queue;

void init_queue(Queue *q, int n);
int push_queue(Queue *q, int value);
int pop_queue(Queue *q);
int front_queue(Queue *q);
int empty_queue(Queue *);
void clear_queue(Queue *q);
void output_queue(Queue *q);


#endif
