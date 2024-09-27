#include <iostream>
#include <Windows.h>
#include <time.h>

int sumOfNegative(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            sum += array[i];
        }
    }
    return sum;
}

int quantityOfZeros(int* array, int size) {
    int q = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            q += 1;
        }
    }
    return q;
}

int multipleOfPositive(int* array, int size) {
    int multiple = 1;
    bool hasPositive = false; 
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            multiple *= array[i];
            hasPositive = true;
        }
    }
    return hasPositive ? multiple : 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[19];

    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 21 - 10; 
        std::cout << array[i] << " ";
    }

    int sum = sumOfNegative(array, size);
    int zeros = quantityOfZeros(array, size);
    int mult = multipleOfPositive(array, size);

    std::cout << std::endl << "Сума від'ємних елементів: " << sum
        << "\nКількість нульових елементів: " << zeros
        << "\nДобуток додатніх елементів: " << mult << std::endl;

    return 0;
}
