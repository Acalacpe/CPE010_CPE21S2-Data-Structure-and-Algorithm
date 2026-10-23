#include <iostream>
#include <string>
#include <cstring>

const int MAX_SIZE = 100;

class ArrayStack {
private:
    char items[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    //places a new element on top of the stack
    void push(char symbol) {
        if (isFull()) {
            std::cout << "Stack Overflow." << std::endl;
            return;
        }
        items[++top] = symbol;
    }

    //removes and returns the element at the top
    char pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow." << std::endl;
            return '\0';
        }
        return items[top--];
    }

    // Peek at the top element without removing it
    char peek() {
        if (isEmpty()) return '\0';
        return items[top];
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
    ArrayStack stack;

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
        // else: not a symbol to be balanced, ignore it
    }

    // 3. At the end of input, if stack is not empty, report an error
    if (!stack.isEmpty()) {
        std::cout << "Error: Unmatched opening symbol(s) remain on the stack."
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

    std::cout << "=== Stack using ARRAYS: Balanced Symbol Checker ===" << std::endl << std::endl;

    for (size_t i = 0; i < 4; i++) {
        std::cout << "Expression " << (i + 1) << ": " << expressions[i] << std::endl;
        bool result = checkBalance(expressions[i]);
        std::cout << "Result: " << (result ? "VALID (Balanced)" : "INVALID (Not Balanced)")
                   << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
    }

    return 0;
}