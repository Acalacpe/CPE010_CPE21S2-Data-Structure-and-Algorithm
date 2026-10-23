#include <iostream>
#include <stack>

int main() {

    std::stack<int> stack1, stack2;
    std::cout<<"Testing the stack STL\n";

    //is empty
    std::cout<<"Is the stack empty? " << stack1.empty() << std::endl;

    //push 
    std::cout<<"========STACK 1========" << std::endl;
    stack1.push(10);
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;

    stack1.push(9);
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;

    stack1.push(8);
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;

    stack1.push(7);
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;

    stack1.push(6);
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;

    //pop
    std::cout<<"Testing the pop: " <<  stack1.top() << std::endl;
    stack1.pop();
    std::cout<<"The top stack is " <<  stack1.top() << std::endl;
    std::cout<<"Size of the stack: " << stack1.size() << std::endl;

    //emplace
    stack1.emplace(69420);
    std::cout<<"The top stack is " << stack1.top() << std::endl;

    //stack 2 to use swap
    std::cout<<"========STACK 2========" << std::endl;
    stack2.push(1);
    std::cout<<"The top stack is " <<  stack2.top() << std::endl;

    stack2.push(2);
    std::cout<<"The top stack is " <<  stack2.top() << std::endl;

    stack2.push(3);
    std::cout<<"The top stack is " <<  stack2.top() << std::endl;

    stack2.push(4);
    std::cout<<"The top stack is " <<  stack2.top() << std::endl;

    stack2.push(5);
    std::cout<<"The top stack is " <<  stack2.top() << std::endl;

    //swap
    stack1.swap(stack2);

    //display entire stack 1
    std::cout<<"========STACK 1========" << std::endl;
    std::cout<<"Displaying Entire Stack1 after swapping:" << std::endl;
    while (!stack1.empty()) {
        std::cout << stack1.top() << "\n";
        stack1.pop();
    }

    return 0;
}