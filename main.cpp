#include <iostream>
#include "inc/matrix.hpp"
#include "inc/linalg.hpp"
#include "inc/more.hpp"


int main(){


	matrix m5(3,3);
	matrix m3(3,3);

	m5.randomData();
	m5.displayMatrix();
	printf("\n\n");

	m3.data={
		{3,0,2},
		{2,0,-2},
		{0,1,1}
	};
	m3.displayMatrix();
	printf("\n\n");


	m5+=m3;
	m5.displayMatrix();




	return 0;
}
