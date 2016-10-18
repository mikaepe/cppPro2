#include <iostream>
#include <cstdlib>
#include "matrix.hpp"

using namespace std;

int main(void) {
    Matrix m(4);
    cout << "Print 1: " << endl;
    m.printMatrix();
    m.fillTestMatrix();
    cout << "Print 2: " << endl;
    m.printMatrix();

    double b[16];

    for (int i = 0; i < 16; i++) {
        b[i] = i;
    }
    m.fillMatrix(b);
    cout << "Print 3: " << endl;
    m.printMatrix();

    Matrix mm;
    Matrix mmm(m);
    mm = m;
    m.identity();
    m *= mm;
    cout << "Print 4: " << endl;
    m.printMatrix();


    double n = m.norm();
    cout << "Norm 1: " << n << endl;

  cout << "Print 5: " << endl;
  mmm.printMatrix();

  return 0;
}
