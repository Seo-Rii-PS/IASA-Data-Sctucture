//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int data;

struct node {
    data val;
    node *nextNode;
};

node *newNode(data val, node *nextNode) {
    node *tNode = (node *) malloc(sizeof(node));
    tNode->val = val;
    tNode->nextNode = nextNode;
    return tNode;
}

struct queue {
    node *front, *rear;
};

queue init() {
    queue tQ = {NULL, NULL};
    return tQ;
}

int isEmpty(queue *qu) {
    if (qu->front == NULL) return 1;
    else return 0;
}

void enQueue(queue *qu, data val) {
    node *tNode = newNode(val, NULL);
    if (qu->rear) qu->rear->nextNode = tNode;
    qu->rear = tNode;
    if (!qu->front) qu->front = tNode;
}

data peek(queue qu) {
    assert(isEmpty(&qu) == 0);
    return qu.front->val;
}

data deQueue(queue *qu) {
    assert(isEmpty(qu) == 0);
    data rValue = peek(*qu);
    node *delNode = qu->front;
    qu->front = qu->front->nextNode;
    free(delNode);
    return rValue;
}

void dfsPrintQueue(node *no) {
    if (no == NULL) return;
    printf("%d ", no->val);
    dfsPrintQueue(no->nextNode);
}

void printQueue(queue *qu) {
    printf("[ ");
    dfsPrintQueue(qu->front);
    printf("]\n");
}

int main() {
    queue qu = init();
    enQueue(&qu, 1);
    enQueue(&qu, 2);
    printQueue(&qu);
    printf("%d\n", deQueue(&qu));
    printf("%d\n", peek(qu));
    printf("%d\n", deQueue(&qu));
    printf("%d\n", deQueue(&qu));
}