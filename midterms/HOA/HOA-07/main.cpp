#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgo.h"

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int MAX_SIZE = 100;
    int unsortedArray[MAX_SIZE];

    srand(time(0)); 

    for (int i = 0; i < MAX_SIZE; i++) {
        unsortedArray[i] = std::rand() % 100; // Random numbers between 0 and 999
    }

    std::cout << "Unsorted Array:" << std::endl;
    displayArray(unsortedArray, MAX_SIZE);

    bubbleSort(unsortedArray, MAX_SIZE);

    std::cout << "Sorted Array:" << std::endl;
    displayArray(unsortedArray, MAX_SIZE);

    std::cout << "Selection Sort:" << std::endl;
    displayArray(unsortedArray, MAX_SIZE);
    std::cout << "Selection sort passes done: " << selectionSort(unsortedArray, MAX_SIZE) << std::endl;

    std::cout << "Insertion Sort:" << std::endl;
    insertionSort(unsortedArray, MAX_SIZE);
    displayArray(unsortedArray, MAX_SIZE);

    
    return 0;
}