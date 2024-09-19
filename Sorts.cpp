//
// Created by josepa on 18/09/24.
//

#include "Sorts.h"

void Sorts::bubbleSort(std::vector<int> & input) {
    int n = input.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j], input[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


void Sorts::selectionSort(std::vector<int> & input) {
    int n = input.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (input[j] < input[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(input[i], input[minIdx]);
    }
}

void Sorts::mergeSort(std::vector<int> & input){
    mergeSortHelper(input, 0, input.size() - 1);
}

void Sorts::merge(std::vector<int> & input, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = input[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = input[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            input[k] = L[i];
            ++i;
        } else {
            input[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        input[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        input[k] = R[j];
        ++j;
        ++k;
    }
}

void Sorts::mergeSortHelper(std::vector<int>& input, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(input, left, mid);
        mergeSortHelper(input, mid + 1, right);
        merge(input, left, mid, right);
    }
}