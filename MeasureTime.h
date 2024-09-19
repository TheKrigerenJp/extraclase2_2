//
// Created by josepa on 18/09/24.
//

#ifndef MEASURETIME_H
#define MEASURETIME_H


#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdexcept>
#include "Sorts.h"
#include "LinkedList.h"
#include "BST.h"

using namespace std;
class MeasureTime {
public:

    double measureTime(const std::string& func, std::vector<int>& data, int caso) {
        Sorts sorters;
        LinkedList assearch;
        BST bst;

        auto start = std::chrono::high_resolution_clock::now();  // Definir start antes de los ifs
        auto end = start;  // Inicializar end también para evitar el uso de variables sin inicializar

        // Seleccionar el algoritmo basado en 'func'
        if (func == "BubbleSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.bubbleSort(data);
        }
        else if (func == "SelectionSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.selectionSort(data);
        }
        else if (func == "MergeSort") {
            start = std::chrono::high_resolution_clock::now();
            sorters.mergeSort(data);
        }
        else if (func == "AllSortedLinkedListSearch") {
            if(caso == 2) {
                reverse(data.begin(), data.end());
            }else if (caso == 3) {
                sort(data.begin(), data.end());
            }
            start = std::chrono::high_resolution_clock::now();

            int a;
            if(caso == 1) {
                a = 1;
            }else if(caso == 2) {
                a = data.size()-1;
            }else {
                a = data[data.size()/2];
            }
            assearch.search(data, a);
        }
        else if (func == "BinaryTreeSearch") {
            NodeBST* root = new NodeBST(data.size());
            for (int i : data) {
                bst.insert( i);
            }
            start = std::chrono::high_resolution_clock::now();
            int a;
            if(caso == 1) {
                a = 0;
            }else if(caso == 2) {
                a = 0;
            }else {
                a = data.size()/2;
            }
            bst.insert( a);
            delete root;
        }
        else {
            throw std::invalid_argument("Error: El algoritmo '" + func + "' no es válido.");  // Lanzar excepción en caso de no coincidir con ningún algoritmo
        }

        // Medir tiempo
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }
};
#endif //MEASURETIME_H
