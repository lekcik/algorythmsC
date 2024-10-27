#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows;
    int columns;

    std::cout << "Введіть кількість рядків: ";
    std::cin >> rows;

    std::cout << "Введіть кількість стовбців: ";
    std::cin >> columns;

    float** array = new float* [rows];

    for (int i = 0; i < rows; i++) {
        array[i] = new float[columns];
    }

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;

    return 0;
}
