#include <iostream>
#include <algorithm>
#include <map>

using namespace std ;
int main() {
    ///1.
    cout << "1. feladat:" << endl << endl ;
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    string toFind = "berry" ;
    auto result1 = find_if(fruits.begin() , fruits.end() , [&toFind]( const string& e ) {
        return e.contains(toFind ) ;
    }) ;
    cout << "Eredmeny:" << *result1 << endl << endl ;
    ///2.
    cout << "2. feladat:" << endl << endl ;
    vector<int> numbers = { 6 , 2 , 3 , 4 };
    auto result2 = all_of(numbers.begin() , numbers.end() , [](const int& e){
        return e%2 == 0;
    }) ;
    cout << (result2 ? "Mind paros" : "Nem mind paros") << endl << endl ;
    ///3.
    cout << "3. feladat:" << endl << endl ;
    for_each( numbers.begin() , numbers.end() , [](int& e){
        e = e * 2 ;
    }) ;
    for_each( numbers.begin() , numbers.end() , [](int& e){
        cout << e << " ";
    }) ;
    cout << endl << endl ;
    ///4.
    cout << "4. feladat:" << endl << endl ;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    auto result3 = count_if( months.begin() , months.end() , []( const string& e){
        return e.length() == 5 ;
    });
    cout << result3 << endl << endl ;
    ///5.
    cout << "5. feladat:" << endl << endl ;
    vector<double> nums = { 3 , 4 , 2 , 1 , 5};
    sort( nums.begin() , nums.end() , greater<double>() ) ;
    for_each( nums.begin() , nums.end() , [](const double& e ){
        cout << e << " " ;
    }) ;
    nums = { 2 ,1 , 5 , 8 , 29 };
    sort( nums.begin() , nums.end() , []( const double& e1 , const double& e2 ){
        return e1 > e2 ;
    }) ;
    cout << endl ;
    for_each( nums.begin() , nums.end() , [](const double& e ){
        cout << e << " " ;
    }) ;
    cout << endl << endl ;
    ///6.
    cout << "6. feladat:" << endl << endl ;
    vector<pair<string , double>> monthGrades = {
            make_pair( "January" , -2 ) ,
            make_pair("February" , -5.2 ) ,
            make_pair("March" , 6 ) ,
            make_pair("April" , 8 ) ,
            make_pair("May" , 10 ) ,
            make_pair("June" , 28 ) ,
            make_pair("July" , 26 ) ,
            make_pair("August" , 26.5 ) ,
            make_pair("September" , 18.6 ) ,
            make_pair("October" , 15.3) ,
            make_pair("November" , 10.4 ) ,
            make_pair("December" , 2.2 )
    };
    sort( monthGrades.begin() , monthGrades.end() , [](const pair<string , double> &e1 , const pair<string , double> &e2 ){
        return e1.second < e2.second ;
    }) ;
    for_each(  monthGrades.begin() , monthGrades.end() , [](const pair<string , double> &e ){
        cout << e.first << " " << e.second << endl ;
    });
    cout << endl ;
    ///7.
    cout << "7. feladat:" << endl << endl ;
    vector<double> realNums = { 1.2 , 3.5 , 1.1  , 2.5 , 1.7 };
    sort( realNums.begin() , realNums.end() , [](const double& e1 , const double& e2){
        return (int) e1 < (int)e2 ;
    }) ;
    for_each( realNums.begin() , realNums.end() , []( const double& e ){
        cout << e << " " ;
    });
    ///8.
    cout << endl << endl << "8. feladat:" ;
    cout << endl << endl ;
    for_each( months.begin() , months.end() , []( string& e){
        e[0] += 'a'-'A' ;
    });
    for_each( months.begin() , months.end() , []( string& e){
        cout << e << " " ;
    });
    cout << endl << endl ;
    ///9.
    cout << "9. feladat:" << endl << endl ;
    map<char , int> abc[26] ;
    return 0;
}