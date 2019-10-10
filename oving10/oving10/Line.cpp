#include "Line.h"
#include "Shape.h"
#include "Image.h"
#include <iostream>


Line::Line(int x1, int y1, int x2, int y2, Color color) : Shape(color) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

void Line::draw(Image & img) {
	int y;
	int x;

	double slope = (static_cast<double>((y2 - y1)) / (x2 - x1));
	double slope2 = (static_cast<double>((x2 - x1)) / (y2 - y1));

	if (slope >= 1.0 || slope <= -1.0) {
		for (int y = y1; y <= y2; y++) {
			
			x =  slope2 * (y - y1) + x1;
			img.setPixelColor(x, y, getColor());
		}
	}
	else {
		for (int x = x1; x <= x2; x++) {
			y = slope * (x - x1) + y1;
			img.setPixelColor(x, y, getColor());
		}
	}
	
	
}

