/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 1: Compute exp(x) for real numbers
 */


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
  cout << "cmath: exp(x) = " << expx << endl;

  double myexpx = myexp(x);
  cout << "myexp: exp(x) = " << myexpx << endl;


  return 0;
}

/* Function myexp is an implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series. Horners algorithm used as in proj. 1.
 */
double myexp(double x, double tol)
{
  double res;
  res = 1;
  for (int i = 10; i > 0; i--)
  {
    res = 1+x*res/i;			// TODO : Använd tol på lämpligt vis
  }
  return res;
}
