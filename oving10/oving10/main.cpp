/*#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "Vector.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Canvas.h"
*/

//inkluder andre headerfiler du lager
using namespace std;
#include <iostream>

int main(){
	int a = 3.6;
	int b = 3.1;
	std::cout << a;
	return 0;
}


/*
///*Vector vector1(3);
//vector1.set(2, 5.0);
//vector1.set(0, 5.0);
//vector1.set(1, 5.0);
//Matrix matrix2(3, 3, 8.0);
//std::cout << matrix2 << " * " << std::endl << vector1 <<  " = " << std::endl << matrix2*vector1 << std::endl;
//*/


/*Image test(100, 100);
test.fill(Color(193, 84, 193));
saveImage(test, "test.bmp");

Image test2(100, 100);
test2.fill(Color(255, 255, 255));
test2.setPixelColor(50, 50, Color(255, 0, 0));
saveImage(test2, "test2.bmp");*/


//
//Image test4(250, 250);
//Line line(0,100,50,200,Color(255,0,0));
//line.draw(test4);
//saveImage(test4, "test4.bmp");
//

/*
Image test5(250, 250);
Rectangle rectangle(0,0,100,0,100,60,0,60,Color(255,0,0));
rectangle.draw(test5);
saveImage(test5, "test5.bmp");


Canvas c;
Image last(400, 400);


Line line3(80, 200, 80, 250, Color(255, 0, 0));
Line line4(220, 200, 220, 250, Color(255, 0, 0));


Line line5(60, 120, 160, 40, Color(255, 0, 0));
Line line6(160, 40, 240, 120, Color(255, 0, 0));

c.addShape(line3);
c.addShape(line4);
c.addShape(line5);
c.addShape(line6);
c.rasterizeTo(last);
saveImage(last, "last.bmp");
*/