#include <iostream>

#include "inc/matrix.hpp"
#include "inc/linalg.hpp"
#include "inc/more.hpp"


int main(){

	matrix m1(2,3);
	matrix m2(3,1);

	linalg la;

	m1.randomData();
	m1.displayMatrix();

	// these are the coefficients for the system of equations
	m1.data = {
		{2,4,2},
		{6,1,8},
		{4,2,1}
	};

	// using m2 as my end values for m1
	m2.data={
		{1},
		{2},
		{3}
	};

	m1.displayMatrix();
	m2.displayMatrix();

	la.solveSystemOfEquations(m1);

	return 0;
}
