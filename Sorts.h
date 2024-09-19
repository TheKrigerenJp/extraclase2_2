//
// Created by josepa on 18/09/24.
//

#ifndef SORTS_H
#define SORTS_H

#include <vector>

class Sorts {
public:
    void bubbleSort(std::vector<int>& input);
    void selectionSort(std::vector<int>& input);
    void mergeSort(std::vector<int>& input);

private:
    void merge(std::vector<int>& input, int left, int mid, int right);
    void mergeSortHelper(std::vector<int>& input, int left, int right);
};



#endif //SORTS_H
