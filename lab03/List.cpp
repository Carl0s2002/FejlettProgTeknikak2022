//
// Created by fodor.laszlo.carlos on 10/5/2022.
//

#include "List.h"

List::List() {
    cout << "Konstruktor(lista)!" << endl ;
    this->first = nullptr ;
}

void List::insertFirst(int d) {
//    Node * temp = new Node( d , first ) ;
//    first = temp ;
    this->first = new Node( d , first ) ;
    ++this->nodeCounter ;
}

void List::print() const {
    cout << "[" ;
    for ( Node *ptr = this->first ; ptr != nullptr ; ptr = ptr->next ) {
        cout << ptr->value << " " ;
    }
    cout << "]" << endl ;
}

List::~List() {
   cout << "Destruktor(lista)!" ;
//    Node* act = this->first ;
//    while ( act != nullptr ){
//        Node * temp = act->next ;
//        act =act->next ;
//        delete temp ;
//    }
    while ( first != nullptr ){
        Node *temp = first ;
        first = first->next ;
        delete temp ;
    }
    this->nodeCounter = 0 ;
}

bool List::exists(int d) const {
    Node* temp = this->first ;
    while ( temp != nullptr ){
        if ( temp->value == d ){
            return true;
        }
        temp = temp->next ;
    }
    delete temp ;
    return false ;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    if ( this->first == nullptr ){
        return true ;
    }
    return false ;
}

int List::removeFirst() {
    if ( this->empty() ) {
        return -1 ;
    }
    int helper = this->first->value ;
    this->first = this->first->next ;
    nodeCounter-- ;
    return helper ;
}

void List::remove(int d, List::DeleteFlag df) {
    switch (df) {
        case DeleteFlag::LESS:{
            Node* temp = this->first ;
            Node* seged = this->first;
            if ( temp->value < d ){
                cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                removeFirst();
                break;
            }
            temp = temp->next ;
            while( temp->next != nullptr ){
                if ( temp->value < d ) {
                    cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                    seged->next = temp->next ;
                    delete temp ;
                    nodeCounter-- ;
                    break;
                }
                seged = seged->next ;
                temp = temp->next ;
            }
            break;
        }
        case DeleteFlag::EQUAL:{
                    Node* temp = this->first ;
                    Node* seged = this->first;
                    if ( temp->value == d ){
                        cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                        removeFirst();
                        break;
                    }
                    temp = temp->next ;
                    while( temp->next != nullptr ){
                        if ( temp->value == d ) {
                            cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                            seged->next = temp->next ;
                            delete temp ;
                            nodeCounter-- ;
                            break;
                        }
                        seged = seged->next ;
                        temp = temp->next ;
                    }
                    break;
        }
        case DeleteFlag::GREATER:{
            Node* temp = this->first ;
            Node* seged = this->first;
            if ( temp->value > d ){
                cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                removeFirst();
                break;
            }
            temp = temp->next ;
            while( temp->next != nullptr ){
                if ( temp->value > d ) {
                    cout << "A " << temp->value << "-es/as/os ertek ki lett torolve a listabol!" << endl;
                    seged->next = temp->next ;
                    delete temp ;
                    nodeCounter-- ;
                    break;
                }
                seged = seged->next ;
                temp = temp->next ;
            }
            break;
        }
    }

}

int List::number( int i ) {
    Node *temp = this->first ;
    while ( i != 0 ) {
        temp = temp->next ;
        i-- ;
    }
    return temp->value ;
}

