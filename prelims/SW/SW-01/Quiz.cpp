#include <iostream>
using namespace std;

float ComputeGrade(float q1, float q2, float q3) {
    return (q1 + q2 + q3)/3;
}

int main() {

    float q1, q2, q3, average;

    cout << "Enter Quiz 1 Score: " << endl;
    cin >> q1;

    cout << "Enter Quiz 2 Score: " << endl;
    cin >> q2;

    cout << "Enter Quiz 3 Score: " << endl;
    cin >> q3;

    average = ComputeGrade(q1, q2, q3);

    cout << "The Average Score is: " << average;
    
    return 0;
}