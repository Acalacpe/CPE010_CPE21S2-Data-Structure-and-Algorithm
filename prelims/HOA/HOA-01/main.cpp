#include<iostream>
#include <string>

//Create a function that will take two numbers and display the sum

float Sum(float n1, float n2) {
    return n1 + n2;
}

// Create a function that will return whether variable A is greater than variable B.

std::string Compare(float n1, float n2){
    if(n1 > n2) {
        return "Variable A is Bigger than variable B"; 
        }
    else if (n1 < n2) {
        return "Variable B is bigger than variable A";
        }
    else {
        return "Both variable is equal";
    }
}

// Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success

std::string CompareBool(int a, int b) {
    if ((a != 0 && a != 1) || (b != 0 && b != 1)) {
        return "Invalid input! Please enter only 0 or 1.";
    }

    bool valA = (a == 1);
    bool valB = (b == 1);

    if (valA && valB) {
        return "Both are true";
    } else if (!valA && !valB) {
        return "Both are false";
    } else {
        return "At least one value is true";
    }
}


int main() {

float n1, n2;
int a, b;
std::string result;

    std::cout << "Enter 1st Number: ";
    std::cin >> n1;
    std::cout << "Ener 2nd Number: ";
    std::cin >> n2;

    std::cout << "Enter first boolean value(1 = True or 0 = False): ";
    std::cin >> a;
    std::cout << "Enter seond boolean value(1 = True or 0 = False): ";
    std::cin >> b;

    result = Compare(n1, n2);

    std::cout << "The sum of 2 number is " << Sum(n1, n2) << std::endl;
    std::cout << result << std::endl;
    std::cout << CompareBool(a, b);

return 0;

}
