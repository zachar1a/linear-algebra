#include <iostream>
#include "inc/matrix.hpp"
#include "inc/linalg.hpp"
#include "inc/more.hpp"


int main(){


	matrix m1(3,3);
	matrix m2(1,3);

	m1.data={
		{1,1,1},
		{0,2,5},
		{2,5,-1}
	};
	m2.data={
		{6},
		{-4},
		{27}
	};

	matrix dot = m1.dot(m2);

	double det = m1.det();

	m1.inverse();
	m1.displayMatrix();

	printf("\n\n\n");
	dot.displayMatrix();





	return 0;
}
