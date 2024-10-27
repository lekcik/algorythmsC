#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 0, K = 0, L = 0, sum = 0;
    int* array;

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

    array = new int[n];

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 15;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int i = K; i <= L; i++) {
        sum += array[i];
    }

    std::cout << "Sum of the elements from " << K << " to " << L << " is: " << sum << std::endl;

    delete[] array;
    array = nullptr;

    return 0;
}
