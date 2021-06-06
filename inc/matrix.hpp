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

	bool operator==(matrix &m1){
		if(this->row != m1.row || this->col != m1.col)
			return false;

		for(int i = 0; i < this->row; i++)
			for(int j = 0; j < this->col; j++)
				if(this->data[i][j] != m1[i][j])
					return false;
		return true;
	}



	void T();
	void scalar(double scalar);

	matrix dot(matrix &m1);
	void adj();
	double det();
	void inverse();

	matrix identity();
	void displayMatrix();
	bool square(){ return isSquare; }
	void randomData();
	private:
	bool isSquare;
};



#endif
