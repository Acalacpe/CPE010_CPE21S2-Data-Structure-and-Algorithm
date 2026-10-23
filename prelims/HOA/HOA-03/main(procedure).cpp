#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

// Main Program
int main() {
    
    //creating list for my name
    DoubleList<char>* head = CreateNewNode('1');
    DoubleList<char>* second = CreateNewNode('2');
    DoubleList<char>* third = CreateNewNode('3');
    DoubleList<char>* fourth = CreateNewNode('4');


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;
    head->prev = nullptr;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    std::cout<<"Try traversal: ";
    dllListTraversal(head);

    std::cout<<std::endl;

    std::cout<<"Try inserting at head: ";
    dllInsertHead('0', head);
    dllListTraversal(head);
    
    std::cout<<std::endl;
    
    std::cout<<"Trying Insert at tail: ";
    dllInsertTail('5', head);
    dllListTraversal(head);
    
    std::cout<<std::endl;

    std::cout<<"Trying Insert at 3rd node: ";
    dllGeneralInsert('A', head->next->next);
    dllListTraversal(head);

    std::cout<<std::endl;

    std::cout<<"Trying deleting 'A': ";
    dllDeleteNode('A', head);
    dllListTraversal(head);

    return 0;

}
