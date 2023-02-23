/*
MatrixMultiplier.h

Created by: Caleb Landis
Created on: 2/16/23
Modified by:
    Logan Kurker on 2/21/23
    Logan Kurker on 2/23/23
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
    void setMatrices(double** xa, double** xb, int m, int n, int p, int q, int start, int end);

    /**
      * @brief
      * Multiply the rows of xa with the columns of xb.
      * Return the value, which is equivalent to the number of elements from the new array.
      */
     int getElements(void); 

   /**
     * @brief
     * A method that adds together elements from the matrix into the sum member variable.
     *
     * @param element is a double value that will be added to the sum value as the new matrix is being created
     */
   void addElements(double element);

   /**
     * @brief
     * Getter for the sum
     */
   double getSum(void);

  /**
    * @brief
    * This method will be called once the new matrix C has been created, and will divide the sum member variable with the elements member variable
    */
  double getAverage(void);

  void multiply(int start, int end);
   
private:
    double **xa_, **xb_, ** product_;
    int m_, n_, p_, q_;
    int elements;
    double sum;
    double average;

    /**
     * @brief Multiply xa_ and xb_ matrices
     *
     * @param double** product is a pointer referencing the matrix allocated for the product of the two matrices
     *
     */
    //temporarily making public to test things
    //void multiply(int start, int end);
};

#endif // defined MatrixMultiplier
