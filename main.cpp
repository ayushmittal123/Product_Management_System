#include <iostream>
#include <limits.h>

void showMenu();
void addProduct();


int main() {
    int choice = INT_MIN;
    showMenu();
    std::cin >> choice;

    switch(choice)
    {
        case 1:
        {
            addProduct();
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

void showMenu()
{
    std::cout << "Menu" << std::endl;
    std::cout << "1. Add Product" << std::endl;
}

void addProduct()
{
    std::cout << "Product Added" << std::endl;
}