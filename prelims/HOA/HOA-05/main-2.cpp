#include <iostream>
#include "queueArr.h"

int main() {

    QueueArr<int> queue(5); // Create a queue of integers with capacity 5

    std::cout << "Testing Empty()" << std::endl;
    std::cout << "Queue Empty? " << (queue.Empty() ? "Yes" : "No") << std::endl;

    std::cout<< "\n Testing Enqueue() " << std::endl;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    std::cout << "Queue Size: " << queue.Size() << std::endl;
    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;

    std::cout << "\n Testing Full()" << std::endl;
    std::cout << "Queue Full? " << (queue.Full() ? "Yes" : "No") << std::endl;

    std::cout << "\n Testing Dequeue()" << std::endl;
    std::cout << "Dequeued: " << queue.Dequeue() << std::endl;
    std::cout << "dequeued: " << queue.Dequeue() << std::endl;

    std::cout << "Queue Size: " << queue.Size() << std::endl;
    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;

    std::cout << "\n Testing Clear()" << std::endl;
    std::cout << "Size before clear(): " << queue.Size() << std::endl;

    queue.Clear();

    std::cout << "Size after clear(): " << queue.Size() << std::endl;
    std::cout << "Queue Empty? " << (queue.Empty() ? "Yes" : "No") << std::endl;

    std::cout << "\n Testing Copy Constructor" << std::endl;
    QueueArr<int> queue2(5);

    queue2.Enqueue(1);
    queue2.Enqueue(2);
    queue2.Enqueue(3);

    QueueArr<int> copiedQueue(queue2); // Use the copy constructor

    std::cout << "Copied Queue Size: " << copiedQueue.Size() << std::endl;
    std::cout << "Copied Queue Front: " << copiedQueue.front() << std::endl;
    std::cout << "Copied Queue Back: " << copiedQueue.back() << std::endl;

    std::cout << "\n Testing Copy Assignment Operator" << std::endl;
    QueueArr<int> assignedQueue(5);
    assignedQueue = queue2; // Use the copy assignment operator

    std::cout << "Assigned Queue Size: " << assignedQueue.Size() << std::endl;
    std::cout << "Assigned Queue Front: " << assignedQueue.front() << std::endl;
    std::cout << "Assigned Queue Back: " << assignedQueue.back() << std::endl;

    return 0;   
}