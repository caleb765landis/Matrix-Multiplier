/*
MatrixMultiplier.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Nobody
*/

#include "MatrixMultiplier.h"

MatrixMultiplier::MatrixMultiplier()
    : xa_(nullptr), xb_(nullptr)
{}

MatrixMultiplier::MatrixMultiplier(double** xa, double** xb)
    : xa_(xa), xb_(xb)
{}

MatrixMultiplier::~MatrixMultiplier(void)
{}

void MatrixMultiplier::multiply(double **product)
{
    // length and width of each collumn
    const int m = 3;
    const int n = 3;
    const int p = 3;
    const int q = 3;

    // if n is not same as p, then exit

    // for i in range 0 to m - 1
    for (int i = 0; i < m; ++i)
    {
        // for j in range 0 to q – 1
        for (int j = 0; j < q; ++j)
        {
            // for k in range 0 to p - 1 or (n - 1) since n and p are the same
            for (int k = 0; k < p; ++k)
            {
                product[i][j] += xa_[i][k] * xb_[k][j];
            }
        }
    }

    /*
    std::cout << "Matrix a:" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << xa_[i][j] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    std::cout << "Matrix b:" << std::endl;
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            std::cout << xb_[i][j] << " ";
        }
        std::cout << std::endl << std::endl;;
    }

    std::cout << "Product of the two matrices is:" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            std::cout << product[i][j] << " ";
        }
        std::cout << std::endl << std::endl;;
    }
    */

    //return product;
}