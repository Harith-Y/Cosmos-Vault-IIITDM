#include "Matrix.hpp"   

Matrix& Matrix :: operator++() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j]++;
        
    return *this;
}

Matrix Matrix :: operator++(int) {
    Matrix temp = *this;
    ++(*this);
    return temp;
}

Matrix& Matrix :: operator--() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j]--;
    
    return *this;
}

Matrix Matrix :: operator--(int) {
    Matrix temp = *this;
    --(*this);
    return temp;
}

