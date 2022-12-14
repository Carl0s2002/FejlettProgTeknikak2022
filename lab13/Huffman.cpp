//
// Created by fdrla on 14/12/2022.
//

#include "Huffman.h"
#include <fstream>
#include <iostream>
Huffman::Huffman(const string &filename) {
    ifstream ifs(filename) ;
    if ( !ifs ) {
        cerr << "File not found" ;
        exit(0) ;
    }
    int c;
    while( (c = ifs.get()) != -1 ){
        frequencies[c]++ ;
    }
    for ( auto it: frequencies){
        cout << it.first << " " << it.second << endl  ;
    }
    createTree() ;
    cout << "Total freq:" << pq.top()->freq << endl ;
}

Huffman::~Huffman() {
//    deleteTree();
}

void Huffman::deleteTree(Huffman::node *root) {

}

void Huffman::createTree() {
    for ( auto& it: frequencies ){
        pq.push(new node(it.first , it.second )) ;
        while( pq.size() > 1 ) {
            //kiveszek 2 elemet
            //epitek egy uj csompontot
            // visszateszem az uj csomopontot
            node* n1 = pq.top() ;
            pq.pop();
            node* n2 = pq.top() ;
            pq.pop();
            node* newNode = new node(' ' , n1->freq+n2->freq , n1 , n2 ) ;
            pq.push(newNode) ;
        }
    }
}

void Huffman::printCodes(node* root ) {

}
