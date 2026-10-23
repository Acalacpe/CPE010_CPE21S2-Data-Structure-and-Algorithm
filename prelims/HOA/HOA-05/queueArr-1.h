#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>
#include <cstddef>

//array-based circular queue

template <typename T>
class QueueArr {
private:

    //pointer to dynamically allocate array
    T* q_array;

    //variable for maximum number of elements in the queue
    size_t q_capacity;

    //current number of the elements in the queue
    size_t q_size;

    //index of the front element
    int q_front;

    //index of the rear element
    int q_rear;

public:

    //construcator
    QueueArr(size_t capacity = 10);

    //copy-constructor
    QueueArr(const QueueArr& other);

    //copy assignment operator
    QueueArr& operator=(const QueueArr& other);

    //deconstructor
    ~QueueArr();

    //queue operations:
    bool Empty();
    bool Full();

    size_t Size();

    void Clear();

    T front();
    T back();

    void Enqueue(T value);
    T Dequeue();
};

// contructor

template <typename T>
QueueArr<T>::QueueArr(size_t capacity) {
    q_capacity = capacity; //set the capacity of the queue
    q_array = new T[q_capacity]; //dynamically allocate an array of size capacity
    q_size = 0; //initialize the size of the queue to 0
    q_front = 0; //initialize the front index to 0
    q_rear = -1; //initialize the rear index to -1
}

// Copy-constructor

template <typename T>
QueueArr<T>::QueueArr(const QueueArr& other) {
    q_capacity = other.q_capacity; //copy the capacity from the other queue
    q_size = other.q_size; //copy the size from the other queue
    q_front = other.q_front; //copy the front index from the other queue
    q_rear = other.q_rear; //copy the rear index from the other queue

    //dynamically allocate a new array and copy the elements from the other queue
    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}

// Copy assignment operator

template <typename T>
QueueArr<T>& QueueArr<T>::operator=(const QueueArr& other) {

    if (this != &other) { //check for self-assignment

        delete[] q_array; //delete the current array

        q_capacity = other.q_capacity; //copy the capacity from the other queue
        q_size = other.q_size; //copy the size from the other queue
        q_front = other.q_front; //copy the front index from the other queue
        q_rear = other.q_rear; //copy the rear index from the other queue

        //dynamically allocate a new array and copy the elements from the other queue
        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }

    return *this; //return the current object
}

// Deconstructor

template <typename T>
QueueArr<T>::~QueueArr() {
    delete[] q_array; //delete the dynamically allocated array
}

// empty{}

template <typename T>
bool QueueArr<T>::Empty() {
    return q_size == 0; //check if the queue is empty
}

// full {}

template <typename T>
bool QueueArr<T>::Full() {
    return q_size == q_capacity; // check if the queue is full
}

// size_T

template <typename T>
size_t QueueArr<T>::Size() {
    return q_size; //return the current size of the queue
}

// clear

template <typename T>
void QueueArr<T>::Clear() {
    q_size = 0; //reset the size of the queue to 0
    q_front = 0; //reset the front index to 0
    q_rear = -1; //reset the rear index to -1
}

// front

template <typename T>
T QueueArr<T>::front() {

    if (Empty()) {
        std::cout << "Queue is Empty.\n";
        return T(); //return default value of T if the queue is empty
    }

    return q_array[q_front]; //return the front element of the queue
}

// back

template <typename T>
T QueueArr<T>::back() {

    if (Empty()) {
        std::cout << "Queue is Empty.\n";
        return T(); //return default value of T if the queue is empty
    }

    return q_array[q_rear]; //return the rear element of the queue
}

// enqueue

template <typename T>
void QueueArr<T>::Enqueue(T value) {

    // Check if the queue is full
    if (Full()) {
        std::cout << "Queue is Full.\n";
        return;
    }

    // Move the rear to the next position
    if (q_rear == q_capacity - 1)
        q_rear = 0;
    else
        q_rear++;

    // Store the new value at the rear
    q_array[q_rear] = value;

    // Increment the queue size
    q_size++;
}

// dequeue

template <typename T>
T QueueArr<T>::Dequeue() {

    if (Empty()) {
        std::cout << "Queue is Empty.\n";
        return T();
    }

    // create a temporary variable to store the current front
    T temp = q_array[q_front];

    // move q_front circularly
    if (q_front == q_capacity - 1)
        q_front = 0;
    else
        q_front++;

    // decrement the q_size
    q_size--;

    // reset the indexes if the queue becomes empty
    if (Empty())
        Clear();

    // return the temporary variable
    return temp;
}

#endif