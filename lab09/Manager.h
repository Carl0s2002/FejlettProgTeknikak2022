//
// Created by fdrla on 16/11/2022.
//

#ifndef MAIN_09_CPP_MANAGER_H
#define MAIN_09_CPP_MANAGER_H

#include <iostream>
#include "Alkalmazott.h"
#include <vector>

using namespace std;

class Manager: public Alkalmazott{
    vector<Alkalmazott*> beosztottak ;
public:
    const static string MANAGER_MUNKAKOR ;
    static int id ;
    Manager(const string &vezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor);
    void addAlkalmazott( Alkalmazott* alkalmazott );
    void deleteAlkalmazott( Alkalmazott* alkalmazott );
    int beosztottakSzama() ;
    virtual void print( ostream& os) const ;
};


#endif //MAIN_09_CPP_MANAGER_H
