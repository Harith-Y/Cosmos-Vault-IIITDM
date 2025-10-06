#include "Matrix.hpp"   

// Pre Increment
Matrix& Matrix :: operator ++ () {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j]++;
        
    return *this;
}

//Post Increment
Matrix Matrix :: operator ++ (int) {
    Matrix temp = *this;
    ++(*this);
    return temp;
}

//Pre Decrement
Matrix& Matrix :: operator -- () {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j]--;
    
    return *this;
}

//Post Decrement
Matrix Matrix :: operator -- (int) {
    Matrix temp = *this;
    --(*this);
    return temp;
}
