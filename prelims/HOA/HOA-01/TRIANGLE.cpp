#include <iostream>
#include <cmath>

class Triangle {
private:
    double angleA, angleB, angleC;
    double totalAngle;

public:
    Triangle(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    void setAngles(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    const bool validateTriangle() {
        return (totalAngle == 180);
    }

    
    double area(double base, double height) {
        return 0.5 * base * height;
    }

    
    double perimeter(double a, double b, double c) {
        return a + b + c;
    }

    
    std::string triangleType() {
        if (angleA < 90 && angleB < 90 && angleC < 90) {
            return "Acute-angled triangle";
        } else if (angleA > 90 || angleB > 90 || angleC > 90) {
            return "Obtuse-angled triangle";
        } else if (angleA == 90 || angleB == 90 || angleC == 90) {
            return "Right-angled triangle";
        } else {
            return "Others";
        }
    }
};

int main() {
    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Triangle type: " << set1.triangleType() << std::endl;
        std::cout << "Area (base=10, height=5): " << set1.area(10, 5) << std::endl;
        std::cout << "Perimeter (sides=3,4,5): " << set1.perimeter(3, 4, 5) << std::endl;
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}
