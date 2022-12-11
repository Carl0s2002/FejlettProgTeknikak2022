#include <iostream>
#include <algorithm>
#include "Settlement.h"
#include "SettlementStatisics.h"
#include "SettlementStatisticsImpl.h"
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationService.h"
#include "GraduationServiceImpl.h"


string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
//    // ADMIN
//    GraduationDao *dao = new GraduationDaoImpl();
//    dao->enrollStudents("names.txt");
//    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;
//
//    for (int i = 0; i < numSubjects; ++i) {
//        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
//    }
//    dao->computeAverage();
//
////    cout << "Subject's averages: " << endl;
////    try {
////        for (int i = 0; i < numSubjects; ++i) {
////            cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
////        }
////    }catch( domain_error& e){
////        cerr << e.what() << endl;
////    }
//
//    GraduationService* service = new GraduationServiceImpl(dao) ;
//    cout << "Individual results: " << endl;
//    int id = 0;
//    while (id != -1) {
//        cout << "Enter ID (-1 for EXIT): ";
//        cin >> id;
//        if (id == -1) {
//            break;
//        }
//        cout << "Student id=" << id << " results: " << endl;
//        try {
//            auto results = dao->findById(id);
//            for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
//                cout << "\t" << e.first << " : " << e.second << endl;
//            });
//        } catch (out_of_range &e) {
//            cerr << "Id not found" << endl;
//        }
//    }
//    delete service ;
//    delete dao;

    SettlementStatisics *statisics = new SettlementStatisticsImpl("telepulesek.csv") ;
    cout << "Number of settlements:" << statisics->numSettlements() << endl ;
    cout << "Number of counties:" << statisics->numCounties() << endl ;
    cout << "Number of settlements by counties:" << statisics->numSettlementsByCounty("AB") << endl ;
    vector<Settlement> settlementsBycounty = statisics->findSettlementsByCounty("AB") ;
    cout << "Settlements by county(AB):" << endl ;
    for ( auto& v: settlementsBycounty  ){
        cout << v << endl ;
    }
    Settlement settlementByNameAndCounty = statisics->findSettlementsByNameAndCounty("Dumitrana" , "IF") ;
    cout << "Settlement by name and county(Dumitrana , IF): " << settlementByNameAndCounty << endl ;
    cout << "Max population:" << statisics->maxPopulationDensity() << endl ;
    cout << "Min population:" << statisics->minPopulationDensity() << endl ;
    vector<Settlement> settlementsByName = statisics->findSettlementsByName("Sfarcea");
    cout << "Settlements by name(Sfarcea):" << endl ;
    for( auto& v : settlementsByName ) {
        cout << v << endl ;
    }
    return 0;
}
