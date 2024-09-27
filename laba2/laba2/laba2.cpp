#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

int sumOfNegative(int* array) {
    int sum = 0;

    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        if (array[i] < 0) {
            sum += array[i];
        }
    }

    return sum;
}

int quantityOfZeros(int* array) {
    int q = 0;

    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        if (array[i] == 0) {
            q += 1;
        }
    }

    return q;
}

int multipleOfPositive(int* array) {
    int multiple = 1;

    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        if (array[i] > 0) {
            multiple *= array[i];
        }
    }

    return multiple;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[19];

    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        array[i] = rand() % 20 - 10;
        std::cout << array[i] << " ";
    }

    int sum = sumOfNegative(array);
    int zeros = quantityOfZeros(array);
    int mult = multipleOfPositive(array);

    std::cout << std::endl << "Сума від'ємних елементів: " << sum << "\nКількість нульових елементів: " << zeros << "\nДобуток додатніх елементів: " << mult << std::endl;

    return 0;
}
