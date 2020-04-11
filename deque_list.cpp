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

void add_front(deque *qu, data val) {
    node *tNode = newNode(val, NULL, NULL);
    if (qu->front) qu->front->prevNode = tNode;
    tNode->nextNode = qu->front;
    qu->front = tNode;
    if (!qu->rear) qu->rear = tNode;
}

void add_rear(deque *qu, data val) {
    node *tNode = newNode(val, NULL, NULL);
    if (qu->rear) qu->rear->nextNode = tNode;
    tNode->prevNode = qu->rear;
    qu->rear = tNode;
    if (!qu->front) qu->front = tNode;
}

data get_front(deque qu) {
    return qu.front->val;
}

data get_rear(deque qu) {
    return qu.rear->val;
}

data delete_front(deque *qu) {
    data rValue = get_front(*qu);
    node *delNode = qu->front;
    qu->front = qu->front->nextNode;
    if (qu->front) qu->front->prevNode = NULL;
    else qu->rear = NULL;
    free(delNode);
    return rValue;
}

data delete_rear(deque *qu) {
    data rValue = get_rear(*qu);
    node *delNode = qu->rear;
    qu->rear = qu->rear->prevNode;
    if (qu->rear) qu->rear->nextNode = NULL;
    else qu->front = NULL;
    free(delNode);
    return rValue;
}

int main() {
    deque qu = new_deque();
    add_front(&qu, 1);
    printf("%d %d\n", get_front(qu), get_rear(qu));
    add_front(&qu, 2);
    printf("%d %d\n", get_front(qu), get_rear(qu));
    add_rear(&qu, 3);
    printf("%d %d\n", get_front(qu), get_rear(qu));
    delete_front(&qu);
    printf("%d %d\n", get_front(qu), get_rear(qu));
    delete_front(&qu);
    printf("%d %d\n", get_front(qu), get_rear(qu));
    delete_front(&qu);
    add_front(&qu, 1);
    printf("%d %d\n", get_front(qu), get_rear(qu));
}