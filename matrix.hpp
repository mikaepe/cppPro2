/* Matrix class
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{

  private:
    int m;
    double **a;

  public:
    // CONSTRUCTORS
    Matrix() {}; 			// Default constructor

    Matrix(int mm) : m(mm) {		// Initializes m and a... (?)
      a = new double * [m];
      for (int i = 0; i < m; i++) {
	a[i] = new double[m];
	for (int j=0; j<m; j++) {
	  a[i][j] = 0;
	}
      }
    }

    // TODO copy constructor and deconstructors
      
    // OPERATOR OVERLOADINGS
    Matrix& operator=(const Matrix& M) {
      if (this != &M) {
	a = M.a;
	m = M.m;
      }
      return *this;
    }

    Matrix& operator+=(const Matrix& M){
      if (m != M.m) {
	std::cerr << "Matrix dimensions mismatch in sum, exiting.." << std::endl;
	exit(1);
      }
      for (int i = 0; i < m; i++){
	for (int j = 0; j < m; j++){
	  a[i][j] += M.a[i][j];
	}
      }
      return *this;
    }

    // TODO operators *= and "*"
    

    // FUNCTIONS
    void fillTestMatrix() {
      for (int i = 0; i<m; i++) {
	for (int j = 0; j<m; j++) {
	  a[i][j] = i*j;
	}
      }
    }
    
    void fillMatrix(double b[]) {
      for (int i = 0; i<m; i++) {
	for (int j = 0; j<m; j++) {
	  a[i][j] = b[j*m+i];
	}
      }
    }

    void identity() {
      for (int i = 0; i<m; i++) {
	for (int j = 0; j<m; j++) {
	  if (i == j) {
	    a[i][j] = 1;
	  }
	  else {
	    a[i][j] = 0;
	  }
	}
      }
    }

    void printMatrix() {
      std::cout << "[" ;
      for (int i = 0; i<m; i++) {
	for (int j = 0; j<m; j++) {
	  std::cout << a[i][j] << ", ";
	}
	std::cout << std::endl;
      }
      std::cout << "]" << std::endl;
    }

    // TODO norm

};

#endif
