#ifndef CIRCULAR_DOUBLY_LL_H
#define CIRCULAR_DOUBLY_LL_H

template <typename T>
class DoubleList {
public:
    T data;
    DoubleList<T>* prev;
    DoubleList<T>* next;
};

// Creating new node data
template <typename T>
DoubleList<T>* CreateNewNode(T NewData) {
    DoubleList<T>* NewNode = new DoubleList<T>;
    NewNode->data = NewData;
    NewNode->next = nullptr;
    NewNode->prev = nullptr;
    return NewNode;
}

// Circular Traversal (Forward & Backward)
template <typename T>
void dllListTraversal(DoubleList<T>* head) {
    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    std::cout << "\n========== PLAYLIST ==========\n";

    // Forward
    std::cout << "\nForward:\n";
    DoubleList<T>* current = head;
    int count = 1;

    do {
        std::cout << "[" << count++ << "] " << current->data << '\n';
        current = current->next;
    } while (current != head);

    std::cout << "\n=======Loops back to the first song=======\n";

    // Backward
    std::cout << "\nBackward:\n";
    current = head->prev;
    count--;

    do {
        std::cout << "[" << count-- << "] " << current->data << '\n';
        current = current->prev;
    } while (current != head->prev);

    std::cout << "\n=======Loops back to the last song=======\n";
}

// Inserting at head
template <typename T>
void dllInsertHead(T NewData, DoubleList<T>*& head) {
    DoubleList<T>* NewNode = CreateNewNode(NewData);

    if (head == nullptr) {
        head = NewNode;
        head->next = head;
        head->prev = head;
        return;
    }

    DoubleList<T>* tail = head->prev;

    NewNode->next = head;
    NewNode->prev = tail;
    head->prev = NewNode;
    tail->next = NewNode;
    head = NewNode;
}

// Inserting at tail
template <typename T>
void dllInsertTail(T NewData, DoubleList<T>*& head) {
    DoubleList<T>* NewNode = CreateNewNode(NewData);

    if (head == nullptr) {
        head = NewNode;
        head->next = head;
        head->prev = head;
        return;
    }

    DoubleList<T>* tail = head->prev;

    tail->next = NewNode;
    NewNode->prev = tail;
    NewNode->next = head;
    head->prev = NewNode;
}

// General Insert after a given node
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null!" << std::endl;
        return;
    }

    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

// Delete node by value
template <typename T>
void dllDeleteNode(T data, DoubleList<T>*& head) {
    if (head == nullptr) return;

    DoubleList<T>* temp = head;

    // Search for the node in circular list
    while (temp->data != data) {
        temp = temp->next;
        if (temp == head) {
            std::cout << "Song \"" << data << "\" not found!" << std::endl;
            return;
        }
    }

    // Only one node in the list
    if (temp->next == temp) {
        head = nullptr;
        delete temp;
        return;
    }

    // Unlink the node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    // If deleting head, move head pointer to next node
    if (temp == head) {
        head = temp->next;
    }

    delete temp;
}

#endif