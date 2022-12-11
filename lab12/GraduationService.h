//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_GRADUATIONSERVICE_H
#define MAIN_12_CPP_GRADUATIONSERVICE_H

#include "Student.h"

class GraduationService{
public:
    virtual Student findById(int id) const = 0;
    virtual double getResultByIdAndSubject(int id,
                                           const string& subject) const = 0;
};



#endif //MAIN_12_CPP_GRADUATIONSERVICE_H
