#include <iostream>
#include <cstdlib>
#include "matrix.hpp"

using namespace std;

int main(void){
  Matrix m(4);
  m.printMatrix();
  m.fillTestMatrix();
  m.printMatrix();
  
  double b[16];

  for (int i = 0; i<16; i++) {
    b[i] = i;
  }
  m.fillMatrix(b);
  m.printMatrix();

  Matrix mm;
  mm = m;
  mm.printMatrix();

  mm += mm;
  mm.printMatrix();

  return 0;
}
