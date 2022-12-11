//
// Created by Admin on 07/12/2022.
//

#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return 0;
}

int SettlementStatisticsImpl::numCounties() const {
    return 0;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return 0;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    return vector<Settlement>();
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    return Settlement();
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    return Settlement();
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    return Settlement();
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    return vector<Settlement>();
}
