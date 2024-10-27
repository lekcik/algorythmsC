#include <iostream>
#include <ctime>

template<class T> void insertionSort(T array[], int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        T temp = array[i];
        for (int j = i-1; j >= 0; j--) {
            if (array[j] > array[i]) {
                array[j + 1] = array[j];
            }
            else {
                array[j + 1] = temp;
                break;
            }

            if (j == 0) {
                array[j] = temp;
            }
        }
    }    
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int array[] = { 2, 5, 9, 1, 4, 7 };
    int arraySize = sizeof(array) / sizeof(array[0]);

    for (auto& elem : array) {

    }
}