#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <cstddef>
#include <iostream>

// Function to perform bubble sort on an array
template <typename T>
void bubbleSort(T arr[], std::size_t n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T>
//array, size of array, starting index
int routineSmallest(T arr[], std::size_t n, int startIndex) {
    int minIndex = startIndex;
    for (int i = startIndex + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

//sorting algorithm that uses the routineSmallest function to sort an array
template <typename T>
std::size_t selectionSort(T arr[], std::size_t n) {
    std::size_t passCount = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = routineSmallest(arr, n, i);
        std::swap(arr[i], arr[minIndex]);
        passCount++;
    }

    return passCount;
}

template <typename T>
void insertionSort(T arr[], std::size_t n) {
    int K = 0;
    int j;
    T temp;

    while (K < n) {
        temp = arr[K];
        j = K - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        K++;
    }
}

template <typename T>
void insertionSortArray(T arr[], std::size_t n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

#endif