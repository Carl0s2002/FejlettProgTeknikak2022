//
// Created by fdrla on 19/11/2022.
//

#include "Ceg.h"

Ceg::Ceg(string name) {
    this->name = name ;
}

void Ceg::hire( const Alkalmazott& alkalmazott) {
    this->alkalmazottak.emplace_back(alkalmazott) ;
}

void Ceg::fire(int id) {
    int i = 0 ;
    for ( auto& a:this->alkalmazottak ){
        if ( a.getId() == id ) {
            break;
        }
        ++i ;
    }
    this->alkalmazottak.erase(this->alkalmazottak.begin() + i ) ;
}

void Ceg::addToManager(Manager& manager, Alkalmazott alkalmazott) {
    manager.addAlkalmazott( &alkalmazott ) ;
}

void Ceg::takeFromManager(Manager manager, Alkalmazott alkalmazott) {
    manager.deleteAlkalmazott(&alkalmazott) ;
}

void Ceg::printAlkalmazottak() {
    for ( auto& a :this->alkalmazottak){
        cout << a ;
    }
}

void Ceg::printManagerek() {
    for ( Manager& a:this->managerek){
        cout << a ;
    }
}

void Ceg::promote( const Manager& manager) {
    this->managerek.emplace_back(manager) ;
}
