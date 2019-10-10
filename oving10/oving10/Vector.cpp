#include "Vector.h"
#include <cmath>

Vector::Vector() : Matrix() {

}

Vector::Vector(int nRows) : Matrix(nRows, 1, 0.0) {

}

Vector::Vector(const Matrix & other) {
	if (other.getColumns() == 1 && other.isValid()) {
		Matrix::operator = (other);
	}
	else {
		Matrix temp = Matrix(other);
		temp.invalidate();
		Matrix::operator = (temp);
	}
}

void Vector::set(int row, double value) {
	at(row, 0) = value;
}

double Vector::get(int row) const {
	return at(row, 0);
}

double Vector::dot(const Vector & rhs) const{
	double dotProduct = 0.0;
	Vector lhs = *this;
	if (lhs.getRows() != rhs.getRows()) {
		return nan("");
	} else {
		for (int i = 0; i < rhs.getRows(); i++) {
			dotProduct += lhs.get(i) * rhs.get(i);
		}
	}
	return dotProduct;
}

double Vector::lengthSquared() const {
	Vector vector1 = *this;
	return vector1.dot(vector1);
}

double Vector::length() const {
	Vector vector1 = *this;
	return (sqrt(vector1.lengthSquared()));
}
