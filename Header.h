#pragma once


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

    // Перегрузка оператора сложения с присваиванием (+=)
    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора вычитания с присваиванием (-=)
    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора неравенства (!=)
    bool operator!=(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return true;
        }

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return true;
                }
            }
        }

        return false;
    }

    // Перегрузка оператора равенства (==)
    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    // Перегрузка оператора сложения (+)
    friend Matrix  operator+ (const Matrix& a, const Matrix& b) {
        Matrix result(a.m, a.n);
        for (unsigned int i = 0; i < a.m; ++i) {
            for (unsigned int j = 0; j < a.n; ++j) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора вычитания (-)
    friend Matrix operator- (const Matrix& a, const Matrix& b) {
        Matrix result(a.m, a.n);
        for (unsigned int i = 0; i < a.m; ++i) {
            for (unsigned int j = 0; j < a.n; ++j) {
                result.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора умножения (*)
    friend Matrix operator* (const Matrix& a, const Matrix& b) {
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