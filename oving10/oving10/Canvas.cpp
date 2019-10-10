#include "Canvas.h"
#include "Shape.h"
#include "Image.h"

void Canvas::addShape(Shape & s) {
	this->s.push_back(&s);
}

void Canvas::rasterizeTo(Image & img) {
	for (Shape *sh : s) {
		sh->draw(img);
	}
}
