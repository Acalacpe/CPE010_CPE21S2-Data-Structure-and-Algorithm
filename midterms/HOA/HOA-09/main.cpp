#include <iostream>
#include "Tree.h"

int main() {
    Tree<char>* A = new Tree<char>('A');
    Tree<char>* B = new Tree<char>('B');
    Tree<char>* C = new Tree<char>('C');
    Tree<char>* D = new Tree<char>('D');
    Tree<char>* E = new Tree<char>('E');
    Tree<char>* F = new Tree<char>('F');
    Tree<char>* G = new Tree<char>('G');
    Tree<char>* H = new Tree<char>('H');
    Tree<char>* I = new Tree<char>('I');
    Tree<char>* J = new Tree<char>('J');
    Tree<char>* K = new Tree<char>('K');
    Tree<char>* L = new Tree<char>('L');
    Tree<char>* M = new Tree<char>('M');
    Tree<char>* N = new Tree<char>('N');
    Tree<char>* P = new Tree<char>('P');
    Tree<char>* Q = new Tree<char>('Q');

    A->leftChild = B;
    B->rightChild = C;
    C->rightChild = D;
    D->rightChild = E;
    E->rightChild = F;
    F->rightChild = G;

    D->leftChild = H;
    E->leftChild = I;
    I->rightChild = J;
    F->leftChild = K;
    K->rightChild = L;
    L->rightChild = M;
    G->leftChild = N;
    
    J->leftChild = P;
    P->rightChild = Q;

    std::cout << "Preorder: ";
    A->preOrder();

    std::cout << "\nInorder: ";
    A->inOrder();

    std::cout << "\nPostorder: ";
    A->postOrder();
    std::cout << "\n\n";

    A->findData('E', 1); 
    A->findData('G', 2); 
    A->findData('Z', 3); 

    Tree<char>* O = new Tree<char>('O');
    N->rightChild = O;

    std::cout << "\nAfter adding O:\n";
    std::cout << "Preorder: ";
    A->preOrder();
    
    std::cout << "\nInorder: ";
    A->inOrder();
    
    std::cout << "\nPostorder: ";
    A->postOrder();
    std::cout << "\n\n";

    A->findData('O', 1); 

    return 0;
}