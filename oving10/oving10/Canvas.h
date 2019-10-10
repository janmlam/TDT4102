#pragma once
#include "Shape.h"
#include <iostream>
#include <vector>
#include "Line.h"

class Canvas {
	private:
		std::vector<Shape*> s;
	public:
		void addShape(Shape &s);
		virtual void rasterizeTo(Image &img);
};