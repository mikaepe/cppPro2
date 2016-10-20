/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 1: Compute exp(x) for real numbers
 */


// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>


// Function Declarations 	::	::	::	::

double myexp(double x, double tol=1e-10);
double expTaylor(double x, int iter);


// Function Definitions		::	::	::	::

using namespace std;

/* main function, calls myexp and compares with cmath exp
 * blah
 * blah
 */
int main(int argc, char *argv[])
{
  double x;
  cout << "x = "; cin >> x;
  cout << fixed << setprecision(15);
  double tol;
  cout << "tol = "; cin >> tol;
 
  double myexpx = myexp(x, tol);
  cout << "myexp: exp(x) = " << myexpx << endl;
 
  double expx = exp(x);
  cout << "cmath: exp(x) = " << expx << endl;

  return 0;
}

double myexp(double x, double tol)
{
  int iter = 2;
  double res1 = 1, res2 = 0;
  int maxiter = 100;

  while (iter < maxiter && abs(res1-res2) > tol*0.1)
  {
    iter ++;
    res2 = res1;
    res1 = expTaylor(x,iter);
  }

  if (iter == maxiter)
  {
    cout << "no convergence, exiting..." << endl;
    exit(1);
  }
  cout << iter << endl;
  return res1;
}

double expTaylor(double x, int iter)
{
  double res = 1;
  for (int i = iter; i > 0; i--)
  {
    res = 1+x*res/i;		
  }
  return res;
}
