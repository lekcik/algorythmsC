#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

int getIntInput(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Помилка: введіть ціле число!\n";
        }
        else {
            return value;
        }
    }
}

std::vector<std::vector<int>> matrixCreate() {
    int resolution = getIntInput("Введіть розмірність матриці: ");
    int max = getIntInput("Введіть максимальне значення чисел матриці: ");
    int min = getIntInput("Введіть мінімальне значення чисел матриці: ");

    if (min > max) {
        std::cout << "Помилка: мінімальне значення не може бути більше за максимальне.\n";
        return {};
    }

    std::vector<std::vector<int>> matrix(resolution, std::vector<int>(resolution));

    for (int i = 0; i < resolution; ++i) {
        for (int j = 0; j < resolution; ++j) {
            if (rand() % 11 > 2) {
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = rand() % (max - min + 1) + min;
            }
        }
    }

    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

void matrixToCSR(const std::vector<std::vector<int>>& matrix, std::vector<int>& aelem, std::vector<int>& jptr, std::vector<int>& iptr) {
    int n = matrix.size();
    iptr.push_back(0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                aelem.push_back(matrix[i][j]);
                jptr.push_back(j);
            }
        }
        iptr.push_back(aelem.size());
    }
}

int getElementCSR(const std::vector<int>& aelem, const std::vector<int>& jptr, const std::vector<int>& iptr, int row, int col) {
    for (int idx = iptr[row]; idx < iptr[row + 1]; ++idx) {
        if (jptr[idx] == col) {
            return aelem[idx];
        }
    }
    return 0;
}

void setElementCSR(std::vector<int>& aelem, std::vector<int>& jptr, std::vector<int>& iptr, int row, int col, int value) {
    for (int idx = iptr[row]; idx < iptr[row + 1]; ++idx) {
        if (jptr[idx] == col) {
            if (value == 0) {
                aelem.erase(aelem.begin() + idx);
                jptr.erase(jptr.begin() + idx);
                for (int i = row + 1; i < iptr.size(); ++i) {
                    iptr[i]--;
                }
            }
            else {
                aelem[idx] = value;
            }
            return;
        }
    }

    if (value != 0) {
        int pos = iptr[row + 1];
        aelem.insert(aelem.begin() + pos, value);
        jptr.insert(jptr.begin() + pos, col);
        for (int i = row + 1; i < iptr.size(); ++i) {
            iptr[i]++;
        }
    }
}

void printMatrixWithCondition(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0 && j % 2 == 0 && matrix[i][j] == 0) {
                std::cout << matrix[i][j] << "\t";
            }

            else if (matrix[i][j] != 0) {
                std::cout << matrix[i][j] << "\t"; 
            }

            else {
                std::cout << " \t"; 
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> aelem;
    std::vector<int> jptr;
    std::vector<int> iptr;
    std::vector<std::vector<int>> matrix;

    while (true) {
        int choice;
        std::cout << "\nМеню:\n1. Створити матрицю\n2. Вивести матрицю\n3. Читати елемент\n4. Записати елемент\n5. Зберегти нулі з парними індексами\n6. Вихід\n";
        choice = getIntInput("Оберіть дію: ");

        switch (choice) {
        case 1:
            matrix = matrixCreate();
            matrixToCSR(matrix, aelem, jptr, iptr);
            break;
        case 2:
            printMatrix(matrix);
            break;
        case 3: {
            int row = getIntInput("Введіть номер рядка для читання: ");
            int col = getIntInput("Введіть номер стовпця для читання: ");
            std::cout << "Елемент: " << getElementCSR(aelem, jptr, iptr, row, col) << std::endl;
            break;
        }
        case 4: {
            int row = getIntInput("Введіть номер рядка для запису: ");
            int col = getIntInput("Введіть номер стовпця для запису: ");
            int value = getIntInput("Введіть нове значення: ");
            setElementCSR(aelem, jptr, iptr, row, col, value);
            std::cout << "Елемент після запису: " << getElementCSR(aelem, jptr, iptr, row, col) << std::endl;
            break;
        }
        case 5:
            printMatrixWithCondition(matrix);
            matrixToCSR(matrix, aelem, jptr, iptr);
            std::cout << "Збережено нулі на парних індексах.\n";
            break;
        case 6:
            return 0;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }

    return 0;
}
