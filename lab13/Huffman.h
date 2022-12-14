//
// Created by fdrla on 14/12/2022.
//

#ifndef MAIN_12_CPP_HUFFMAN_H
#define MAIN_12_CPP_HUFFMAN_H

#include <string>
#include <map>
#include <queue>
using namespace std ;

class Huffman {
    map<char,int> frequencies ;
    struct node{
        char data ;
        int freq ;
        struct node *left , *right ;

        node(  char data=' ' , int freq = 0 , node* left= nullptr , node* right = nullptr): data(data) , freq(freq) , left(left) , right(right) {}
    };
    struct Compnode{
        bool operator()(node* n1 , node* n2 ){
            return n1->freq > n2->freq ;
        }
    };
    priority_queue<node* , vector<node*> , Compnode> pq ;
    void createTree() ;
    void deleteTree(node * root) ;
public:
    explicit Huffman( const string& filename ) ;
    void printCodes( node* root ) ;
    ~Huffman();
};


#endif //MAIN_12_CPP_HUFFMAN_H
