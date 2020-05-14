//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define qu_size 4
typedef int data;

struct queue {
    data arr[qu_size];
    int front, rear, usedSize;
};

queue *init() {
    queue *nQueue = (queue *) malloc(sizeof(queue));
    nQueue->front = 0;
    nQueue->rear = -1;
    nQueue->usedSize = 0;
    return nQueue;
}

int isEmpty(queue *qu) {
    if (qu->usedSize == 0) return 1;
    return 0;
}

int isFull(queue *qu) {
    if (qu->usedSize == qu_size) return 1;
    return 0;
}

void enQueue(queue *qu, data val) {
    assert(!isFull(qu));
    ++qu->rear;
    if (qu->rear == qu_size) qu->rear = 0;
    qu->arr[qu->rear] = val;
    ++qu->usedSize;
}

data peek(queue *qu) {
    if (!qu->usedSize) return 0;
    return qu->arr[qu->front];
}

data deQueue(queue *qu) {
    assert(!isEmpty(qu));
    data rValue = peek(qu);
    ++qu->front;
    if (qu->front == qu_size) qu->front = 0;
    --qu->usedSize;
    return rValue;
}

int main() {
    queue *qu = init();
    printf("%d\n", deQueue(qu));
    enQueue(qu, 1);
    enQueue(qu, 2);
    enQueue(qu, 3);
    enQueue(qu, 4);
    printf("%d\n", peek(qu));
    printf("%d\n", deQueue(qu));
    printf("%d\n", deQueue(qu));
}