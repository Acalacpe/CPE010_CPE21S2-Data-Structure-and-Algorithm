#include <iostream>
#include <string>

class Fruit {
    private: 
    std::string name;
    float price;
    int quantity;

public:
    //constructor
    Fruit(std::string n = " ", float p = 0.0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }
    //destructor
    ~Fruit() {}

    //Copy constructor
    Fruit(const Fruit& other)
    {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }
    
    //copy assignment operator
    Fruit& operator=(const Fruit& other)
    {
        if (this != &other)
        {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    //calculate total price
    float calculateTotalPrice() const
    {
        return price * quantity;
    }

    //Attribute display
    void displayAttributes() const {
        
        std::cout << "Category : Fruit" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total Price: " << calculateTotalPrice() << std::endl;
    }
};

class Vegetable {
    private: 
    std::string name;
    float price;
    int quantity;

public:
    //constructor
    Vegetable(std::string n = " ", float p = 0.0, int q = 0){
        name = n;
        price = p;
        quantity = q;
    }

    //destructor
    ~Vegetable() {}

    //Copy constructor
    Vegetable(const Vegetable& other)
    {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }
    
    //copy assignment operator
    Vegetable& operator=(const Vegetable& other)
    {
        if (this != &other)
        {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    //calculate total price
    float calculateTotalPrice() const
    {
        return price * quantity;
    }

    //Attribute display
    void displayAttributes() const {
        
        std::cout << "Category : Vegetable" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total Price: " << calculateTotalPrice() << std::endl;
    }
};

float TotalSum(Fruit* fruits[], int fruitSize, Vegetable* vegetables[], int vegetableSize){
    float totalSum = 0.0;

    for (int i = 0; i < fruitSize; i++) {
        if (fruits[i] != nullptr)
            totalSum += fruits[i]->calculateTotalPrice();
    }

    for (int i = 0; i < vegetableSize; i++) {
        if(vegetables[i] != nullptr)
            totalSum += vegetables[i]->calculateTotalPrice();
    }

    return totalSum;

}

int main() {
    const int FRUITS = 2;
    const int VEGETABLES = 2;

    Fruit** fruits = new Fruit*[FRUITS];
    Vegetable** vegetables = new Vegetable*[VEGETABLES];

    fruits[0] = new Fruit("Apple", 10, 7);
    fruits[1] = new Fruit("Banana", 10, 8);

    vegetables[0] = new Vegetable("Broccoli", 60, 12);
    vegetables[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "Acala Grocery Lists: " << std::endl;

    for (int i = 0; i < FRUITS; i++) {
        fruits[i]->displayAttributes();
    }

    for (int i = 0; i < VEGETABLES; i++) {
        vegetables[i]->displayAttributes();
    }

    std::cout << "Total Sum: " << TotalSum(fruits, FRUITS, vegetables, VEGETABLES) << std::endl;

    //clean up memory
    for (int i = 0; i < FRUITS; i++)
        delete fruits[i];

    for (int i = 0; i < VEGETABLES; i++)
        delete vegetables[i];

    delete[] fruits;
    delete[] vegetables;

    return 0;

}