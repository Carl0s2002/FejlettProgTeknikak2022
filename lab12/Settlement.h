//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_SETTLEMENT_H
#define MAIN_12_CPP_SETTLEMENT_H
#include <iostream>
#include <vector>

using namespace std ;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;
public:
    Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                           population(population) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Settlement::name = name;
    }

    const string &getCounty() const {
        return county;
    }

    void setCounty(const string &county) {
        Settlement::county = county;
    }

    int getPopulation() const {
        return population;
    }

    void setPopulation(int population) {
        Settlement::population = population;
    }

    friend ostream &operator<<(ostream &os, const Settlement &settlement) {
        os << "name: " << settlement.name << " county: " << settlement.county << " population: "
           << settlement.population;
        return os;
    }

};



#endif //MAIN_12_CPP_SETTLEMENT_H
