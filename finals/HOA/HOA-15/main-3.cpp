#include <iostream>
#include "queueLL.h"

int main()
{

    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr;

    enqueue('1', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('2', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('3', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('4', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('3', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('2', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('5', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;

    checker(&front, &back);

    return 0;
}