#include <iostream>
#include <string>
#include "circular_doubly_ll.h"

// Main Program
int main() {

    // Creating initial playlist nodes
    DoubleList<std::string>* head = CreateNewNode(std::string("Twice - Yes or Yes"));
    DoubleList<std::string>* second = CreateNewNode(std::string("Twice - What Is Love?"));
    DoubleList<std::string>* third = CreateNewNode(std::string("Twice - Look At Me Now"));
    DoubleList<std::string>* fourth = CreateNewNode(std::string("Twice - The Feels"));

    // Manual circular linking: fourth->next goes back to head, head->prev points to fourth
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // Circular link

    head->prev = fourth; // Circular link
    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    std::cout << "Try playlist traversal:\n";
    dllListTraversal(head);
    std::cout << std::endl;

    std::cout << "Try inserting song at head:\n";
    dllInsertHead(std::string("Twice - Signal"), head);
    dllListTraversal(head);
    std::cout << std::endl;

    std::cout << "Try inserting song at tail:\n";
    dllInsertTail(std::string("Twice - Heart Shaker"), head);
    dllListTraversal(head);
    std::cout << std::endl;

    std::cout << "Try general insert after 3rd node:\n";
    dllGeneralInsert(std::string("Twice - Likey"), head->next->next);
    dllListTraversal(head);
    std::cout << std::endl;

    std::cout << "Try deleting 'Twice - Likey':\n";
    dllDeleteNode(std::string("Twice - Likey"), head);
    dllListTraversal(head);
    std::cout << std::endl;


    return 0;
}