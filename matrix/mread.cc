#include "matrix.h"
using namespace std;

int main()
{
  int nr, nc; 
  double **xa, **xb;
  
  xa = read2d("a.mat", nr, nc); // read a 2d matrix, dimensions are returned as nr and nc
  xb = allocate2d(nr, nc); 	// allocate dynamic memory for nr*nc matrix

  for (int i=0; i<nr; i++)
    for (int j=0; j<nc; j++) 
      xb[i][j] = xa[i][j];	// copy each element

  print2d("\nxa", xa, nr, nc); 	// print the matrix to screen
  print2d("\nxb", xb, nr, nc); 
  free2d(xa); 			// deallocate the dynamic memory
  free2d(xb);
  return 0; 
}
