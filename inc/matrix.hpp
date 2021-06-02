#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

struct matrix{
	int col, row;
	typedef std::vector<double> Row;
	// this vector is a vector of vector
	std::vector<Row>data;

	matrix(int r, int c): col(c), row(r), data(r, std::vector<double>(c))
       	{ col == row ? isSquare=true : isSquare=false;}
	Row &operator[](int i){
		return data[i];
	}

	bool square(){ return isSquare; }
	void displayMatrix();
	void randomData();
	bool matrixAreEqual(matrix &m2);
	void T();
	void scalar(double scalar);
	void addition(matrix &m2);
	void subtraction(matrix &m2);
	void multiplication(matrix &m2);

	matrix identity();

	// in order to get the inverse
	// going i am going to have to make
	// a function to find the determinent
	// of a matrix and then i am going to
	// have to make another function to get
	// the adjunct matrix
	void matrixInverse(matrix &m1);

	matrix adjoint();
	double determinent();
	private:
	bool isSquare;
};



#endif
