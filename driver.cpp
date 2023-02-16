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

    int nra, nca, nrb, ncb;
    double **xa, **xb, **product;

    xa = read2d("matrix/a.mat", nra, nca); // read a 2d matrix, dimensions are returned as nr and nc
    xb = read2d("matrix/b.mat", nrb, ncb);
    product = allocate2d(nra,ncb);
    //xb = allocate2d(nr, nc);      // allocate dynamic memory for nr*nc matrix


    // multiply the two matrices
    MatrixMultiplier mm(xa, xb);
    mm.multiply(product);
    
    // print the matrices to screen
    print2d("\nxa", xa, nra, nca); 
    print2d("\nxb", xb, nrb, ncb);
    print2d("\product", product, nra, ncb);
    
    // deallocate the dynamic memory
    free2d(xa); 
    free2d(xb);
    free2d(product);
    return 0;
} // end main