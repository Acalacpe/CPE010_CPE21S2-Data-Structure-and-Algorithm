#include <iostream>
#include <string>
 
class Node {
public:
    char data;
    Node* next;
};
 
class LinkedStack {
private:
    Node *head, *tail;
 
public:
    LinkedStack() {
        head = NULL;
        tail = NULL;
    }
 
    bool isEmpty() {
        return head == NULL;
    }
 
    //creates a new node and places it at the head
    void push(char newData) {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = head;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            head = newNode;
        }
    }
 
    //removes and returns the node at the head
    char pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow." << std::endl;
            return '\0';
        }
        Node *temp = head;
        char val = temp->data;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        return val;
    }
 
    char peek() {
        if (isEmpty()) return '\0';
        return head->data;
    }
 
    // Cleans up any remaining nodes
    ~LinkedStack() {
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
 
// Returns true if 'open' is the correct opening symbol for 'close'
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}
 
bool checkBalance(const std::string &expr) {
    LinkedStack stack;
 
    for (size_t i = 0; i < expr.length(); i++) {
        char ch = expr[i];
 
        // a) Ignore characters that are not elements to be balanced
        if (ch == '(' || ch == '{' || ch == '[') {
            // b) Opening element -> push onto stack
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            // c) Closing element found
            if (stack.isEmpty()) {
                // i) Report error if stack is empty
                std::cout << "Error: Closing element '" << ch
                          << "' found with no matching opening element (position "
                          << i << ")." << std::endl;
                return false;
            } else {
                // ii) Otherwise, pop the stack
                char popped = stack.pop();
                // d) If popped element doesn't correspond to closing element, report error
                if (!isMatchingPair(popped, ch)) {
                    std::cout << "Error: Mismatched elements. '" << popped
                              << "' does not match '" << ch << "' (position "
                              << i << ")." << std::endl;
                    return false;
                }
            }
        }
        // else: not a element to be balanced, ignore it
    }
 
    // 3. At the end of input, if stack is not empty, report an error
    if (!stack.isEmpty()) {
        std::cout << "Error: Unmatched opening element(s) remain on the stack."
                  << std::endl;
        return false;
    }
 
    return true;
}
 
int main() {
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D)}"
    };

    std::cout << "=== Stack using LINKED LISTS: Balanced Element Checker ===" << std::endl << std::endl;

    for (size_t i = 0; i < 4; i++) {
        std::cout << "Expression " << (i + 1) << ": " << expressions[i] << std::endl;
        bool result = checkBalance(expressions[i]);
        std::cout << "Result: " << (result ? "VALID (Balanced)" : "INVALID (Not Balanced)")
                   << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
    }
 
    return 0;
}