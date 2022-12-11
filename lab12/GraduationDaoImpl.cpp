//
// Created by Admin on 07/12/2022.
//

#include "GraduationDaoImpl.h"
#include <fstream>
#include <algorithm>

using namespace std;

void GraduationDaoImpl::enrollStudents(const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "File not found: " << filename << endl;
        exit(1);
    }
    int id;
    while (ifs >> id) {
        string fname;
        ifs >> fname;
        string lname;
        ifs >> lname;
        this->students.insert({id, Student(id, fname, lname)});
    }
}

void GraduationDaoImpl::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "File not found: " << filename << endl;
        exit(1);
    }
    int id;
    while (ifs >> id) {
        double grade;
        ifs >> grade;
        try {
            this->students.at(id).addGrade(subject, grade);
        } catch (out_of_range &e) {
            cerr << subject << ": student with id "<<id<<" not found"<<endl;
        }
    }
}

int GraduationDaoImpl::numPassed() const {
    return count_if(students.begin(), students.end(), [] (const pair<int, Student>& p){
        return p.second.getAverage() > 0;
    });
}

void GraduationDaoImpl::computeAverage() {
    for( auto& p : this->students ){
        p.second.computeAverage();
    }
}

double GraduationDaoImpl::getAverageBySubject(const string &subject) const {
    double avg = 0;
    int counter = 0;
    for( auto& p : this->students ){
        auto result = p.second.getGrades().find(subject);
        if( result != p.second.getGrades().end()){
            avg += result->second;
            ++counter;
        }
    }
    if ( counter == 0 ){
        throw domain_error("subject does not exist");
    }
    return avg/counter;
}

