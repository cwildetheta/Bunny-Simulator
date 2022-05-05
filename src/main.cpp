#include "bunny.h"
#include <iostream>

int main()
{
    system("cls");
    std::cout << "Test" << std::endl;

    bunny test;
    std::cout << test.get_name() << std::endl;
    std::cout << "Test" << std::endl;

    return 0;
}