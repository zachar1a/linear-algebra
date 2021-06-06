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

matrix matrix::dot(matrix &m1){
	std::vector<double>tmp;
	matrix prod(m1.row, this->col);

	for(int i = 0; i < m1.row; i++ ){
		double p = 0;
		for(int j = 0; j < this->col; j++ ){
			p+= this->data[i][j] * m1.data[i][j];
			tmp.push_back(p);
		}
	}
	for(int i = 0; i < m1.row; i++)
		for(int j = 0; j < this->col; j++)
			prod[i][j]=tmp[i+j];
	return prod;
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


//
// det()
// returns the determinent of the matrix
//
double matrix::det(){
	// basic checks to see if we can even find determinent
	if(!this->square())
		return -1.0;
	if(this->row > 3)
		return -1.0;

	if(this->row == 2)
		// The plus zero is at the end because if an operation occurs where a
		// (double)0 is multiplited by a negative number it returns a negative 0
		// this is mainly stylistic as I don't want to see a negative 0 ind displayMatrix()
		return (this->data[0][0] * this->data[1][1]) - (this->data[1][0] * this->data[0][1]) + 0;

	if(this->row == 3){
		// a
		double det_a = this->data[0][0] *((this->data[1][1] * this->data[2][2]) - (this->data[1][2] * this->data[2][1]));
		double det_b = this->data[0][1] *((this->data[1][0] * this->data[2][2]) - (this->data[1][2] * this->data[2][0]));
		double det_c = this->data[0][2] *((this->data[1][0] * this->data[2][1]) - (this->data[1][1] * this->data[2][0]));
		return det_a - det_b + det_c;
	}

	return -1.0;
}

//
// adj()
// This finds the adjoint of a matrix
// it is applied to the matrix that called
// it and assigns the values equal to that
// of the adjoint matrix
//
void matrix::adj(){
	if(this->row == 2){
		this->data = {
			{this->data[1][1],-this->data[0][1]},
			{-this->data[1][0],this->data[0][0]}
		};
	}

	if(this->row == 3){

		// Label matrix indices for easier access
		double a = this->data[0][0];
		double b = this->data[0][1];
		double c = this->data[0][2];
		double d = this->data[1][0];
		double e = this->data[1][1];
		double f = this->data[1][2];
		double g = this->data[2][0];
		double h = this->data[2][1];
		double i = this->data[2][2];
		// Create each sub matrices to find the cofactor of the tmp index
		// i.e matrix[0][0] cofactor needs matrix:
		//
		// [e f]
		// [h i]
		// det = ie - fh;
		// then find the determinent and that is the new value
		matrix tmp00(2,2);
		tmp00.data = {{e,f},{h,i}};
		matrix tmp01(2,2);
		tmp01.data={{c,b},{i,h}};
		matrix tmp02(2,2);
		tmp02.data={{b,c},{e,f}};
		matrix tmp10(2,2);
		tmp10.data = {{f,d},{i,g}};
		matrix tmp11(2,2);
		tmp11.data = {{a,c},{g,i}};
		matrix tmp12(2,2);
		tmp12.data = {{c,a},{f,d}};
		matrix tmp20(2,2);
		tmp20.data = {{d,e},{g,h}};
		matrix tmp21(2,2);
		tmp21.data = {{b,a},{h,g}};
		matrix tmp22(2,2);
		tmp22.data = {{a,b},{d,e}};

		a = tmp00.det();
		b = tmp01.det();
		c = tmp02.det();
		d = tmp10.det();
		e = tmp11.det();
		f = tmp12.det();
		g = tmp20.det();
		h = tmp21.det();
		i = tmp22.det();

		this->data={
			{a,b,c},
			{d,e,f},
			{g,h,i}
		};
	}


	if(this->row != 2 && this->row != 3)
		return;
}


//
// Inverse()
// is applied to the matrix that is calling it
// setting the values equal to the inverse of
// the matrix
//
void matrix::inverse(){
	double det = this->det();

	if(this->row == 2){
		this->data={
			{this->data[1][1],-this->data[0][1]},
			{-this->data[1][0],this->data[0][0]},
		};
		this->scalar(1/det);
	}
	if(this->row == 3){
		this->adj();
		this->scalar(1/det);
	}
}
