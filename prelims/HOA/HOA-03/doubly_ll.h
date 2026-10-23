#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev;
    DoubleList<T>* next;
};


//Creating new node data
template <typename T>
DoubleList<T>* CreateNewNode(T NewData){
    DoubleList<T> *NewNode = new DoubleList<T>;

    NewNode->data = NewData;
    NewNode->next = nullptr;
    NewNode->prev = nullptr;

    return NewNode;
}

template <typename T>
void dllListTraversal(DoubleList<T>* head) {

    DoubleList<T> *tail;

    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << " ";
        tail = head;
        head = head->next;
    }
    std::cout << std::endl;
    std::cout << "Backward: ";
    while(tail != nullptr){
        std::cout<< tail->data<<" ";
        tail = tail->prev;
    }

}

//inserting at head
template <typename T>
void dllInsertHead(T NewData, DoubleList<T>*& head){
    DoubleList<T> *NewNode = CreateNewNode(NewData);

    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode; 
}

//inserting at tail
template <typename T>
void dllInsertTail(T NewData, DoubleList<T>*& head){
    DoubleList<T>* NewNode = CreateNewNode(NewData);

    if (head == nullptr) {
        head = NewNode;
        return;
    }

    DoubleList<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = NewNode;
    NewNode->prev = current;
}


//general insert

template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous value cannot be null!" << std::endl;
        return;
    }
    DoubleList<T>* newNode = new DoubleList<T>();
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    // Fix the next node's prev pointerr
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}


//delete node
template <typename T>
void dllDeleteNode(T data, DoubleList<T>*& head) {
    if (head == nullptr) return;

    DoubleList<T>* temp = head;

    // search for the node
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }

    // Node wasn't found in the list
    if (temp == nullptr) return;

    // deleting the head
    if (temp == head) {
        head = temp->next;
    }

    // deleting a middle or tail node
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    // deleting the tail node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    // deleting the node
    delete temp;
}

#endif