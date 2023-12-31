/*
MatrixMultiplier.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Logan Kurker on 2/21/23
    Logan Kurker on 2/23/23
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
    multiply(0, 0);
}

MatrixMultiplier::~MatrixMultiplier(void)
{
    free2d(product_);
}

void MatrixMultiplier::multiply(int start, int end)
{
    // if n is not same as p, throw exception
    // haven't implemented yet
    if(p_ != n_){
      //do something
    }//end if statement 

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
          addElements(product_[i][j]);
        } // end for j
    } // end for i
} // end multiply

double** MatrixMultiplier::getProduct(void)
{
    return product_;
}

void MatrixMultiplier::setMatrices(double **xa, double **xb, int m, int n, int p, int q, int start, int end)
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
    multiply(start, end);
}

int MatrixMultiplier::getElements(void)
{

  // we can easily return the number of values for the new matrix if we multiply the number of rows from the first matrix with the number of columns from the second
  int elements = m_ * q_;
  return elements; 

}

//
// addElements
//
void MatrixMultiplier::addElements(double element)
{

  sum += element;

}

//
// getSum
//
double MatrixMultiplier::getSum(void)
{

  return sum;

}

//
// getAverage
//
double MatrixMultiplier::getAverage(void)
{

    average = this->getSum() / elements;
    return average;

}
