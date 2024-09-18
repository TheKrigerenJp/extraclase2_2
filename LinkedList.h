//
// Created by josepa on 18/09/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class NodeLL {
private:
    int dato;
    NodeLL* nextt;
public:
    NodeLL(int valo) : dato(valo), nextt(nullptr) {}
    int getDato();
    void setDato(int valo);
    NodeLL* getNext();
    void setNext(NodeLL* nextt);
};

class LinkedList {
private:
    NodeLL* head;
    int i;

public:
    LinkedList() : head(nullptr), i(0) {}
    ~LinkedList();
    int getPos(int posicion);
    void setPos(int posicion, int valo);
    void append(int valo);
    void deleteNode(int posicion);

};
#include "LinkedList.cpp"
#endif //LINKEDLIST_H
