//
// Created by fodor.laszlo.carlos on 10/5/2022.
//

#ifndef FEJLETTPROGTEKNIKAK2022_STACK_H
#define FEJLETTPROGTEKNIKAK2022_STACK_H
#include <cmath>
#include <iostream>
#include "List.h"

using namespace std;
class Stack {
public:
    Stack( int ) ;

    ~Stack();

    void push(int e);

    int pop();

    int top() ;

    void print() ;

    bool isEmpty() const;

private:
    struct listStack{
        int top ;
        int capacity ;
        int *stack;

    };
    listStack listStack1 ;
    List list ;
};


#endif //FEJLETTPROGTEKNIKAK2022_STACK_H
