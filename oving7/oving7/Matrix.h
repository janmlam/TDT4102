#pragma once
#include <iostream>

class Matrix {
	private:
		int mRow;
		int nCol;
		double **matrix;

	public:
		Matrix();
		Matrix(int nRows, int nColoumns);
		explicit Matrix(int nRows);
		~Matrix();
		double get(int row, int col) const;
		void set(int row, int col, double value);
		int getHeight() const;
		int getWidth() const;
		bool isValid() const;
		Matrix(const Matrix & rhs);
		Matrix operator=(Matrix & rhs);
		Matrix operator+=(const Matrix & rhs);
		Matrix operator+(const Matrix & rhs);

};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
