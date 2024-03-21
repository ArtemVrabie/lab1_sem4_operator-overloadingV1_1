#include "Matrix.h"


Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}