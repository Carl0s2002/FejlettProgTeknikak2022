//
// Created by fdrla on 23/11/2022.
//

#ifndef MAIN_10_CPP_ORDEREDLIST_H
#define MAIN_10_CPP_ORDEREDLIST_H
// OrderedList.h
#include <functional>
#include <iostream>
using namespace std;
// Class declaration
template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;
// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >

class OrderedList {
private:
    struct Node{
        T value ;
        Node* next ;
        Node( T value , Node* next = nullptr ): value(value) , next(next) {}
    };
    int numElements{0};
    Node* first {nullptr};
public:
    ~OrderedList();
    void listElements( ostream& os = cout );
    void insert(const T& what);
    bool isEmpty() ;
    void remove(const T& what) ;
    int size(){
        return numElements;
    }
    bool find( const T& what );
    friend class Iterator<T, LessComp, Equal>;
};
template< class T, class LessComp, class Equal >
class Iterator{
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &list) : list(list),act(list.first) {}
    bool hasNext() ;
    T next() ;
};

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    if ( act != nullptr ) {
        return true ;
    }
    return false ;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    auto aux = act->value ;
    act = act->next ;
    return aux ;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listElements(ostream &os) {
    Node* aux = first ;
    while ( aux != nullptr ){
        os << aux->value << " " ;
        aux = aux->next ;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T & what) {
//    Node* newNode = new Node(what) ;
//    Node* aux1 = first ;
//    Node* aux2 = first->next ;
//    bool ok = false ;
//    while ( aux2 != nullptr ){
//        if ( aux1->value < newNode->value && newNode->value < aux2->value ){
//            newNode->next = aux2 ;
//            aux1->next = newNode ;
//            ok = true ;
//            break ;
//        }
//    }
//    if (!ok) {
//        aux2->next = newNode ;
//    }

    Node* newNode = new Node(what) ;
    Node* prev = nullptr ;
    Node* act = first ;
    while ( act != nullptr && LessComp()(act->value , what) ) {
        prev = act ;
        act = act-> next ;
    }
    if ( prev == nullptr ){
        newNode->next = first ;
        first = newNode ;
        ++numElements ;
        return;
    }
    prev->next = newNode ;
    newNode->next = act ;
    ++numElements ;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while ( first != nullptr ) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return first == nullptr ;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &what) {
    if ( isEmpty() ){
        cout << endl << "List is empty " << endl ;
        return;
    }
    if ( Equal()(what , first->value) ){
        first = first->next ;
        --numElements;
        return;
    }

    Node* temp = first -> next;
    Node* prev = first ;

    while ( temp != nullptr ){
        if ( Equal()(temp->value,what) ) {
            prev->next = temp->next ;
            --numElements;
            return;
        }
        prev = temp ;
        temp = temp->next;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find( const T& what) {
    Node* temp = first;
    while ( temp != nullptr ){
        if ( Equal()(temp->value,what) ) {
            return true ;
        }
        temp = temp->next;
    }
    return false ;
}


#endif //MAIN_10_CPP_ORDEREDLIST_H