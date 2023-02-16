/*
driver.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Nobody
*/

#include <iostream>

int main(int argc, char *argv[])
{

    // (m x n)
    double xa[3][3] = 
    {
        {2, 4, 1},
        {2, 3, 9},
        {3, 1, 8}
    };

    // (p x q)
    double xb[3][3] =
    {
        {1, 2, 3},
        {3, 6, 1},
        {2, 4, 7}
    };

    // (m x q)
    double product[3][3];

    // length and width of each collumn
    const int m=3;
    const int n=3;
    const int p=3;
    const int q=3;

    // if n is not same as p, then exit

    // for i in range 0 to m - 1
    for (int i = 0; i < m; ++i)
    {
        // for j in range 0 to q – 1
        for (int j = 0; j < q; ++j)
        {
            // for k in range 0 to p - 1
            for (int k = 0; k < p; ++k)
            {
                product[i][j] += xa[i][k] * xb[k][j];
            }
        }
    }

    std::cout << "Product of the two matrices is:" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < q; ++j)
        {   
            std::cout << product[i][j] << " ";
        }
        std::cout << std::endl;
    }

} // end main