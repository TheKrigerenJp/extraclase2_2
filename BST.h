//
// Created by curso on 17/09/24.
//

class NodeBST {
private:
    int dato;
    NodeBST* izq;
    NodeBST* der;
public:
    NodeBST(int valo) : dato(valo), izq(nullptr), der(nullptr) {}
    int getDato();
    void setDato(int valo);
    NodeBST* getIzq();
    NodeBST* getDer();
    void setIzq(NodeBST* next);
    void setDer(NodeBST* next);
};


class BST {
private:
    NodeBST* raiz;
    NodeBST* insert(NodeBST* nodo, int valo);

public:
    BST() : raiz(nullptr) {}
    void insert(int valo);
    bool buscar(NodeBST* nodo, int valo) const;
    NodeBST* getRaiz() const;
};

#include "BST.cpp"
#ifndef BST_H
#define BST_H

#endif //BST_H
