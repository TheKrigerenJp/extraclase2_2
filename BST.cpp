//
// Created by curso on 17/09/24.
//
#include "BST.h"

//Parte del NodeBST
int NodeBST::getDato(){
    return dato;
}
void NodeBST::setDato(int valo){
    dato = valo;
}
NodeBST* NodeBST::getIzq(){
    return izq;
}
NodeBST* NodeBST::getDer(){
    return der;
}
void NodeBST::setIzq(NodeBST* izqui){
    izq = izqui;
}
void NodeBST::setDer(NodeBST* dere){
    der = dere;
}

//Parte BST
void BST::insert(int valo) {
    raiz= insert(raiz, valo);
}

NodeBST* BST::insert(NodeBST* node, int valo) {
    if (!node) {
        return new NodeBST(valo);
    }

    if (valo < node->getDato()) {
        node->setIzq(insert(node->getIzq(), valo));
    } else if (valo > node->getDato()) {
        node->setDer(insert(node->getDer(), valo));
    }

    return node;
}

bool BST::buscar(NodeBST* node, int valo) const{
    if (!node) {
        return false;
    }
    if (valo == node->getDato()) {
        return true;
    } else if (valo < node->getDato()) {
        return buscar(node->getIzq(), valo);
    } else {
        return buscar(node->getDer(), valo);
    }

}

NodeBST* BST::getRaiz() const {
    return raiz;
}