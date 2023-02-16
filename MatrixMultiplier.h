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
#include "matrix/matrix.h"

class MatrixMultiplier
{
public:
    /**
     * @brief Construct a new Matrix Multiplier object
     * 
     */
    MatrixMultiplier(void);

    /**
     * @brief 
     * Construct a new Matrix Multiplier object.
     * Takes two matrices of size (mxn) and (pxq) respectively.
     * Automatically multiplies two matrices together and stores their result in product_.
     * 
     * @param xa double pointer to first matrix
     * @param xb double pointer to second matrix
     * @param m length of matrix a's rows
     * @param n length of matrix a's columns
     * @param p length of matrix b's rows
     * @param q length of matrix b's columns
     */
    MatrixMultiplier(double** xa, double** xb, int m, int n, int p, int q);

    /**
     * @brief Destroy the Matrix Multiplier object and free product_.
     * 
     * !!! Does not free matrices xa_ and xb_
     * 
     */
    ~MatrixMultiplier(void);

    /**
     * @brief Get the product of matrices xa_ and xb_
     * 
     * @return double**, double pointer to product_ matrix
     */
    double** getProduct(void);

private:
    double **xa_, **xb_, ** product_;
    int m_, n_, p_, q_;

    /**
     * @brief Multiply xa_ and xb_ matrices
     *
     * @param double** product is a pointer referencing the matrix allocated for the product of the two matrices
     *
     */
    void multiply(void);
};

#endif // defined MatrixMultiplier