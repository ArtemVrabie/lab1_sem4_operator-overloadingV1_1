
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

    
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Для генерации случайных чисел на основе времени 

    Matrix mat(3, 3); // Создание матрицы 3х3
    mat.randomFill(); // Заполнение случайными значениями
    std::cout << "Random Matrix" << std::endl;
    std::cout << mat; // Вывод матрицы

    return 0;
}

