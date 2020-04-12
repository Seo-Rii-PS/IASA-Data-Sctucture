//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

#define initial_dq_size 10
typedef int data;

struct deque {
    data *arr;
    int front, rear, usedSize, currentSize;
};

deque *new_deque() {
    deque *nQueue = (deque *) malloc(sizeof(deque));
    nQueue->front = 0;
    nQueue->rear = 0;
    nQueue->usedSize = 0;
    nQueue->currentSize = initial_dq_size;
    nQueue->arr = (data *) malloc(nQueue->currentSize * sizeof(data));
    return nQueue;
}

void extend_deque(deque *dq) {
    int i;
    data *nArr = (data *) malloc(dq->currentSize * 2 * sizeof(data));
    for (i = 0; i < dq->currentSize; i++) {
        nArr[i] = dq->arr[(i + dq->front) % dq->currentSize];
    }
    free(dq->arr);
    dq->arr = nArr;
    dq->front = 0;
    dq->rear = dq->currentSize - 1;
    dq->currentSize *= 2;
}

void add_front(deque *dq, data val) {
    if (!dq->usedSize) {
        dq->front = 0;
        dq->rear = 0;
        dq->arr[0] = val;
        ++dq->usedSize;
        return;
    }
    if (dq->currentSize == dq->usedSize) {
        extend_deque(dq);
    }
    --dq->front;
    if (dq->front == -1) dq->front = dq->currentSize - 1;
    dq->arr[dq->front] = val;
    ++dq->usedSize;
}

void add_rear(deque *dq, data val) {
    if (!dq->usedSize) {
        dq->front = 0;
        dq->rear = 0;
        dq->arr[0] = val;
        ++dq->usedSize;
        return;
    }
    if (dq->currentSize == dq->usedSize) {
        extend_deque(dq);
    }
    ++dq->rear;
    if (dq->rear == dq->currentSize) dq->rear = 0;
    dq->arr[dq->rear] = val;
    ++dq->usedSize;
}

data get_front(deque *dq) {
    if (!dq->usedSize) return 0;
    return dq->arr[dq->front];
}

data get_rear(deque *dq) {
    if (!dq->usedSize) return 0;
    return dq->arr[dq->rear];
}

data delete_front(deque *dq) {
    data rValue = get_front(dq);
    ++dq->front;
    if (dq->front == dq->currentSize) dq->front = 0;
    --dq->usedSize;
    return rValue;
}

data delete_rear(deque *dq) {
    data rValue = get_rear(dq);
    --dq->rear;
    if (dq->rear == -1) dq->rear = dq->currentSize - 1;
    --dq->usedSize;
    return rValue;
}

int main() {
    deque *dq = new_deque();
    add_front(dq, 1);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    add_front(dq, 2);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    add_rear(dq, 3);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_front(dq);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_front(dq);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_rear(dq);
    add_front(dq, 1);
    printf("%d %d\n", get_front(dq), get_rear(dq));
}