//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_SETTLEMENTSTATISTICSIMPL_H
#define MAIN_12_CPP_SETTLEMENTSTATISTICSIMPL_H

#include "SettlementStatisics.h"
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

class SettlementStatisticsImpl: public SettlementStatisics {
    multimap<string , Settlement> settlements ;
public:
    SettlementStatisticsImpl(const string& fileName );

    int numSettlements() const override ;
    int numCounties() const override;
    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(
                const string& county) const override;
    Settlement findSettlementsByNameAndCounty(
                const string& name, const string& county) const override ;
    Settlement maxPopulationDensity() const override ;
    Settlement minPopulationDensity() const override;
    vector<Settlement> findSettlementsByName(
                const string& name) override ;
};


#endif //MAIN_12_CPP_SETTLEMENTSTATISTICSIMPL_H
