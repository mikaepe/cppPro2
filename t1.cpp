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
 */
int main(int argc, char *argv[])
{
  double x;
  cout << "x = "; cin >> x;		// user input x
  cout << fixed << setprecision(12);	

  double expx = exp(x);			// cmath function
  double myexpx = myexp(x);		// own implementation

  cout << "cmath:  exp(x) = " << expx << endl;
  cout << "myexp:  exp(x) = " << myexpx << endl;
 
  return 0;
}

/* fctn myexp is a straight forward implementation of the exponential
 * series representation i.e. the McLaurin series without Horners algorithm
 */
double myexp(double x, double tol)
{
    double res = 1;
    double term = 1;
    for (int i = 1; i<1000; i++)
    {
        term *= (x/ (double) i);
        if (abs(term) < tol){
	  cout << "iterations performed (myexp): " << i << endl;
	  res += term;
	  break;
        }
        res += term;
    }
    return res;
}

