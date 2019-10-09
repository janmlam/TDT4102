#include <iostream>
#include <iomanip>
#include <cmath>
//using namespace std;


void inputAndPrintInteger() {
	int x;
	std::cout << "inputAndPrintInteger: ";
	std::cin >> x;
	std::cout << "You wrote: " << x << std::endl;
}


bool isOdd(int a) {
	if(a%2==1) {
		return true;
	} else {
		return false;
	}
}

void printHumanReadableTime(int a) {
	int h = 0;
	int m = 0;
	int s = 0;

	if(a>=3600) {
		h = a/3600;
		a -= 3600*h;
	}

	if(a>=60) {
		m = a/60;
		a -= 60*m;
	} 
	s = a;
	if(h==0 && m==0) {
		std::cout << s << " sec" << std::endl;
	} else if(h==0 && m!=0) {
		std::cout << m << " min " << " and " << s << " sec";
	} else {
		std::cout << h << " hours, " << m << " min" << " and "
		<< s << " sec";
	}

}


int inputInteger() {
	int x;
	std::cout << "inputInteger ";
	std::cin >> x;
	return x;
}

void inputIntegersAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();
	std::cout << "Sum is: " << x + y << std::endl;
}

//while{true} for x==0
void inputIntegersUsingLoopAndPrintSum() {
	int x;
	int sum = 0;
	std::cout << "how many nrs" << std::endl;
	std::cin >> x;
	for(int i=0; i<x; i++) {
		int y = inputInteger();
		if(y == 0) {
			break;
		}
		sum += y;
	}
	std::cout << "sum is: " << sum << std::endl;
}

double inputDouble() {
	double x;
	std::cin >> x;
	return x;
}

//diving by 9.64 will most of the time result in not
//an int. using double ensures this wrong calculation
//no return value, since ex. only specifies to print out
//and not return any value, we also dont need
//to save the value for later use
void convert() {
	double nok;
	double eur;
	nok = inputDouble();
	while(nok < 0) {
		nok = inputDouble();
	}
	eur = nok/9.64;
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << nok << " nok = " << eur << " eur" << std::endl;
}

void table() {
	int l;
	int h;
	std::cout << "length: " << std::endl;
	std::cin >> l; 
	std::cout << "height: " << std::endl;
	std::cin >> h;
	for(int i = 1; i<l+1; i++) {
		for(int j = 1; j<h+1; j++) {
			std::cout << j << "x" << i << " = " << i*j << "; ";
		}
		std::cout << "" <<std::endl;
	}

}

double discriminant(double a, double b, double c) {
	return (b*b) - (4*a*c);
}

void printRealRoots(double a, double b, double c) {
	double d = discriminant(a,b,c);
	if(d>0) {
		double x1 = (-(b)+sqrt(d))/(2*a);
		double x2 = (-(b)-sqrt(d))/(2*a);
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "x1=" << x1 << " x2=" << x2 << std::endl; 
	} else if(d==0) {
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "x= " << -b/2*a << std::endl;
	} else {
		std::cout << "no solutions" << std::endl;
	}
}

void solveQuadraticEquation() {
	double a = inputDouble();
	double b = inputDouble();
	double c = inputDouble();
	printRealRoots(a,b,c);	
}

void calculateLoanPayments() {
	double loan;
	double interest;
	std::cout << "loan amount? " << std::endl;
	loan = inputDouble();
	std::cout << "interest? " << std::endl;
	interest = inputDouble();
	double in;
	double rest = loan;

	in = (loan)/(10)+(interest/100)*rest;
	std::cout << "Year\t In\t Rest\t" << std::endl;

	for(int i=1; i<11; i++) {
		rest += rest*(interest/100);
		rest -= in;
		std::cout << i << "\t" << in << "\t" << rest << std::endl;
		in = (loan)/(10)+(interest/100)*rest;
	}
}

int main() {
	//calculateLoanPayments();

	//table();
	
	int x=1;
	while(x != 0) {
		std::cout << "Choose a function: " << std::endl;
		std::cout << "0) terminate " << std::endl;
		std::cout << "1) sum two nrs " << std::endl;
		std::cout << "2) sum x nrs " << std::endl;
		std::cout << "3) covert nok to eur " << std::endl;
		std::cout << "4) quadratic solver " << std::endl;
		std::cout << "options 0-4 " << std::endl;
		std::cin >> x;
		if(x==1) {
			inputIntegersAndPrintSum();
		} else if(x==2) {
			inputIntegersUsingLoopAndPrintSum();
		} else if(x==3) {
			convert();
		} else if(x==4) {
			solveQuadraticEquation();
		}
	} 
	
	
	//inputIntegersUsingLoopAndPrintSum();

	//printHumanReadableTime(10000);


	for (int i = 10; i < 15; i++) {
		if(isOdd(i)) { //if true
			std::cout << i << " is odd" << std::endl;
		}
		else {
			std::cout << i << " is even" << std::endl;
		}
	}

	//inputIntegersAndPrintSum(); //I used inputIntegers
	//since the func has a return value, which i can 
	//set a variable to, contra the other where the value 
	//cant be retrived


	//int number = inputInteger();
	//std::cout << "You wrote " << number << std::endl;


	//inputAndPrintInteger();
	return 0;
}