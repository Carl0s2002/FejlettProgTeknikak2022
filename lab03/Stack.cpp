//
// Created by fodor.laszlo.carlos on 10/5/2022.
//

#include "Stack.h"

Stack::Stack(  int capacity ) {
    cout << endl << "Konstruktor!" << endl;
    listStack1.capacity = capacity ;
    listStack1.top = -1 ;
    listStack1.stack = new int[capacity] ;
}

void Stack::push(int e) {
    if ( listStack1.top < listStack1.capacity) {
        listStack1.top++;
        listStack1.stack[listStack1.top] = e;
    }
}

int Stack::pop() {
    try {
        if ( this->isEmpty() ){
            throw(-1) ;
        }
        int help = listStack1.stack[listStack1.top];
        listStack1.stack[listStack1.top--] = NAN;
        return help;
    }catch( int myNum) {
        cout << "A verem ures!" ;
        return myNum ;
    }
}

bool Stack::isEmpty() const {
    if ( listStack1.top == -1 ){
        return true;
    }
    return false ;
}

Stack::~Stack() {
    cout << "Destruktor!" ;
    while ( listStack1.top != -1 ){
        listStack1.stack[listStack1.top--] = NAN ;
    }
}

int Stack::top() {
    if ( !this->isEmpty()) {
        return listStack1.stack[listStack1.top];
    }
    return NAN ;
}

void Stack::print() {
    for ( int i = listStack1.top ; i >= 0 ; --i ){
        cout << listStack1.stack[i] << endl ;
    }
}
