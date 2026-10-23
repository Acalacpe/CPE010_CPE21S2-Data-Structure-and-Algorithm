#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"

const int max_size = 50;

int main() {

    /*
    int dataset[max_size];

    srand(time(0));

    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "What number to find: ";
    int choice;

    std::cin >> choice;

    linearSearchAR(max_size, choice, dataset);

    return 0;

    

    Node<char> *char1 = newNode('M');
    Node<char> *char2 = newNode('A');
    Node<char> *char3 = newNode('T');
    Node<char> *char4 = newNode('T');

    char1->next = char2;
    char2->next = char3;
    char3->next = char4;

    // Searching for a letter that exists in the list
    linearSearchLL(char1, 'T');
    
    // Searching for a letter that does not exist in the list
    linearSearchLL(char1, 'S');

    return 0;

    

    int Arr1[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < max_size; i++) {
        Arr1[i] = i;
    }

    binarysearchArr(Arr1, 10, 11);

    int Arr2[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < max_size; i++) {
        Arr2[i] = i;
    }

    binarysearchArr(Arr2, 10, 1);

    return 0;

    */

    // ===== Binary Search Linked List =====

    Node<char> *char1 = newNode('M');
    Node<char> *char2 = newNode('A');
    Node<char> *char3 = newNode('T');
    Node<char> *char4 = newNode('T');

    char1->next = char2;
    char2->next = char3;
    char3->next = char4;
    char4->next = nullptr;

    binarySearchLL(char1, 'T');
    binarySearchLL(char1, 'M');

    return 0;
}