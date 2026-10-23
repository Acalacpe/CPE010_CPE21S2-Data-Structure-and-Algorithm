#include <iostream>

//global declarations
#define maxCap 100

int StackArr[maxCap];
int top = -1;   // stack starts empty
int newData;

//prototype functions
void push();
void pop();
void displayStack();
void angat();    
bool isEmpty();
bool isFull();

//function definition

//check if is empty
bool isEmpty() {
    if(top == -1) return true;
    return false;
}

bool isFull() {
    if(top == maxCap -1) return true;
    return false;
}

void push() {
    //error checking
    if(isFull()){
        std::cout<<"Stack overflow" << std::endl;
        return;
    }

    //pushing to the stack
    std::cout<<"\nEnter a new value: " << std::endl;
    std::cin>>newData;
    StackArr[++top] = newData;
}

void pop(){
    //error checking
    if(isEmpty()){
        std::cout<<"Stack Underflow"<<std::endl;
        return;
    }
    
    //display the value that we are going to pop
    std::cout<<"Popping: " << StackArr[top]<<std::endl;
    //decrement the top value from the stack
    top--;
}

void angat(){
    //error catching
    if(isEmpty()){
        std::cout<<"The stack is empty"<<std::endl;
        return;
    }
    std::cout<<"Top element is: "<<StackArr[top]<<std::endl;
}

void displayStack(){
    //error catching
    if(isEmpty()){
        std::cout<<"Stack underflow"<<std::endl;
        return;
    }

    //display using normal for loop
    std::cout<<"Stack elements: "<<std::endl;
        for(int i = top; i >= 0; i--){
            std::cout<<StackArr[i]<<std::endl;
        }
}

int main() {

    //main program
    int choice;

    while(true){
        std::cout<<"<<<======Stack Operations=====>>>" << std::endl;
        std::cout<<"1. Push\n2. Pop\n3. Top\n4. isFull\n5. isEmpty\n6. displayStack"<<std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin>>choice;
        

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: angat();
            break;
            case 4: std::cout<<"Is stack full? " << isFull() << std::endl;
            break;
            case 5: std::cout<<"Is stack empty? "<< isEmpty() << std::endl;
            break;
            case 6: displayStack();
            break;
            default: std::cout<<"Invalid choice"<<std::endl;
        }
    }
}

