//
// Created by fdrla on 19/11/2022.
//

#ifndef MAIN_09_CPP_CEG_H
#define MAIN_09_CPP_CEG_H

#include <vector>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std ;

class Ceg {
    string name ;
    vector<Alkalmazott> alkalmazottak ;
    vector<Manager> managerek;
public:
    Ceg( string name ) ;
    void hire( const Alkalmazott& alkalmazott ) ;
    void fire( int id ) ;
    void promote( const Manager& manager ) ;
    void addToManager( Manager& manager , Alkalmazott alkalmazott ) ;
    void takeFromManager( Manager manager , Alkalmazott alkalmazott ) ;
    void printAlkalmazottak() ;
    void printManagerek();
};

#endif //MAIN_09_CPP_CEG_H
