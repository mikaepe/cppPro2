/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 1: Compute exp(x) for real numbers
 */


// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>


// Function Declarations 	::	::	::	::

double myexp(double x, double tol=1e-14);
double myexpWoH(double x, double tol=1e-14);


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
  

  double expx = exp(x);
  double myexpx = myexp(x);
  double myexpxwoH = myexpWoH(x);

  cout << "cmath:    exp(x) = " << expx << endl;
  cout << "myexp:    exp(x) = " << myexpx << endl;
  cout << "myexpwoH: exp(x) = " << myexpxwoH << endl;


  return 0;
}


/* NEW IMPLENTATION OF HORNERS WITH TOL
 */
double myexp(double x, double tol)
{
  int req_iter = 2;			// requested iterations
  double res1 = 1, res2 = 0;		// initialize values to start looping
  int maxiter = 100;			// max iterations to be performed

  // stop when the last term is less than tolerance i.e. abs(res1-res2)
  while (req_iter < maxiter && abs(res1-res2) > tol)
  {
    req_iter ++;
    res2 = res1;
    res1 = 1;
    for (int i = req_iter; i>0; i--)
    {					// Horners algorithm (to avoid
      res1 = 1+x*res1/i;		// adding small doubles to large)
    }
  }

  if (req_iter == maxiter)
  {
    cout << "max iterations performed, tolerance not attained" << endl;
  }
  cout << "iterations performed (Horners): " << req_iter << endl;

  return res1;
}


/* Function myexpWoH is an straight forward implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series without Horners algorithm
 */
double myexpWoH(double x, double tol)
{
    double res = 1;
    double term = 1;
    for (int i = 1; i<1000; i++)
    {
        term *= (x/ (double) i);
        if (term < tol){
	  cout << "iterations performed     (WoH): " << i << endl;
	  break;
        }
        res += term;
    }
    return res;
}
