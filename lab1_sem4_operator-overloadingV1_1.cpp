
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Header.h"



int main() {
    srand(static_cast<unsigned int>(time(0))); // Для генерации случайных чисел на основе времени 

    Matrix mat1(3, 3); // Создание первой матрицы 3x3
    mat1.randomFill(); // Заполнение случайными значениями первой матрицы
    std::cout << "First matrix:" << std::endl;
    std::cout << mat1; // Вывод первой матрицы

    Matrix mat2(3, 3); // Создание второй матрицы 3x3
    mat2.randomFill(); // Заполнение случайными значениями второй матрицы
    std::cout << "Second matrix:" << std::endl;
    std::cout << mat2; // Вывод второй матрицы

    mat2 += mat1;
    std::cout << "+=:" << std::endl;
    std::cout << mat2;

    mat2 -= mat1;
    std::cout << "-=:" << std::endl;
    std::cout << mat2;

    if (mat2 != mat1) {
        std::cout << "matrices aren't equal" << std::endl;
        std::cout << true;
    }
    else
        std::cout << "matrices are equal" << std::endl;
        std::cout << false;

        if (mat2 == mat1) {
            std::cout << "matrices are equal" << std::endl;
            std::cout << true;
        }
        else
            std::cout << "matrices aren't equal" << std::endl;
            std::cout << false;


    Matrix sum = mat1 + mat2; // Сложение матриц
    std::cout << "Sum of matrices : " << std::endl;
    std::cout << sum; // Вывод суммы матриц

    Matrix diff = mat1 - mat2; // Вычитание матриц
    std::cout << "Matrix difference:" << std::endl;
    std::cout << diff; // Вывод разности матриц

    Matrix mult = mat1 * mat2; // Умножение матриц
    std::cout << "Product of matrices:" << std::endl;
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

