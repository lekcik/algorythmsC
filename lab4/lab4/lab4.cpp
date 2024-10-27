#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 0, K = 0, L = 0, sum = 0;
    int* firstArray;

    while (!(n > 0)) {
        std::cout << "Enter arrays capacity (greater than 0): ";
        std::cin >> n;
    }

    while (!((K >= 1) && (L > K) && (K < n) && (L < n))) {
        std::cout << "Enter first limit (greater or equal to 1): ";
        std::cin >> K;
        std::cout << "Enter second limit (greater than first one): ";
        std::cin >> L;
    }

    firstArray = new int[n];

    for (int i = 0; i < n; i++) {
        firstArray[i] = rand() % 15;
        std::cout << firstArray[i] << " ";
    }
    std::cout << std::endl;

    for (int i = K; i <= L; i++) {
        sum += firstArray[i];
    }

    std::cout << "Sum of the elements from " << K << " to " << L << " is: " << sum << std::endl;

    delete[] firstArray;
    firstArray = nullptr;

    //int rows;
    //int columns;

    //std::cout << "Введіть кількість рядків: ";
    //std::cin >> rows;

    //std::cout << "Введіть кількість стовбців: ";
    //std::cin >> columns;

    //float** array = new float* [rows];

    //for (int i = 0; i < rows; i++) {
    //    array[i] = new float[columns];
    //}

    //for (int i = 0; i < rows; i++) {
    //    delete[] array[i];
    //}
    //delete[] array;
    //array = nullptr;

    return 0;
}
