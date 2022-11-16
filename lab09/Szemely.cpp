//
// Created by fdrla on 16/11/2022.
//

#include "Szemely.h"

Szemely::Szemely(const string &vezeteknev, const string &keresztnev, int szuletesiEv) : vezeteknev(vezeteknev),
                                                                                        keresztnev(keresztnev),
                                                                                        szuletesiEv(szuletesiEv) {}

void Szemely::print(ostream &os) const{
    os << "Szemely:" << endl ;
    os << "Vezeteknev es Keresztnev: " << this->vezeteknev << " " << this->keresztnev ;
    os << endl << "Szuletesi ev: " << this->szuletesiEv ;
    os << endl ;
}
ostream &operator<<(ostream &os, const Szemely& szemely) {
szemely.print(os);
return os;
}

