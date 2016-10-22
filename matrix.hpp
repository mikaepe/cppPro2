/* Matrix class
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<cmath>

class Matrix {

private:
    int m;
    double **a;

public:
    // CONSTRUCTORS
    Matrix() {};            // Default constructor

    Matrix(int mm) : m(mm) {        // Initializes m and a... (?)
        a = new double *[m];
        for (int i = 0; i < m; i++) {
            a[i] = new double[m];
            for (int j = 0; j < m; j++) {
                a[i][j] = 0;
            }
        }
    }

    // copy constructor
    Matrix(const Matrix &M) {
        m = M.m;
        a = new double *[m];
        for (int i = 0; i < m; i++) {
            a[i] = new double[m];
            for (int j = 0; j < m; j++) {
                a[i][j] = M.a[i][j];
            }
        }
    }

    // destructor
    ~Matrix() {
        for (int i = 0; i < m; i++) {
            delete[] a[i];
        }
        delete[] a;
        a = NULL;
    }

    // OPERATOR OVERLOADINGS
    Matrix &operator=(const Matrix &M) {
        if (this == &M) {
            return *this;
        }
        if (m == M.m) { // if same dimension, can just change the elements in a
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = M.a[i][j];
                }
            }
        } else {
            if (!a) { // if a initialized, delete a
                for (int i = 0; i < m; i++) {
                    delete[] a[i];
                }
                delete[] a;
            }
            m = M.m;
            a = new double *[m];
            for (int i = 0; i < m; i++) {
                a[i] = new double[m];
                for (int j = 0; j < m; j++) {
                    a[i][j] = M.a[i][j];
                }
            }
        }
        return *this;
    }

    Matrix &operator+=(const Matrix &M) {
        if (m != M.m) {
            std::cerr << "Matrix dimensions mismatch in sum, exiting.." << std::endl;
            exit(1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] += M.a[i][j];
            }
        }
        return *this;
    }

    // operators *= and "*"
    const Matrix operator*=(const Matrix &M) {
        if (m != M.m) {
            std::cerr << "Matrix dimensions mismatch in sum, exiting.." << std::endl;
            exit(1);
        }
        double **temp_a = new double *[m];
        for (int i = 0; i < m; i++) {
            temp_a[i] = new double[m];
            for (int j = 0; j < m; j++) {
                temp_a[i][j] = 0;
                for (int l = 0; l < m; l++) {
                    temp_a[i][j] += a[i][l] * M.a[l][j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            delete[] a[i];
        }
        delete[] a;
        a = temp_a;

        return *this;

    }

    const Matrix operator*=(const double d) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] *= d;
            }
        }
        return *this;

    }

    const Matrix operator*(const Matrix &M) const {
        if (m != M.m) {
            std::cerr << "Matrix dimensions mismatch in sum, exiting.." << std::endl;
            exit(1);
        }

        Matrix C(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < m; l++) {
                    C.a[i][j] += a[i][l] * M.a[l][j];
                }
            }
        }
        return C;

    }


    // FUNCTIONS
    void fillTestMatrix() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = i * j;
            }
        }
    }

    void fillMatrix(double b[]) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = b[j * m + i];
            }
        }
    }

    void makeMatrix() {
      for (int i = 0; i < m; i++) {
	std::cout << "row " << i+1 << ":" << std::endl;
	std::cout << "(elements separated by blanks)" << std::endl;
	for (int j = 0; j < m; j++) {
	  std::cin >> a[i][j];
	}
	std::cout << std::endl;
      }
    }

    void identity() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 0;
                }
            }
        }
    }

    void printMatrix() {
        std::cout << "[";
        for (int i = 0; i < m; i++) {
            if (i != 0) {
                std::cout << " ";
            }
            for (int j = 0; j < m; j++) {
                std::cout << a[i][j];
                if (j != m - 1) {
                    std::cout << ", ";
                }
            }
            if (i != m - 1) {
                std::cout << std::endl;
            }
        }
        std::cout << "]" << std::endl;
    }

    // norm using inf norm
    double norm() {
        double norm = 0, temp_sum;
        for (int i = 0; i < m; i++) {
            temp_sum = 0;
            for (int j = 0; j < m; j++) {
                temp_sum += fabs(a[i][j]);
            }
            if (temp_sum > norm) {
                norm = temp_sum;
            }
        }
        return norm;
    }

};

#endif
