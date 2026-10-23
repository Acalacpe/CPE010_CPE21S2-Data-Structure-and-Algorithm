#include <iostream>
using namespace std;

float CashieringSystem(float money, float item1, float item2, float item3) {
    if (money >= (item1 + item2 + item3)) {
        float change = money - (item1 + item2 + item3);
        return change;
    }
    else {
        cout << "Not enough money";
        return -1;
    }
}

int main() {
    
    float money, item1, item2, item3, total;

    cout << "How much is your money: ";
    cin >> money;
    cout << "Enter Item 1 Price: ";
    cin >> item1;
    cout << "Enter Item 2 Price: ";
    cin >> item2;
    cout << "Enter Item 3 Price: ";
    cin >> item3;

    total = CashieringSystem(money, item1, item2, item3);
    
    if (total != -1){
        cout << "Your change is: " << total;
    }
    
    return 0;
}