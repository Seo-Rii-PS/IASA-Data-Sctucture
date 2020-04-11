//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

#define qu_size 100
typedef int data;

struct queue {
    data arr[qu_size];
    int front, rear, usedSize;
};

queue *newQueue() {
    queue *nQueue = (queue *) malloc(sizeof(queue));
    nQueue->front = 0;
    nQueue->rear = -1;
    nQueue->usedSize = 0;
    return nQueue;
}

void enQueue(queue *qu, data val) {
    ++qu->rear;
    if (qu->rear == qu_size) qu->rear = 0;
    qu->arr[qu->rear] = val;
    ++qu->usedSize;
}

data frontQueue(queue *qu) {
    if (!qu->usedSize) return 0;
    return qu->arr[qu->front];
}

data deQueue(queue *qu) {
    data rValue = frontQueue(qu);
    ++qu->front;
    if (qu->front == qu_size) qu->front = 0;
    --qu->usedSize;
    return rValue;
}

int main() {
    queue *qu = newQueue();
    enQueue(qu, 1);
    for(int i=1;i<50;i++) {
        for(int j=1;j<50;j++) enQueue(qu, i);
        for(int j=1;j<50;j++) deQueue(qu);
        printf("%d\n", frontQueue(qu));
    }
    deQueue(qu);
    printf("%d\n", frontQueue(qu));
}