/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 2: Compute exp(A) for square matrices
 */


// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>		// Behövdes för exit(1)..
#include "matrix.hpp"

// Function Definitions		::	::	::	::

using namespace std;
#include "r8lib.h"
#include "r8mat_expm1.h"

// Function Declarations 	::	::	::	::

Matrix myexp(int m, Matrix A);

/* main function, calls myexp and compares with given exp
 * blah
 * blah
 */
int main(int argc, char *argv[])
{
  int m = 2;
  double a[4] = {1, 2, 3, 4};
  Matrix A(m);
  A.fillMatrix(a);
  A.printMatrix();

  double* expAarray = r8mat_expm1(m, a);
  Matrix expA(m);
  expA.fillMatrix(expAarray);
  cout << "given function: exp(A) = " << endl;
  expA.printMatrix();

  Matrix myexpA = myexp(m,A);
  cout << "myexp: exp(A) = " << endl;
  myexpA.printMatrix();


  return 0;
}

/* Function myexp is an implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series. Horners algorithm used as in proj. 1.
 */
Matrix myexp(int m, Matrix A)
{
  Matrix I(m);
  I.identity();
  Matrix res(m);
  res = I;
  for (int i = 100; i > 0; i--)
  {
    res *= A;
    res *= ((double) 1 / (double) i);
    res += I;			// TODO : Använd tol på lämpligt vis
  }
  return res;
}
