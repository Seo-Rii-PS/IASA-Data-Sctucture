//
// Created by Seo_Hyun on 2020-04-27.
//

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int element;

typedef struct node {
    struct node *link;
    element el;
} node;

node *top;

int isEmpty() {
    return !top;
}

void printStackDfs(node *currentNode) {
    if (!currentNode) return;
    printf("%d ", currentNode->el);
    printStackDfs(currentNode->link);
}

void printStack() {
    printf("[ ");
    printStackDfs(top);
    printf("]\n");
}

void push(element el) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->el = el;
    newNode->link = top;
    top = newNode;
}

element peek() {
    assert(!isEmpty());
    return top->el;
}

element pop() {
    element rVal = peek();
    node *delNode = top;
    top = top->link;
    free(delNode);
    return rVal;
}

int main() {
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printStack();
}