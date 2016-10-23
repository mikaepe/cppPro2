# cppPro2

files:
Makefile	- for 'make' command, 'make clean', 'make t1' etc...
matrix.hpp	- Contains the class matrix
t1.cpp		- evaluate myexp(x) using 10-term taylor series
t1new.cpp	- A primitive means of evaluating the taylor series
		  until satisfactory tolerance...
t2.cpp		- same as t1 but for matrices. Compares own implementation
		  with implementation from "r8mat_expm1.h"
testMatrix.cpp	- A bunch of tests for matrix.hpp
r8xxx		- functions to compare with own implementations



TODO: borde fixa så vi kan ta norm(A-B), A & B matriser, för att kunna
kolla på seriernas noggrannhet.
