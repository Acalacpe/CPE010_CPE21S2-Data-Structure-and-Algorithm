#include <iostream>
#include <string>
#include <string.h>

class Student {
private:
    std::string studentName;
    int studentAge;


public:
//constructor
    Student(std::string newName = "Matt John", int newAge = 18) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
};

//deconstructor
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

//Copy Constructor
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

//Display Attributes
    void printDetails() {
        std::cout << this->studentName << " " << this->studentAge << std::endl;

    }

//Copy Assignment Operator
    Student& operator=(const Student& other) {
        std::cout << "Copy Assignment Operator Called." << std::endl;

        if (this != &other){
            studentName = other.studentName;
            studentAge = other.studentAge;
        }
        return *this;
    }
};
int main() {
    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 17, 18, 19};

//Loop A
    for(int i = 0; i < j; i++){
        Student* ptr = new Student (nameList[i], ageList[i]);
        studentList[i] = *ptr;
    }
//Loop B
    for(int i = 0; i < j; i++){
        studentList[i].printDetails();
    }

    return 0;
}