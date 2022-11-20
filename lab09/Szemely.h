//
// Created by fdrla on 16/11/2022.
//

#ifndef MAIN_09_CPP_SZEMELY_H
#define MAIN_09_CPP_SZEMELY_H

#include <iostream>

using namespace std;

class Szemely{
protected:
        string vezeteknev ;
        string keresztnev ;
        int szuletesiEv ;
public:
    Szemely(const string &vezeteknev, const string &keresztnev, int szuletesiEv);
    virtual void print( ostream& os ) const ;
};

ostream &operator<<(ostream &os, const Szemely& szemely) ;

#endif //MAIN_09_CPP_SZEMELY_H