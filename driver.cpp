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

    // read 2d matrices a and b
    // dimensions are returned as nrx and ncx where x is matrix name
    xa = read2d("matrix/a.mat", nra, nca); 
    xb = read2d("matrix/b.mat", nrb, ncb);

    // multiply the two matrices and store result in product
    MatrixMultiplier mm(xa, xb, nra, nca, nrb, ncb);
    product = mm.getProduct();
    
    // print the matrices to console
    print2d("\nxa", xa, nra, nca); 
    print2d("\nxb", xb, nrb, ncb);
    print2d("\nproduct", product, nra, ncb);
    
    // deallocate the dynamic memory
    free2d(xa); 
    free2d(xb);

    return 0;
} // end main