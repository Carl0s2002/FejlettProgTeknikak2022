//
// Created by Admin on 07/12/2022.
//

#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const string& fileName ){
    ifstream f( fileName ) ;
    if ( !f ) {
        cerr << "Wrong file" ;
        exit(1) ;
    }
    string line;
    getline(f, line);
    while (getline(f, line)) {
        string name, county;
        int population;
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> population;
        settlements.insert({county, Settlement(name, county, population)});
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return this->settlements.size() ;
}

int SettlementStatisticsImpl::numCounties() const {
    vector<string> counties ;
    for ( auto& p : this->settlements ) {
        bool ok = true ;
        for ( auto& c : counties ) {
            if ( c == p.second.getCounty() ) {
                ok = false ;
                break;
            }
        }
        if (ok) {
            counties.emplace_back(p.second.getCounty()) ;
        }
    }
    return counties.size() ;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int sum = 0 ;
    for ( auto& p : this->settlements ) {
        if ( p.second.getCounty() == county ) {
            sum++ ;
        }
    }
    return sum ;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> settlementByCounty ;
    for ( auto& p : this->settlements ) {
        if ( p.second.getCounty() == county ) {
            settlementByCounty.emplace_back(p.second) ;
        }
    }
    return settlementByCounty ;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for ( auto& p : this->settlements ){
        if ( p.second.getCounty() == county && p.second.getName() == name ) {
            return p.second ;
        }
    }
    return Settlement("" , "" , 0 ) ;
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    int maxPopulation = 0 ;
    Settlement settlement("" , "" , 0) ;
    for ( auto& p : this->settlements ) {
        if ( p.second.getPopulation() > maxPopulation ){
            maxPopulation = p.second.getPopulation() ;
            settlement = p.second ;
        }
    }
    return settlement ;
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    int minPopulation = INT_MAX ;
    Settlement settlement("" , "" , 0) ;
    for ( auto& p : this->settlements ) {
        if (p.second.getPopulation() < minPopulation ){
            minPopulation = p.second.getPopulation() ;
            settlement = p.second ;
        }
    }
    return settlement ;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> settlementsByName ;
    for ( auto& p : this->settlements ) {
        if ( p.second.getName() == name ){
            settlementsByName.emplace_back(p.second) ;
        }
    }
    return settlementsByName ;
}
