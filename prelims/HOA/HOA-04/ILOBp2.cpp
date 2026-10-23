#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class Stack {
private:
    Node<T> *head, *tail;

public:
    Stack() {
        head = NULL;
        tail = NULL;
    }

    //adds a new element to the top of the stack
    void push(T newData) {
        Node<T> *newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = head;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    //removes and returns the top element of the stack
    T pop() {
        T tempVal;
        Node<T> *temp;
        if (head == NULL) {
            std::cout << "Stack Underflow." << std::endl;
            return T(); // returns default value of type T (0, '\0', "" etc.)
        } else {
            temp = head;
            tempVal = temp->data;
            head = head->next;
            if (head == NULL) tail = NULL; // reset tail if stack becomes empty
            delete temp;
            return tempVal;
        }
    }

    //displays the current top element without removing it
    void Top() {
        if (head == NULL) {
            std::cout << "Stack is Empty." << std::endl;
            return;
        } else {
            std::cout << "Top of Stack: " << head->data << std::endl;
        }
    }

    //traverses and prints all elements currently in the stack
    void display() {
        if (head == NULL) {
            std::cout << "Stack is Empty." << std::endl;
            return;
        }
        std::cout << "Stack elements (top to bottom): ";
        Node<T> *current = head;
        while (current != NULL) {
            std::cout << current->data;
            if (current->next != NULL) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //cleans up remaining nodes to avoid memory leaks
    ~Stack() {
        while (head != NULL) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    std::cout << "\n=== Char Stack ===" << std::endl;
    Stack<char> Stack;
    Stack.push('T');
    Stack.push('T');
    Stack.push('A');
    Stack.push('M');
    Stack.Top();
    Stack.display();
    Stack.pop();
    Stack.display();

    return 0;
}