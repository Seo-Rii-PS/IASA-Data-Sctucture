//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

#define qu_size 100
typedef int data;

struct queue {
    data arr[qu_size];
    int front, rear;
};

queue *newQueue() {
    queue *nQueue = (queue *) malloc(sizeof(queue));
    nQueue->front = 0;
    nQueue->rear = -1;
    return nQueue;
}

void enQueue(queue *qu, data val) {
    ++qu->rear;
    qu->arr[qu->rear] = val;
}

data frontQueue(queue qu) {
    return qu.arr[qu.front];
}

data deQueue(queue *qu) {
    data rValue = frontQueue(*qu);
    ++qu->front;
    return rValue;
}

int main() {
    queue *qu = newQueue();
    enQueue(qu, 1);
    printf("%d\n", frontQueue(*qu));
    enQueue(qu, 2);
    printf("%d\n", frontQueue(*qu));
    deQueue(qu);
    printf("%d\n", frontQueue(*qu));
}