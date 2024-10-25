#include <iostream>
#include <Windows.h>
#include <time.h>

template<class T> void bubbleSort(T array[], int size) {
    T temp;

    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (array[j] < array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[] = { 4, 18, 32, 2, 1, 19, 22, 40 };
    int arraySize = sizeof(array) / sizeof(array[0]);

    std::cout << "UNORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    bubbleSort(array, arraySize);

    std::cout << "\n\nORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    return 0;
}
