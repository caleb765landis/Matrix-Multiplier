/*
driver.cpp

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Logan Kurker on 2/23/23
*/

#include <iostream>
#include <thread>
#include "matrix/matrix.h"
#include "MatrixMultiplier.h"
#include "TimeInterval.h"

int main(int argc, char *argv[])
{

    int nra, nca, nrb, ncb;
    double **xa, **xb, **product, **xc, **xd;
    
    // read 2d matrices a and b
    // dimensions are returned as nrx and ncx where x is matrix name
    xa = read2d("matrix/a.mat", nra, nca); 
    xb = read2d("matrix/b.mat", nrb, ncb);
    
    TimeInterval t;
    t.start();
    
    int numThreads = 16;
    //the threadIterations variable will be used to determine how many times each thread will compute the multiplication of the rows and columns between matrices A and B
    int threadIterations = 1024 / numThreads;

    //placeholder variables
    int start = 0;
    int end = threadIterations;

    std::thread threads[numThreads];

    MatrixMultiplier mm(xa, xb, nra, nca, nrb, ncb);

    /*for(int i = 0; i < numThreads; i++){
       // multiply the two matrices and store result in product
        threads[i] = std::thread(&MatrixMultiplier::multiply, &mm, start, end);
        start += threadIterations;
        end += threadIterations;
    }//end for loop

    //now we must join the threads
    for(int i = 0; i < numThreads; i++){
      threads[i].join();
   }//end for loop*/

    
    
   
    product = mm.getProduct();
    
    t.stop();
    std::cout << t.GetInterval() << std::endl;

    // checking to see if the number of elements in the array is correct
    int numElements = mm.getElements();
    std::cout << numElements << std::endl;

    int sum = mm.getSum();
    std::cout << sum << std::endl;
    
    /*
    //print the matrices to console
    print2d("\nxa", xa, nra, nca); 
    print2d("\nxb", xb, nrb, ncb);
    print2d("\nproduct", product, nra, ncb);
    */
    // deallocate the dynamic memory
    free2d(xa); 
    free2d(xb);
    /*
    // read 2d matrices c and d
    // dimensions are returned as nrx and ncx where x is matrix name
    xc = read2d("matrix/c.mat", nra, nca);
    xd = read2d("matrix/d.mat", nrb, ncb);
    
    // MatrixMultiplier mm2(xc, xd, nra, nca, nrb, ncb);
    mm.setMatrices(xc, xd, nra, nca, nrb, ncb);
    product = mm.getProduct();
     
    // print the new matrices to console
    print2d("\nxc", xc, nra, nca);
    print2d("\nxd", xd, nrb, ncb);
    print2d("\nproduct", product, nra, ncb);
    
    free2d(xc);
    free2d(xd);
    */
    
   
    return 0;
} // end main
