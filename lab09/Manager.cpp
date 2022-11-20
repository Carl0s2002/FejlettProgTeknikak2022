//
// Created by fdrla on 16/11/2022.
//

#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR="Manager";

Manager::Manager(const string &vezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor)
        : Alkalmazott(vezeteknev, keresztnev, szuletesiEv, MANAGER_MUNKAKOR) {
    this->id = this->counter ;
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    this->beosztottak.emplace_back(alkalmazott) ;
}

void Manager::deleteAlkalmazott(Alkalmazott* alkalmazott) {
    int index = 0 ;
   for ( auto& a: this->beosztottak ) {
       if ( a == alkalmazott ) {
           break;
       }
       index++ ;
   }
   this->beosztottak.erase( this->beosztottak.begin() + index ) ;
}

int Manager::beosztottakSzama() {
    return this->beosztottak.size();
}

void Manager::print(ostream &os) const {
    os << "Manager:" << endl;
    os << "Id: "  << this->id << endl ;
    os << "Vezeteknev es Keresztnev: " << this->vezeteknev << " " << this->keresztnev << endl ;
    os << "Szuletesi ev: " << this->szuletesiEv << endl ;
    os << "Munkakor: " << this->munkakor << endl ;
    os << "Beosztottak:" << endl ;
    for ( Alkalmazott *a: this->beosztottak ){
        os << *a ;
    }
}
