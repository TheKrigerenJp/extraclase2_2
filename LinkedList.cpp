//
// Created by josepa on 18/09/24.
//

#include "LinkedList.h"

//Parte del NodeLL
int NodeLL::getDato(){
    return dato;
}

void NodeLL::setDato(int valor){
    dato = valor;
}

NodeLL* NodeLL::getNext(){
    return nextt;
}
void NodeLL::setNext(NodeLL* next){
    nextt = next;
}

//Parte de LinkedList
LinkedList::~LinkedList() {
    NodeLL* actual = head;
    while (actual) {
        NodeLL* siguiente = actual->getNext();
        delete actual;
        actual = siguiente;
    }
}

int LinkedList::getPos(int posicion) {

    NodeLL* actual = head;
    int pos = 0;
    while (actual) {
        if(pos == posicion) {
            return actual->getDato();
        }else {
            NodeLL* siguiente = actual->getNext();
            actual = siguiente;
            pos++;
        }

    }
    return -1;
}

void LinkedList::setPos(int posicion, int valo) {

    NodeLL* actual = head;
    int pos = 0;
    while (actual) {
        if(pos == posicion) {
            actual->setDato(valo);
            return;
        }else {
            NodeLL* siguiente = actual->getNext();
            actual = siguiente;
        }
    }
}

void LinkedList::append(int valo) {
    if (!head) {
        head = new NodeLL(valo);
        return;
    }


    NodeLL* actual = head;
    while (actual->getNext()) {
        actual = actual->getNext();
    }

    actual->setNext(new NodeLL(valo));
}

void LinkedList::deleteNode(int posicion) {
    if (posicion < 0 || !head) {
        return;
    }

    if (posicion == 0) {
        NodeLL* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }

    NodeLL* actual = head;
    NodeLL* anterior = nullptr;
    int contador = 0;

    while (actual && contador < posicion) {
        anterior = actual;
        actual = actual->getNext();
        contador++;
    }

    if (!actual) {
        return;
    }
    anterior->setNext(actual->getNext());
    delete actual;
    actual = nullptr;
}
