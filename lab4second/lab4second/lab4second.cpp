#include <iostream>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int N = 5;
    int M = 4;

    int c1 = 0, c2 = 0;

    float A[5][4];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rand() / (RAND_MAX / 100.0);
        }
    }

    std::cout << "Initial array\n" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << A[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    float** array = new float*[N];

    for (int i = 0; i < N; i++) {
        array[i] = new float[M];
    }

    while (!(c1 < c2)) {
        std::cout << "Enter first border: ";
        std::cin >> c1;
        std::cout << "Enter second border: ";
        std::cin >> c2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((A[i][j] <= c1) || (A[i][j] >= c2)) {
                array[i][j] = A[i][j];
            }
            else {
                array[i][j] = 0;
            }
        }
    }

    std::cout << "\nArray with values outside of borders\n" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << array[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;

    return 0;
}
