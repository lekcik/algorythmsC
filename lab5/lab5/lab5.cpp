#include <iostream>
#include <ctime>

template<class T> void insertionSort(T array[], int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        T temp = array[i];
        for (int j = i-1; j >= 0; j--) {
            if (array[j] >= temp) {
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

template<class T> void shallSort(T array[], int arraySize) {

}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int array[] = { 2, 5, 9, 1, 4, 7 };
    int arraySize = sizeof(array) / sizeof(array[0]);

    std::cout << "Not ordered array" << std::endl;
    for (auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    insertionSort(array, arraySize);

    std::cout << "Ordered array with InsertionSort" << std::endl;
    for (auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << "\n" << std::endl;

    int secondArray[] = {2, 5, 9, 1, 4, 7};
    int secondArraySize = sizeof(secondArray) / sizeof(secondArray[0]);

    std::cout << "Not ordered array" << std::endl;
    for (auto& elem : secondArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    //insertionSort(array, arraySize);

    //std::cout << "Ordered array with InsertionSort" << std::endl;
    //for (auto& elem : array) {
    //    std::cout << elem << " ";
    //}
    //std::cout << std::endl;
}