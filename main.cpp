#include <iostream>
#include "inc/matrix.hpp"
#include "inc/linalg.hpp"
#include "inc/more.hpp"


int main(){


	matrix m1(2,3);
	matrix m2(3,1);
	matrix m3(2,2);
	matrix m4(3,3);
	matrix m5(3,3);

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

	printf("The third matrix\n");
	m3.randomData();
	m3.displayMatrix();

	printf("determinent: %lf\n", m3.determinent());


	printf("The fourth matrix\n");
	m4.randomData();
	m4.displayMatrix();

	printf("determinet: %lf\n", m4.determinent());

	m5.randomData();
	m5.displayMatrix();
	m5.adjoint();

	printf("determinent for m5: %lf\n",m5.determinent());


	return 0;
}
