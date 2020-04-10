//
// Created by Seo_Hyun on 2020-04-11.
//

#include<stdio.h>
#include<stdlib.h>

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

queue newQueue() {
    queue tQ = {NULL, NULL};
    return tQ;
}

void enQueue(queue *qu, data val) {
    node *tNode = newNode(val, NULL);
    if (qu->rear) qu->rear->nextNode = tNode;
    qu->rear = tNode;
    if (!qu->front) qu->front = tNode;
}

data frontQueue(queue qu) {
    return qu.front->val;
}

data deQueue(queue *qu) {
    data rValue = frontQueue(*qu);
    node *delNode = qu->front;
    qu->front = qu->front->nextNode;
    free(delNode);
    return rValue;
}

int main() {
    queue qu = newQueue();
    enQueue(&qu, 1);
    printf("%d\n", frontQueue(qu));
    enQueue(&qu, 2);
    printf("%d\n", frontQueue(qu));
    deQueue(&qu);
    printf("%d\n", frontQueue(qu));
}