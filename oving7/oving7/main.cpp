#include "fibo.h"
#include "Matrix.h"
#include "Dummy.h"
#include <iostream>
using namespace std;

int main() {
	int a = 4;
	int b = 9;
	int c = ++b;
	int d = b++ / c++;
	int e = (16.7 / a);
	std::cout << e << std::endl;
	return 0;
}


/*
//createFibonacci();
dummyTest();

///*Matrix asd = Matrix(2,2);
//asd.set(0, 0, 1.);
//asd.set(0, 1, 2.);
//asd.set(1, 0, 3.);
//asd.set(1, 1, 4.);
//Matrix asd2 = Matrix(2, 2);
//asd2.set(0, 0, 4.);
//asd2.set(0, 1, 3.);
//asd2.set(1, 0, 2.);
//asd2.set(1, 1, 1.);
//Matrix asd3 = Matrix(2, 2);
//asd3.set(0, 0, 1.);
//asd3.set(0, 1, 3.);
//asd3.set(1, 0, 1.5);
//asd3.set(1, 1, 2.);

//asd += asd2 + asd3;
//std::cout << asd << std::endl;*/