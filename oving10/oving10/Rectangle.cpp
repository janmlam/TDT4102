#include "Rectangle.h"
#include "Shape.h"
#include "Image.h"

Rectangle::Rectangle(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, Color color) : Shape(color) {
	this->ax = ax;
	this->ay = ay;
	this->bx = bx;
	this->by = by;
	this->cx = cx;
	this->cy = cy;
	this->dx = dx;
	this->dy = dy;
}

void Rectangle::draw(Image & img) {
	lineDraw(ax, ay, bx, by, img);
	lineDraw(ax, ay, dx, dy, img);
	lineDraw(dx, dy, cx, cy, img);
	lineDraw(bx, by, cx, cy, img);
}


void Rectangle::lineDraw(int x1, int y1, int x2, int y2, Image & img) {
	int y;
	int x;
	double slope = (static_cast<double>((y2 - y1)) / (x2 - x1));
	double slope2 = (static_cast<double>((x2 - x1)) / (y2 - y1));
	if (slope >= 1.0 || slope <= -1.0) {
		for (int y = y1; y <= y2; y++) {
			x = slope2 * (y - y1) + x1;
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