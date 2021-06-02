#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "matrix.hpp"

void matrix::displayMatrix(){
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j<this->col; j++){
			std::cout << this->data[i][j] << " ";
		}
		std::cout << '\n';
	}
}
//
// This is helping me set pseudo random data so I can initialize
// matrixes faster that I can use with these algorithms
//
void matrix::randomData(){
	srand(time(NULL));
	for(int i = 0; i < this->row; i++){
		for(int j = 0 ; j < this->col; j++){
			this->data[i][j] = rand()%10;
		}
	}
}

//
// multiplies a matrix by a scalar value
//
void matrix::scalar(double scalar){
	for(int i = 0; i < this->row; i++)
		for(int j = 0 ; j< this->col; j++)
			 this->data[i][j] *= scalar;
}

// 
// simple addition of two matrices
//
void matrix::addition(matrix &m2){
	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < this->col; j++)
			this->data[i][j] = this->data[i][j]+m2[i][j];
}

// 
// simple subtraction of two matrices
//
void matrix::subtraction(matrix &m2){
	matrix ms(this->row, this->col); 
	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < this->col; j++)
			ms[i][j] = this->data[i][j]-m2[i][j];
	*this = ms;
}

//
// multiplies two matrixes together 
// and returns a new matrix with
// dimensions   m1.row,m2.col
//
void matrix::multiplication(matrix &m2){
	matrix mProduct(this->row, this->col);

	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < m2.col; j++)
			for(int k = 0; k < this->col; k++)
				mProduct[i][j] += this->data[i][k] * m2[k][j];
	*this = mProduct;
}

// 
// compares row and col values for easy false detection
// then compares each value
//
bool matrix::matrixAreEqual(matrix &m2){
	if(this->row != m2.row || this->col != m2.col)
		return false;

	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < this->col; j++)
			if(this->data[i][j] != m2[i][j])
				return false;
	return true;
}

//
// this returns the identity matrix
// if it exists for the given matrix
//
matrix matrix::identity(){
	try{!this->square() ? throw "Matrix is not square() therefore has no identity matrix" : this->square();}
	catch(const char *e){std::cerr << e << std::endl;}

	matrix mIdentity(this->row, this->col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			if(i == j){
				mIdentity[i][j] = 1;
			}
		}
	}

	return mIdentity;
}

// 
// this converts the current matrix
// into its transposed form
//
void matrix::T(){
	matrix mTranspose(this->col, this->row);
	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < this->col; j++)
			mTranspose[j][i] = this->data[i][j];

	*this = mTranspose;
}


double matrix::determinent(){
	// basic checks to see if we can even find determinent
	if(!this->square())
		return -1.0;
	if(this->row > 3)
		return -1.0;

	if(this->row == 2)
		return (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]);

	if(this->row == 3){
		// a
		double det_a = this->data[0][0] *((this->data[1][1] * this->data[2][2]) - (this->data[1][2] * this->data[2][1]));
		double det_b = this->data[0][1] *((this->data[1][0] * this->data[2][2]) - (this->data[1][2] * this->data[2][0]));
		double det_c = this->data[0][2] *((this->data[1][0] * this->data[2][1]) - (this->data[1][1] * this->data[2][0]));
		return det_a - det_b + det_c;
	}

	return -1.0;
}

matrix matrix::adjoint(){
	matrix adjointMatrix(this->row, this->col);

	if(this->row == 2){
		// adjoint for 2x2 goes here
	}

	if(this->row == 3){
		// adoint for 3x3 goes here
		auto data = this->data;

		double a11 =   (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]);
		double a12 = -((data[1][0] * data[1][2]) - (data[2][0] * data[2][2]));
		double a13 =   (data[1][0] * data[1][1]) - (data[2][0] * data[2][1]);

		double a21 = -((data[0][1] * data[2][2]) - (data[0][2] * data[2][1]));
		double a22 =   (data[0][0] * data[2][2]) - (data[0][2] * data[2][0]);
		double a23 = -((data[0][0] * data[2][1]) - (data[0][1] * data[2][0]));

		double a31 =   (data[0][1] * data[1][2]) - (data[0][2] * data[1][1]);
		double a32 = -((data[0][0] * data[1][2]) - (data[0][2] * data[1][0]));
		double a33 =   (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);

		adjointMatrix.data = {
			{a11,a12,a13},
			{a21,a22,a23},
			{a31,a32,a33}
		};

	}


	if(this->row != 2 && this->row != 3){
		adjointMatrix.row = 1;
		adjointMatrix.col = 1;
		adjointMatrix.data = {{-1}};

		return adjointMatrix;
	}
	return adjointMatrix;
}


// 
// work in progress
//
/*
void matrix::matrixInverse(matrix &m1){
	try{(!m1.square()) ? throw "Matrix has no inverse!": m1.square();}
	catch(const char *e){std::cerr << e << std::endl;}
		
	matrix mInverse(m1.col,m1.row);
	if(m1.row==2){
		double determinent = 1/((m1[0][0]*m1[1][1])-(m1[0][1]*m1[1][0]));

		mInverse[0][0] = m1[1][1];
		mInverse[0][1] = (m1[0][1]* -1);

		mInverse[1][0] = (m1[1][0]* -1);
		mInverse[1][1] = m1[0][0];
		scalarMultiplication(determinent);
		m1=mInverse;
	}
}
*/
