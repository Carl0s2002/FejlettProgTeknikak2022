//
// Created by Admin on 07/12/2022.
//

#ifndef MAIN_12_CPP_GRADUATIONDAOIMPL_H
#define MAIN_12_CPP_GRADUATIONDAOIMPL_H


#include "Student.h"
#include "GraduationDao.h"

class GraduationDaoImpl: public GraduationDao {
    int year {2022};
    map<int, Student> students;
public:
    void enrollStudents(const string &filename) override;

    void saveGradesForSubject(const string &subject, const string &filename) override ;

    void computeAverage() override;

    int numEnrolled() const override{
        return students.size();
    }

    int numPassed() const override;

    Student findById(int id) const override{
        return students.at(id);
    }

    double getAverageBySubject( const string& subject) const override;
};



#endif //MAIN_12_CPP_GRADUATIONDAOIMPL_H
