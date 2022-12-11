//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_SETTLEMENTSTATISICS_H
#define MAIN_12_CPP_SETTLEMENTSTATISICS_H

#include <iostream>
#include "Settlement.h"

class SettlementStatisics {
public:
        virtual int numSettlements() const = 0;
        virtual int numCounties() const = 0;
        virtual int numSettlementsByCounty(const string& county) const = 0;
        virtual vector<Settlement> findSettlementsByCounty(
                const string& county) const = 0;
        virtual Settlement findSettlementsByNameAndCounty(
                const string& name, const string& county) const = 0;
        virtual Settlement maxPopulationDensity() const = 0;
        virtual Settlement minPopulationDensity() const = 0;
        virtual vector<Settlement> findSettlementsByName(
                const string& name) = 0;
};


#endif //MAIN_12_CPP_SETTLEMENTSTATISICS_H
