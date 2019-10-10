#include "fibo.h"
#include <iostream>

void fillInFibonacciNumbers(int result[], int length) {
	if(length==1) {
		result[0] = 0;
	}
	else if(length==2) {
		result[0] = 0;
		result[1] = 1;
	}
	else if(length==3) {
		result[0] = 0;
		result[1] = 1;
		result[2] = 1;
	}
	else {
		result[0] = 0;
		result[1] = 1;
		result[2] = 2;
		for (int i = 3; i < length; i++) {
			result[i] = result[i-1] + result[i-2];
		}
	}
}

void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << std::endl;
	}
}

void createFibonacci() {
	int length = -1;
	std::cout << "fibonacci numbers?" << std::endl;
	std::cin >> length;
	int *arr = new int[length];
	fillInFibonacciNumbers(arr, length);
	printArray(arr, length);
}