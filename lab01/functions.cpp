//
// Created by Admin on 10/5/2022.
//

#include "functions.h"

using namespace std ;

int countBits( int number) {
    int counter = 0 ;
    while ( number != 0 ) {
        if ( (number & 1) == 1 ){
            ++counter;
        }
        number = number >> 1 ;
    }
    return counter;
}
bool setBit( int& number , int order ){
    if ( order > 31 || order < 0 ) {
        return false ;
    }
    int helper = 1 ;
    helper = helper << order ;
    number = number | helper ;
    return true ;
}
double mean(double array[], int numElements){
    if ( numElements == 0 ){
        return NAN ;
    }
    double sum = 0 ;
    for ( int i = 0 ; i < numElements ; ++i ) {
        sum += array[i] ;
    }
    return sum/numElements ;
}
double szoras( double array[] , int numElements ) {
    if ( numElements == 0 ){
        return NAN ;
    }
    double szoras = 0 ;
    double atlag = mean( array , numElements ) ;
    for ( int i = 0 ; i < numElements ; ++i ) {
        szoras += pow(array[i] - atlag , 2 ) ;
    }
    szoras = sqrt(szoras/numElements) ;
    return szoras ;
}

pair<double, double> twoBiggest(double array[], int numElements) {
    pair<double,double> biggestValues(0 , 0 ) ;
    if ( numElements == 0 ){
        biggestValues.first = NAN ;
        biggestValues.second = NAN;
        return biggestValues;
    }
    else if( numElements == 1 ){
        biggestValues.first = array[0] ;
        biggestValues.second = array[0] ;
        return biggestValues ;
    }
    for ( int i = 0 ; i < numElements ; ++i ){
        if ( biggestValues.first < array[i] ) {
            biggestValues.second = biggestValues.first ;
            biggestValues.first = array[i] ;
        }
        else if ( biggestValues.second < array[i] ) {
            biggestValues.second = array[i] ;
        }
    }
    return biggestValues ;
}

void stringToNumeric() {
    istringstream iss("1.1 2.2 3.3 alma 4.4");
    istringstream iss2(" 1.1 2.2 3.3 alma 4.4");
    string s ;
    double number = 0 , sum = 0 ;
    while( iss2 >> s ){
        iss >> number ;
        sum += number;
    }
    cout << "A szamok osszege:" << sum ;
}
int countWords(string text){
    istringstream iss(text) ;
    string help ;
    int i = 0 ;
    while ( iss >> help ){
        ++i ;
    }
    return i ;
}
string code(string text){
    for( int i = 0 ; i < text.capacity() ; ++i ) {
        if ( text[i] == ' ' ) {
            continue;
        }
        if ( text[i] == 'z' ){
            text[i] = 'a' ;
        }
        else if ( text[i] == 'Z' ) {
            text[i] = 'A' ;
        }
        else {
            text[i] = text[i] + 1;
        }
    }
    return text ;
}