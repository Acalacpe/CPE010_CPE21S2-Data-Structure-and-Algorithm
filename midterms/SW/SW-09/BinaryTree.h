#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree
{
private:
    T key;
    BinaryTree<T> *leftchild;
    BinaryTree<T> *rightchild;

public:
    BinaryTree(T rootObj);

    void insertLeftChild(T rootobj);
    void insertRightChild(T rootobj);

    BinaryTree<T> *getLeftChild();
    BinaryTree<T> *getRightChild();

    T getRootVal();
    void setRootVal(T obj);
    bool isLeaf();
};

template <typename T>
bool BinaryTree<T>::isLeaf()
{
    return leftchild == nullptr && rightchild == nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj)
{
    key = rootObj;
    leftchild = nullptr;
    rightchild = nullptr;
}

template <typename T>
void BinaryTree<T>::insertLeftChild(T newNode)
{
    if (leftchild == nullptr)
    {
        leftchild = new BinaryTree<T>(newNode);
    }
    else
    {
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
        newChild->leftchild = leftchild;
        leftchild = newChild;
    }
}

template <typename T>
void BinaryTree<T>::insertRightChild(T newNode)
{
    if (rightchild == nullptr)
    {
        rightchild = new BinaryTree<T>(newNode);
    }
    else
    {
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
        newChild->rightchild = rightchild;
        rightchild = newChild;
    }
}

template <typename T>
BinaryTree<T> *BinaryTree<T>::getLeftChild()
{
    return leftchild;
}

template <typename T>
BinaryTree<T> *BinaryTree<T>::getRightChild()
{
    return rightchild;
}

template <typename T>
T BinaryTree<T>::getRootVal()
{
    return key;
}

template <typename T>
void BinaryTree<T>::setRootVal(T obj)
{
    key = obj;
}

#endif
