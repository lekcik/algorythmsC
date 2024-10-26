#include <iostream>
#include <Windows.h>
#include <time.h>

template<class T> void bubbleSort(T array[], int arraySize) {
    T temp;

    for (int i = arraySize; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (array[j] < array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

template<class T> void quickSort(T array[], int arraySize) {
    int pivot = arraySize - 1;
    int i = -1;
    int j = 0;
    T temp;

    while (j <= pivot) {
        if (array[j] < array[pivot] || j == pivot) {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
        j++;
    }

    if (i != 0) {
        quickSort(array, i);
    }
    if (arraySize - i - 1 > 1) {
        quickSort(array + i + 1, arraySize - i - 1); 
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[30];
    int arraySize = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 90 + 10;
    }

    std::cout << "BUBBLE SORT\n";

    std::cout << "UNORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    bubbleSort(array, arraySize);

    std::cout << "\n\nORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 90 + 10;
    }

    std::cout << "\n\nQUICK SORT";

    std::cout << "\nUNORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    quickSort(array, arraySize);

    std::cout << "\n\nORDERED ARRAY" << std::endl;
    for (int& elem : array) {
        std::cout << elem << " ";
    }

    return 0;
}
