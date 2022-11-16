//
// Created by fdrla on 16/11/2022.
//

#ifndef MAIN_09_CPP_ALKALMAZOTT_H
#define MAIN_09_CPP_ALKALMAZOTT_H
#include <iostream>
#include "Szemely.h"
using namespace std ;

class Alkalmazott: public Szemely{
protected:
    static int id ;
    string munkakor ;
public:
    Alkalmazott(const string &vezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor);
    virtual void print(ostream& os) const;
};


#endif //MAIN_09_CPP_ALKALMAZOTT_H
