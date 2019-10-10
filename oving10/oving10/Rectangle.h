#pragma once
#include "Shape.h"

class Rectangle : public Shape {
	private:
		int ax;
		int ay;
		int bx;
		int by;
		int cx;
		int cy;
		int dx;
		int dy;
	public:
		Rectangle(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, Color color);
		virtual void lineDraw(int x1, int x2, int y1, int y2, Image &img);
		virtual void draw(Image &img);
};