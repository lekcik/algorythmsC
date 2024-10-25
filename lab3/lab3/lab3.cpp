#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::cout << "Hello World!\n";
}
