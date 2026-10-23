#ifndef QUEUELL_H
#define QUEUELL_H

// create a class node
template <typename T>
class qNode
{
public:
    T data;
    qNode *next;
};

// new node creator
template <typename T>
qNode<T> *new_node(T newData)
{
    // allocate a space for the new nod
    qNode<T> *newNode = new qNode<T>;

    // store the newdata to the newNode
    newNode->data = newData;

    // point the nownode to nulltptr
    newNode->next = nullptr;

    return newNode;
}
// enqueue
template <typename T>
void enqueue(T newData, qNode<T> **frontPtr, qNode<T> **backPtr)
{
    // create a new node
    qNode<T> *newNode = new_node(newData);
    // check if the quque is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr)
    {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    // if not then insert at the back
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

// dequeue
template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr)
{
    // check if the queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr)
    {
        std::cout << "The Queue is empty." << std::endl;
        return;
    }

    // create a temporary variable to store the node to be deleted
    qNode<T> *deleteTemp = nullptr;

    // assign the current front to the deleteTemp
    deleteTemp = (*frontPtr);

    // check if the queue has only 1 item
    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr)
    {
        // means only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        deleteTemp;
        return;
    }

    // check if more than 1 item in the queue
    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;

    // delete Node
    delete deleteTemp;
}

// display all
template <typename T>
void Traverse(qNode<T> **front)
{

    if ((*front) == nullptr)
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    while ((*front) != nullptr)
    {
        std::cout << (*front)->data << " ";
        (*front) = (*front)->next;
    }

    std::cout << std::endl;
}

// isEmpty
template <typename T>
bool isEmpty(qNode<T> **front, qNode<T> **back)
{
    if ((*front) == nullptr && (*back) == nullptr)
    {
        return true;
    }

    return false;
}

template <typename T>
void checker(qNode<T> **front, qNode<T> **back)
{
    if ((*front)->data == (*back)->data)
    {
        std::cout << "Symmetrical" << std::endl;
    }

    else
    {
        std::cout << "Not Symmetrical" << std::endl;
    }
}

#endif