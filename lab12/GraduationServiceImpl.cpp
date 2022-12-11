//
// Created by Admin on 07/12/2022.
//

#include "GraduationServiceImpl.h"

Student GraduationServiceImpl::findById(int id) const {
    return dao->findById(id) ;
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
}

GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao) : dao(dao) {}
