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

#include "r8lib.cpp"
//#include "r8lib.h"		// Behövs inte (r8lib.cpp öppnar den)
#include "r8mat_expm1.cpp"
//#include "r8mat_expm1.h"	// Behövs inte heller

// Function Declarations 	::	::	::	::

Matrix myexp(int m, Matrix A);
Matrix myexpWoH(int m, Matrix A, double tol=1e-10);

/* main function, calls myexp and compares with given exp
 * blah
 * blah
 */
int main(int argc, char *argv[])
{
  int m = 3;
  double a[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  /* NILPOTENT:
  int m = 3;
  double a[16] = {0,0,0,2,0,0,1,2,0};
  */
  Matrix A(m);
  A.fillMatrix(a);
  A.printMatrix();
  
  cout << fixed << setprecision(5);

  double* expAarray = r8mat_expm1(m, a);
  Matrix expA(m);
  expA.fillMatrix(expAarray);
  cout << "given function: exp(A) = " << endl;
  expA.printMatrix();

  Matrix myexpA = myexp(m,A);
  cout << "myexp: exp(A) = " << endl;
  myexpA.printMatrix();
  
  Matrix myexpAwoH = myexpWoH(m,A);
  cout << "myexpwoH: exp(A) = " << endl;
  myexpAwoH.printMatrix();

  Matrix M(A.sizeMatrix());
  M = expA;
  M -= myexpA;
  double n1 = M.norm();
  M = expA;
  M -= myexpAwoH;
  double n2 = M.norm();

  cout << fixed << setprecision(15);

  cout << "norm matlab-horner = " << n1 << endl;
  cout << "norm matlab-woH    = " << n2 << endl;

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


/* Function myexpWoH is an straight forward implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series without Horners algorithm
 */
Matrix myexpWoH(int m, Matrix A, double tol)
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
