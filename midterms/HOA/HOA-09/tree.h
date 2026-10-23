#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class Tree {
public:
    // create a key
    T key;

    // pointers for the left and right children
    Tree<T>* leftChild;
    Tree<T>* rightChild;

    // constructor
    Tree(T value);

    // traversing
    void preOrder();
    void inOrder();
    void postOrder();

    // searching
    bool findData(T value, int choice);
};

template <typename T>
Tree<T>::Tree(T value) {
    key = value;
    leftChild = nullptr;
    rightChild = nullptr; 
}

template <typename T>
void Tree<T>::preOrder() {
    std::cout << key << " ";
    if (leftChild != nullptr) {
        leftChild->preOrder();
    }
    if (rightChild != nullptr) {
        rightChild->preOrder();
    }
}

template <typename T>
void Tree<T>::inOrder() {
    if (leftChild != nullptr) {
        leftChild->inOrder();
    }
    std::cout << key << " ";
    if (rightChild != nullptr) {
        rightChild->inOrder();
    }
}

template <typename T>
void Tree<T>::postOrder() {
    if (leftChild != nullptr) {
        leftChild->postOrder();
    }
    std::cout << key << " ";
    if (rightChild != nullptr) {
        rightChild->postOrder();
    }
}

template <typename T>
bool Tree<T>::findData(T value, int choice) {
    if (choice == 1) { // Preorder
        if (key == value) {
            std::cout << value << " was found!" << std::endl;
            return true;
        }
        if (leftChild != nullptr && leftChild->findData(value, choice)) return true;
        if (rightChild != nullptr && rightChild->findData(value, choice)) return true;
    }
    else if (choice == 2) { // Inorder
        if (leftChild != nullptr && leftChild->findData(value, choice)) return true;
        if (key == value) {
            std::cout << value << " was found!" << std::endl;
            return true;
        }
        if (rightChild != nullptr && rightChild->findData(value, choice)) return true;
    }
    else if (choice == 3) { // Postorder
        if (leftChild != nullptr && leftChild->findData(value, choice)) return true;
        if (key == value) {
            std::cout << value << " was found!" << std::endl;
            return true;
        }
        if (rightChild != nullptr && rightChild->findData(value, choice)) return true;
    }
    return false;
}

#endif