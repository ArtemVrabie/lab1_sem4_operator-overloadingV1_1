// lab1_sem4_operator-overloadingV1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
    // Конструктор
    Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
        data = new int* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

    // Деструктор
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

    // Перегрузка операторов для арифметических и логических операций
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Для генерации случайных чисел на основе времени 

    Matrix mat(3, 3); // Создание матрицы 3х3
    mat.randomFill(); // Заполнение случайными значениями
    std::cout << "Случайно заполненная матрица:" << std::endl;
    std::cout << mat; // Вывод матрицы

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
