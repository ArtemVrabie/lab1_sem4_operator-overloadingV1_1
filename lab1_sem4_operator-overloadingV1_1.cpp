﻿
#include <iostream>
#include <cstdlib>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
  
    Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
        data = new int* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

   
    ~Matrix() {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Перегрузка оператора [] для доступа и изменения элемента
    int* operator[](unsigned int row) {
        return data[row];
    }

    // Метод для заполнения случайными значениями от 0 до 9
    void randomFill() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    // Перегрузка оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Перегрузка оператора сложения (+)
    Matrix  operator+ ( Matrix a,Matrix b) {
        Matrix result(a.m, a.n);
        for (unsigned int i = 0; i < a.m; ++i) {
            for (unsigned int j = 0; j < a.n; ++j) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора вычитания (-)
    Matrix operator- (const Matrix& a, const Matrix& b) {
        Matrix result(a.m, a.n);
        for (unsigned int i = 0; i < a.m; ++i) {
            for (unsigned int j = 0; j < a.n; ++j) {
                result.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора умножения (*)
    Matrix operator* (const Matrix& a, const Matrix& b) {
        Matrix result(a.m, b.n);
        for (unsigned int i = 0; i < a.m; ++i) {
            for (unsigned int j = 0; j < b.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < a.n; ++k) {
                    result.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return result;
    }
    
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Для генерации случайных чисел на основе времени 

    Matrix mat1(3, 3); // Создание первой матрицы 3x3
    mat1.randomFill(); // Заполнение случайными значениями первой матрицы
    std::cout << "Первая матрица:" << std::endl;
    std::cout << mat1; // Вывод первой матрицы

    Matrix mat2(3, 3); // Создание второй матрицы 3x3
    mat2.randomFill(); // Заполнение случайными значениями второй матрицы
    std::cout << "Вторая матрица:" << std::endl;
    std::cout << mat2; // Вывод второй матрицы

    Matrix sum = mat1 + mat2; // Сложение матриц
    std::cout << "Сумма матриц:" << std::endl;
    std::cout << sum; // Вывод суммы матриц

    Matrix diff = mat1 - mat2; // Вычитание матриц
    std::cout << "Разность матриц:" << std::endl;
    std::cout << diff; // Вывод разности матриц

    Matrix mult = mat1 * mat2; // Умножение матриц
    std::cout << "Произведение матриц:" << std::endl;
    std::cout << mult; // Вывод произведения матриц

    return 0;
}


//int main() {
  //  srand(static_cast<unsigned int>(time(0))); // Для генерации случайных чисел на основе времени 

    //Matrix mat(3, 3); // Создание матрицы 3х3
    //mat.randomFill(); // Заполнение случайными значениями
    //std::cout << "Random Matrix" << std::endl;
    //std::cout << mat; // Вывод матрицы

    //return 0;
//}

