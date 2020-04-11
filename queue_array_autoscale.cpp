//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

#define initial_qu_size 10
typedef int data;

struct queue {
    data *arr;
    int front, rear, usedSize, currentSize;
};

queue *newQueue() {
    queue *nQueue = (queue *) malloc(sizeof(queue));
    nQueue->front = 0;
    nQueue->rear = -1;
    nQueue->usedSize = 0;
    nQueue->currentSize = initial_qu_size;
    nQueue->arr = (data *) malloc(nQueue->currentSize * sizeof(data));
    return nQueue;
}

void extendQueue(queue *qu) {
    int i;
    data *nArr = (data *) malloc(qu->currentSize * 2 * sizeof(data));
    for (i = 0; i < qu->currentSize; i++) {
        nArr[i] = qu->arr[(i + qu->front) % qu->currentSize];
    }
    free(qu->arr);
    qu->arr = nArr;
    qu->front = 0;
    qu->rear = qu->currentSize - 1;
    qu->currentSize *= 2;
}

void enQueue(queue *qu, data val) {
    if (qu->currentSize == qu->usedSize) {
        extendQueue(qu);
    }
    ++qu->rear;
    if (qu->rear == qu->currentSize) qu->rear = 0;
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
    if (qu->front == qu->currentSize) qu->front = 0;
    --qu->usedSize;
    return rValue;
}

int main() {
    queue *qu = newQueue();
    enQueue(qu, 1);
    for (int i = 1; i < 50; i++) {
        enQueue(qu, i);
        printf("%d\n", frontQueue(qu));
    }
    for (int i = 1; i < 50; i++) {
        deQueue(qu);
        printf("%d\n", frontQueue(qu));
    }
    deQueue(qu);
    printf("%d\n", frontQueue(qu));
}