#include <iostream>
#include <cmath>

float KtoF(float K){
    return (K - 273.15) * 9/5 + 32;
}

float Distance(float x1, float y1, float x2, float y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main () {
    int a, b, temp;
    float K, x1, x2, y1, y2;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> K;
    std::cout << "Enter coordinates (x1, y1, x2, y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

        temp = a;
        a = b;
        b = temp;

    std::cout << "After swapping a = " << a << ", b =  " << b << std::endl;
    std::cout << "Temperature in Fahrenheit: " << KtoF(K) << std::endl;
    std::cout << "Distance between points: " << Distance(x1, y1, x2, y2) << std::endl;

    return 0;
}