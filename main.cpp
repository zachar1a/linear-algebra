#include <iostream>
#include "inc/matrix.hpp"
#include "inc/linalg.hpp"
#include "inc/more.hpp"


int main(){


	matrix m5(3,3);

	m5.randomData();
	m5.displayMatrix();

	/*
	m5.data={
		{3,0,2},
		{2,0,-2},
		{0,1,1}
	};
	*/
	printf("inverse for m5: \n\n");
	m5.Inverse();
	m5.displayMatrix();



	return 0;
}
