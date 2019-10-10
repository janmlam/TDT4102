#include "Matrix.h"

Matrix::Matrix() {
	this->matrix = nullptr;
}

Matrix::Matrix(int nRows, int nColoumns) {
	this->mRow = nRows;
	this->nCol = nColoumns;
	this->matrix = new double *[nRows];
	for (int m = 0; m < nColoumns; m++) {
		this->matrix[m] = new double [nColoumns];
		for (int n = 0; n < nColoumns; n++) {
			this->matrix[m][n] = 0.;
		}
	}
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows) {
	this->mRow = nRows;
	for (int m = 0; m < nRows; m++) {
		this->matrix[m] = new double[nRows];
		this->matrix[m][m] = 1.;
	}
}

Matrix::~Matrix() {
	delete this->matrix;
	this->matrix = nullptr; 
}

double Matrix::get(int row, int col) const {
	return this->matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
	this->matrix[row][col] = value;
}

int Matrix::getHeight() const {
	return this->nCol;
}

int Matrix::getWidth() const {
	return this->mRow;
}

bool Matrix::isValid() const {
	if (this->matrix == nullptr) {
		return false;
	}
	else {
		return true;
	}
}


std::ostream & operator<<(std::ostream & os, const Matrix & matrix) {
	for (int i = 0; i < matrix.getWidth(); i++) {

		for (int j = 0; j < matrix.getHeight(); j++) {
			os << matrix.get(i, j) << " ";
		}
	}
	return os;
}

Matrix::Matrix(const Matrix & rhs) {
	this->nCol = rhs.getHeight();
	this->mRow = rhs.getWidth();
	this->matrix = new double *[this->nCol];
	for (int m = 0; m < this->nCol; m++) {
		this->matrix[m] = new double[this->nCol];
		for (int n = 0; n < this->nCol; n++) {
			this->matrix[m][n] = rhs.get(m, n);
		}
	}
}

Matrix Matrix::operator=(Matrix & rhs) {
	std::swap(matrix, rhs.matrix);
	return *this;
}

Matrix Matrix::operator+=(const Matrix & rhs) {
	if (isValid() && rhs.isValid() && this->nCol == rhs.getHeight() && this->mRow == rhs.getWidth()) {
		Matrix temp = rhs;
		for (int m = 0; m < mRow; m++) {
			for (int n = 0; n < nCol; n++) {
				this->matrix[m][n] += temp.matrix[m][n];
			}
		}

	}
	else { 
		*this->matrix = nullptr;
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix & rhs) {
	Matrix final(*this);
	final += rhs;
	return final;
}

