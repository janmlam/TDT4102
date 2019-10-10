#pragma once
#include "Image.h"

class Shape {
	private:
		Color color;
	public:
		Shape(Color color);
		Color getColor();
		virtual void draw(Image &img)=0;
};