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



  cout << "testa fylla i matris...." << endl;
  int sizE;
  cout << "size of square matrix: "; cin >> sizE;
  Matrix mm2(sizE);
  mm2.makeMatrix();
  mm2.printMatrix();
  n = mm2.norm();
  cout << "Norm 1: " << n << endl;

  /* Funkar inte
  Matrix mm3;
  mm3 = (mm2 + mm2);
  cout << "Print 6:" << endl;
  mm3.printMatrix();
  */

  Matrix mm3 = mm2;
  mm3 -= mm2;
  cout << "Print 6: " << endl;
  mm3.printMatrix();

  Matrix mm4(mm2.sizeMatrix());
  mm4 -= mm2;
  cout << "Print 7: " << endl;
  mm4.printMatrix();
  

  return 0;
}
