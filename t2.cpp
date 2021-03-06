/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 2: Compute exp(A) for square matrices
 */


// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include "matrix.hpp"

using namespace std;

#include "r8lib.cpp"
#include "r8mat_expm1.cpp"

// Function Declarations 	::	::	::	::

Matrix myexp(int m, Matrix A, double tol=1e-10);

// Function Definitions	::	::	::	::	::

/* main function, asks user to input matrix, then
 * calls myexp and compares with given expm from r8
 */
int main(int argc, char *argv[])
{
  cout << "Size of square matrix: ";	// Ask user for size
  int m; cin >> m; double a[m*m];
  cout << "(elements separated by blanks)" << endl;
  for (int i = 0; i < m; i++){		// Array to fill matrix
    cout << "row " << i+1 << ":" << endl;
    for (int j = 0; j < m; j++){
      cin >> a[i+j*m];
    }
  }
  Matrix A(m); A.fillMatrix(a);		// Own Matrix class
  cout << "A = " << endl; A.printMatrix();
  
  cout << fixed << setprecision(5);

  double* expAr8 = r8mat_expm1(m, a);	// r8 implementation
  Matrix expA(m);
  expA.fillMatrix(expAr8);
  cout << "given function: exp(A) = " << endl;
  expA.printMatrix();

  Matrix myexpA = myexp(m,A);
  cout << "own implementation: exp(A) = " << endl;
  myexpA.printMatrix();

  Matrix M(A.sizeMatrix());
  M = expA;
  M -= myexpA;
  double n = M.norm();			// For comparison

  cout << fixed << setprecision(15);

  cout << "norm expA-myexpA = " << n << endl;

  return 0;
}

/* Function myexp is an straight forward implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series without Horners algorithm
 */
Matrix myexp(int m, Matrix A, double tol)
{
    double norm = 1.0;
    Matrix term(m);
    Matrix res(m);
    term.identity();
    res.identity();
    int i = 1;
    while (norm > tol)
    {
        term *= A;
        term *= ((double) 1 / (double) i);
        norm = term.norm();
        res += term;
        i++;
    }
    return res;
}
