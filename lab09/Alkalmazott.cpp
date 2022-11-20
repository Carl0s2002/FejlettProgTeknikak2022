//
// Created by fdrla on 16/11/2022.
//

#include "Alkalmazott.h"
int Alkalmazott::counter{0} ;
Alkalmazott::Alkalmazott(const string &vezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor)
        : Szemely(vezeteknev, keresztnev, szuletesiEv), munkakor(munkakor) {
        this->id = this->counter++ ;
}

void Alkalmazott::print(ostream &os)const {
    os << "Alkalmazott:" << endl ;
    os << "Id: " << this->id << endl ;
    os << "Vezeteknev es Keresztnev: " << this->vezeteknev << " " << this->keresztnev ;
    os << endl << "Szuletesi ev: " << this->szuletesiEv << endl ;
    os << "Munkakor:" << this->munkakor ;
    os << endl ;
}

const string &Alkalmazott::getMunkakor() const {
    return munkakor;
}
