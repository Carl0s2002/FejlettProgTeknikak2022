//
// Created by fdrla on 14/12/2022.
//

#ifndef MAIN_12_CPP_MYIFSTREAM_H
#define MAIN_12_CPP_MYIFSTREAM_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std ;
class myifstream: public ifstream {
public:
    myifstream( const string& filename ) ;
    int filesize();
    char operator[] ( int index ) ;
};


#endif //MAIN_12_CPP_MYIFSTREAM_H
