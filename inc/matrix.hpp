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

	matrix operator+(matrix &m1){
		matrix add(this->row,this->col);
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				add[i][j] = this->data[i][j] + m1.data[i][j];
		return add;
	}


	void operator+=(matrix &m1){
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				this->data[i][j] = this->data[i][j] + m1.data[i][j];


	}

	matrix operator-(matrix &m1){
		matrix sub(this->row,this->col);
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				sub[i][j] = this->data[i][j] - m1.data[i][j];
		return sub;
	}

	void operator-=(matrix &m1){
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				this->data[i][j] = this->data[i][j] - m1.data[i][j];
	}

	matrix operator*(matrix &m1){
		matrix mult(this->row,this->col);
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				mult[i][j] = this->data[i][j] * m1.data[i][j];
		return mult;
	}
	void operator*=(matrix &m1){
		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				this->data[i][j] = this->data[i][j] * m1.data[i][j];
	}



	bool square(){ return isSquare; }
	void displayMatrix();
	void randomData();
	bool matrixAreEqual(matrix &m2);
	void T();
	void scalar(double scalar);

	matrix identity();

	// in order to get the inverse
	// going i am going to have to make
	// a function to find the determinent
	// of a matrix and then i am going to
	// have to make another function to get
	// the adjunct matrix
	void Inverse();

	void adj();
	double det();
	private:
	bool isSquare;
};



#endif
