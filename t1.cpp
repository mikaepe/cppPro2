/* SF2565 Project 2, Hanna Hultin & Mikael Persson.
 * Task 1: Compute exp(x) for real numbers
 */


// Libraries	::	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>


// Function Declarations 	::	::	::	::

double myexp(double x, double tol=1e-10);	
double myexpHorner(double x);

// Function Definitions		::	::	::	::

using namespace std;

/* main function, calls myexp and compares with cmath exp
 */
int main(int argc, char *argv[])
{
  double x;
  cout << "x = "; cin >> x;
  cout << fixed << setprecision(12);
  

  double expx = exp(x);
  double myexpH = myexpHorner(x);
  double myexpx = myexp(x);

  cout << "cmath:  exp(x) = " << expx << endl;
  cout << "myexp:  exp(x) = " << myexpx << endl;
  cout << "myexpH: exp(x) = " << myexpH << endl;
 
  return 0;
}


/* Function myexp is an straight forward implementation of the exponential
 * functions series representation i.e. the McLaurin
 * series without Horners algorithm
 */
double myexp(double x, double tol)
{
    double res = 1;
    double term = 1;
    for (int i = 1; i<1000; i++)
    {
        term *= (x/ (double) i);
        if (abs(term) < tol){
	  cout << "iterations performed     (WoH): " << i << endl;
	  res += term;
	  break;
        }
        res += term;
    }
    return res;
}

/* Implementation of Horners algorithm to compare with
 */
double myexpHorner(double x)
{
  double res = 1;
  for (int i = 40; i>0; i--)
  {					// Horners algorithm (to avoid
    res = 1+x*res/i;		// adding small doubles to large)
  }
  

  return res;
}
