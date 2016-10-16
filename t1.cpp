

// Libraries	::	::	::	::	::	::
#include<iostream>
#include<cmath>
#include<iomanip>

// Function Declarations 	::	::	::	::

double myexp(double x, double tol=1e-10);


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
  cout << fixed << setprecision(12);
  double expx = exp(x);

  cout << "cmath:  exp(x) = " << expx << endl;


  return 0;
}

/* Function myexp is an implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series.
 */
double myexp(double x, double tol)
{
  double res;
  res = 1;
  for (int i = 10; i > 0; i--)
  {
    res = 1+x*res/i;
  }
  return res;
}
