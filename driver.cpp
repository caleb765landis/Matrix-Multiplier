/*
driver.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Nobody
*/

#include <iostream>
#include "matrix/matrix.h"
#include "MatrixMultiplier.h"

int main(int argc, char *argv[])
{

    int nr, nc;
    double **xa, **xb;

    xa = read2d("a.mat", nr, nc); // read a 2d matrix, dimensions are returned as nr and nc
    xb = allocate2d(nr, nc);      // allocate dynamic memory for nr*nc matrix

    for (int i = 0; i < nr; i++)
        for (int j = 0; j < nc; j++)
            xb[i][j] = xa[i][j]; // copy each element


    MatrixMultiplier mm(xa, xb);
    mm.multiply();

    free2d(xa); // deallocate the dynamic memory
    free2d(xb);
    return 0;
} // end main