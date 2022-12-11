//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_GRADUATIONSERVICEIMPL_H
#define MAIN_12_CPP_GRADUATIONSERVICEIMPL_H

#include "Student.h"
#include "GraduationService.h"
#include "GraduationDao.h"

class GraduationServiceImpl: public GraduationService{
private:
    GraduationDao* dao ;
public:
    GraduationServiceImpl(GraduationDao *dao) ;

    Student findById(int id) const override;
    double getResultByIdAndSubject(int id,const string& subject) const ;
};


#endif //MAIN_12_CPP_GRADUATIONSERVICEIMPL_H
