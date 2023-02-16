/*
MatrixMultiplier.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Nobody
*/

#include "MatrixMultiplier.h"

MatrixMultiplier::MatrixMultiplier()
    : xa_(nullptr), xb_(nullptr), m_(0), n_(0), p_(0), q_(0)
{}

MatrixMultiplier::MatrixMultiplier(double **xa, double **xb, int m, int n, int p, int q)
    : xa_(xa), xb_(xb), m_(m), n_(n), p_(p), q_(q)
{
    // allocate memory for product matrix based on a's row length and b's column length
    product_ = allocate2d(m_, q_);

    // multiply two matrices and store their result in product
    multiply();
}

MatrixMultiplier::~MatrixMultiplier(void)
{
    free2d(product_);
}

void MatrixMultiplier::multiply()
{
    // if n is not same as p, throw exception
    // haven't implemented yet

    // for i in range 0 to m - 1
    for (int i = 0; i < m_; ++i)
    {
        // for j in range 0 to q – 1
        for (int j = 0; j < q_; ++j)
        {
            // for k in range 0 to p - 1 or (n - 1) since n and p are the same
            for (int k = 0; k < p_; ++k)
            {
                product_[i][j] += xa_[i][k] * xb_[k][j];
            } // end for k
        } // end for j
    } // end for i
} // end multiply

double** MatrixMultiplier::getProduct(void)
{
    return product_;
}

void MatrixMultiplier::setMatrices(double **xa, double **xb, int m, int n, int p, int q)
{
    // reset properties
    xa_ = xa;
    xb_ = xb;
    m_ = m;
    n_ = n;
    p_ = p;
    q_ = q;

    // reallocate space for product
    free2d(product_);
    product_ = allocate2d(m_, q_);

    // multiply new matrices together
    multiply();
}