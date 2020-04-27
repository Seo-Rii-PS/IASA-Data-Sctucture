//
// Created by Seo_Hyun on 2020-04-27.
//

#include<cassert>

#ifndef IASA_STACK_ARRAY_CPP_H
#define IASA_STACK_ARRAY_CPP_H

#endif //IASA_STACK_ARRAY_CPP_H

template<typename element>
class stack {
private:
    element *elArr;
    int stackLevel, assignedSize;

    void realloc() {
        element *tArr = new element[assignedSize <<= 1];
        for (int i = 0; i <= stackLevel; ++i) tArr[i] = elArr[i];
        delete[] elArr;
        elArr = tArr;
    }

public:
    stack(int capacity = 2) : elArr(new element[capacity]), stackLevel(-1), assignedSize(capacity) {}

    void push(element el) {
        if (stackLevel == assignedSize - 1) realloc();
        elArr[++stackLevel] = el;
    }

    element peek() {
        assert(stackLevel >= 0);
        return elArr[stackLevel];
    }

    element pop() {
        assert(stackLevel >= 0);
        return elArr[stackLevel--];
    }

    int size() { return stackLevel + 1; }

    ~stack() {
        if (elArr) {
            delete[] elArr;
        }
    }
};