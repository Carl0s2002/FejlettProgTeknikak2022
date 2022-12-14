#include <iostream>
#include "myifstream.h"
#include "Huffman.h"
using namespace std ;
int main() {
//    myifstream f("input.txt");
//    if ( !f ){
//        cout << "File not found" ;
//        exit(1) ;
//    }
//    for( int i=0; i <f.filesize(); ++i){
//        cout << f[i] ;
//    }
//    cout << endl;
    Huffman huf("input.txt") ;
    return 0 ;
}