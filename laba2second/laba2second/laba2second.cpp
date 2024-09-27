#include <iostream>
#include <Windows.h>
#include <time.h>

int findSum(int array[][4], int rows, int columns) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] == 1) {
                sum += array[i][j];
            }
        }
    }

    return sum;
}

int countElems(int array[][4], int rows, int columns) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int rows = 5;
    const int columns = 4;

    int array[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 6 - 3;
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int sum = findSum(array, rows, columns);
    int count = countElems(array, rows, columns);

    std::cout << std::endl << "Сума елементів, рівних 1: " << sum << "\nКількість елементів, рівних 1: " << count << std::endl;

    return 0;
}
