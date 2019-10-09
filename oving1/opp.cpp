#include <iostream>
using namespace std;
//a)
int max(int a, int b) {
	if(a>b) {
		cout <<"A is greater than B" << endl;
		return a;
	}
	else {
		cout << "B is greater than or equal to A" << endl;
		return b;
	}
}
//c)
int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << endl;
	for(int i=1; i<(n+1); i++) {
		cout << i << b << endl;
		int temp = b;
		b += a;
		a = temp; 
	}
	cout << "----" << endl;
	return b;
}
//d)
int squareNumberSum(int n) {
	int totalSum = 0;
	for(int i=0; i<n+1; i++) {
		totalSum += i*i;
		cout << i*i << endl;
	}
	cout << "SUM:" << totalSum << endl;
	return totalSum;
}

//e)
int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while(acc < n+1) {
		cout << acc << endl;
		acc += num;
		num += 1;
	}
	cout << "" << endl;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while(number > 0) {
		number -= acc;
		acc += 1;
	}
	return (number == 0);
}
//f)
bool isPrime(int n) {
	bool primeness = true;
	for(int i=2; i<n; i++) {
		if(n%i == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

//g)
void naivePrimeNumberSearch(int n) {
	for(int i=2; i<n; i++) {
		if(isPrime(i)){
			cout << i << " is prime" << endl;
		}
	}
}

int denominator(int n) {
	for(int i=n-1; i!=0 ;i--) {
		if(n%i == 0) {
			return i;
		}
	}
}


int main() {
	//cout << denominator(42) << endl;
	//naivePrimeNumberSearch(10);
	//cout << isPrime(10) << endl;
	//cout << isTriangleNumber(7) << endl;
	//triangleNumbersBelow(10);

	/* b)
	//cout << "Oppgave a)" << endl;
	//cout << max(5, 6) << endl;
	*/
	//cout << fibonacci(10) << endl;

	//squareNumberSum(2);
	return 0;
}