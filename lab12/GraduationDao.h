//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_GRADUATIONDAO_H
#define MAIN_12_CPP_GRADUATIONDAO_H


#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class GraduationDao {
public:
    virtual void enrollStudents(const string &filename) = 0;

    virtual void saveGradesForSubject(const string &subject, const string &filename) = 0;

    virtual void computeAverage() = 0;

    virtual int numEnrolled() const = 0;

    virtual int numPassed() const = 0;

    virtual double getAverageBySubject( const string& subject) const = 0;

    virtual Student findById(int id) const = 0;
};


#endif //MAIN_12_CPP_GRADUATIONDAO_H
