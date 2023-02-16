/*
MatrixMultiplier.h

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Nobody
*/

#ifndef _MATRIX_MULTIPLIER_H_
#define _MATRIX_MULTIPLIER_H_

#include <iostream>

class MatrixMultiplier
{
public:
    /**
     * @brief Construct a new Matrix Multiplier object
     * 
     */
    MatrixMultiplier(void);

    MatrixMultiplier(double** xa, double** xb);

    /**
     * @brief Destroy the Matrix Multiplier object
     * 
     */
    ~MatrixMultiplier(void);

    /**
     * @brief Multiply xa_ and xb_ matrices
     * 
     * @return double**, product of matrices
     */
    void multiply(void);

private:
    double **xa_, **xb_;
};

#endif // defined MatrixMultiplier