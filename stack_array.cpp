//
// Created by Seo_Hyun on 2020-04-27.
//

#include<stdio.h>
#include<assert.h>

const int stackMaxSize = 50;

typedef int element;
int stackTop = -1;
element stackArray[stackMaxSize];

void push(element el) {
    assert(stackTop < stackMaxSize-1);
    stackArray[++stackTop] = el;
}

element peek() {
    assert(stackTop >= 0);
    return stackArray[stackTop];
}

element pop() {
    assert(stackTop >= 0);
    return stackArray[stackTop--];
}

int main() {
    push(1);
    push(2);
    printf("%d\n", peek());
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
}