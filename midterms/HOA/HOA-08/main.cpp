#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort_algorithms.h"

int main() {
    // Seed for random number generation
    std::srand(std::time(0));
    
    // Create an array of elements with random values containing 100 elements
    int originalArr[100];
    for (int i = 0; i < 100; i++) {
        originalArr[i] = std::rand() % 1000; // Random values up to 999
    }

    //Preparation Task Output
    std::cout << "--- Array of Values for Sort Algorithm Testing ---" << std::endl;
    std::cout << "Unsorted Array:" << std::endl;
    printArray(originalArr, 100);
    std::cout << "\n";

    //Shell Sort
    int shellArr[100];
    for (int i = 0; i < 100; i++) shellArr[i] = originalArr[i];
    std::cout << "--- Shell Sort Technique ---" << std::endl;
    shellSort(shellArr, 100);
    printArray(shellArr, 100);
    std::cout << "\n";

    //Merge Sort
    int mergeArr[100];
    for (int i = 0; i < 100; i++) mergeArr[i] = originalArr[i];
    std::cout << "---Merge Sort Algorithm ---" << std::endl;
    merge_sort(mergeArr, 0, 99);
    printArray(mergeArr, 100);
    std::cout << "\n";

    //Quick Sort
    int quickArr[100];
    for (int i = 0; i < 100; i++) quickArr[i] = originalArr[i];
    std::cout << "--- Quick Sort Algorithm ---" << std::endl;
    quicksort(quickArr, 0, 99);
    printArray(quickArr, 100);

    return 0;
}