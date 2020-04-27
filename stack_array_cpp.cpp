//
// Created by Seo_Hyun on 2020-04-27.
//

#include<iostream>
#include "stack_array_cpp.h"

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    std::cout << stk.peek() << std::endl;
    stk.push(3);
    std::cout << stk.pop() << std::endl;
    std::cout << stk.pop() << std::endl;
    std::cout << stk.pop() << std::endl;
    std::cout << stk.pop() << std::endl;
}