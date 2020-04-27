//
// Created by Seo_Hyun on 2020-04-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initial_qu_size 300
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
    int i, n, k, len;
    long long cnt = 0;
    char str[22];
    queue *qu[22];
    for (i = 0; i < 21; i++) qu[i] = newQueue();
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        while (qu[len]->usedSize && i - frontQueue(qu[len]) > k) deQueue(qu[len]);
        cnt += qu[len]->usedSize;
        enQueue(qu[len], i);
    }
    printf("%lld\n", cnt);
}