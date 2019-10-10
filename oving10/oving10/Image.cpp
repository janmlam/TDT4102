#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( int width, int height ) {
	data = new Color[width*height];
	this->width = width;
	this->height = height;
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
}

int Image::getWidth() const {
	return this->width;
}
int Image::getHeight() const  {
	return this->height;
}

const Pixel * Image::getScanLine(int line) const  {
	return &data[width*line];
}
Pixel * Image::getScanLine(int line) {
	return data + width * line;
	//return &data[width*line];
}

Color Image::getPixelColor( int x, int y ) const {
	return Color(data[y, x]);
}
void Image::setPixelColor( int x, int y, const Color &color ) {
	data[width*y+x] = color; 
}

void Image::fill( const Color &color ) {
	for (int i = 0; i < width*height; i++) {
		data[i] = color;
	}
}
