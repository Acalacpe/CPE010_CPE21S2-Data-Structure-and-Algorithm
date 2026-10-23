#include <iostream>
#include "BinaryTree.h"

int main()
{
    // 1. Creating the root node:
    BinaryTree<char> *root = new BinaryTree<char>('A');
    std::cout << "Root created: " << root->getRootVal() << std::endl;

    // 2. Inserting left and right children of root:
    root->insertLeftChild('B');  // left child of A
    root->insertRightChild('C'); // right child of A
    std::cout << "Root left child: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Root right child: " << root->getRightChild()->getRootVal() << std::endl;

    // 3. Inserting children of node B:
    root->getLeftChild()->insertLeftChild('D');  // left child of B
    root->getLeftChild()->insertRightChild('E'); // right child of B
    std::cout << "Node B left child: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Node B right child: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;

    // 4. Inserting children of node C:
    root->getRightChild()->insertLeftChild('F');  // left child of C
    root->getRightChild()->insertRightChild('G'); // right child of C
    std::cout << "Node C left child: " << root->getRightChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Node C right child: " << root->getRightChild()->getRightChild()->getRootVal() << std::endl;

    // 5. Testing setRootVal (changing a node’s value):
    root->getLeftChild()->getRightChild()->setRootVal('N'); // change E → N
    std::cout << "Node B right child after setRootVal: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;

    // 6. Testing getRootVal again after modification:
    std::cout << "Root value still: " << root->getRootVal() << std::endl;

    std::cout << "Is root A a leaf? " << (root->isLeaf() ? "Yes" : "No") << std::endl;

    return 0;
}
