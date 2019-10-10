#include "Shape.h"

Shape::Shape(Color color) {
	this->color = color;
}

Color Shape::getColor(){
	return this->color;
}
