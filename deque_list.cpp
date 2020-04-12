//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

typedef int data;

struct node {
    data val;
    node *nextNode, *prevNode;
};

node *newNode(data val, node *nextNode, node *prevNode) {
    node *tNode = (node *) malloc(sizeof(node));
    tNode->val = val;
    tNode->nextNode = nextNode;
    tNode->prevNode = prevNode;
    return tNode;
}

struct deque {
    node *front, *rear;
};

deque new_deque() {
    deque tQ = {NULL, NULL};
    return tQ;
}

void add_front(deque *dq, data val) {
    node *tNode = newNode(val, NULL, NULL);
    if (dq->front) dq->front->prevNode = tNode;
    tNode->nextNode = dq->front;
    dq->front = tNode;
    if (!dq->rear) dq->rear = tNode;
}

void add_rear(deque *dq, data val) {
    node *tNode = newNode(val, NULL, NULL);
    if (dq->rear) dq->rear->nextNode = tNode;
    tNode->prevNode = dq->rear;
    dq->rear = tNode;
    if (!dq->front) dq->front = tNode;
}

data get_front(deque dq) {
    return dq.front->val;
}

data get_rear(deque dq) {
    return dq.rear->val;
}

data delete_front(deque *dq) {
    data rValue = get_front(*dq);
    node *delNode = dq->front;
    dq->front = dq->front->nextNode;
    if (dq->front) dq->front->prevNode = NULL;
    else dq->rear = NULL;
    free(delNode);
    return rValue;
}

data delete_rear(deque *dq) {
    data rValue = get_rear(*dq);
    node *delNode = dq->rear;
    dq->rear = dq->rear->prevNode;
    if (dq->rear) dq->rear->nextNode = NULL;
    else dq->front = NULL;
    free(delNode);
    return rValue;
}

int main() {
    deque dq = new_deque();
    add_front(&dq, 1);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    add_front(&dq, 2);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    add_rear(&dq, 3);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_front(&dq);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_front(&dq);
    printf("%d %d\n", get_front(dq), get_rear(dq));
    delete_front(&dq);
    add_front(&dq, 1);
    printf("%d %d\n", get_front(dq), get_rear(dq));
}