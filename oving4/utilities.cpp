#include "utilities.h"
#include <iostream>
#include <ctime>
#include <cctype>

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}


void incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

void swapNumbers(int *a, int *b) {
	std::cout << *a << *b << std::endl;
	int temp = *b;
	*b = *a;
	*a = temp;
	std::cout << *a << *b << std::endl;
}

void printArray(int array[], int l) {
	for(int i=0; i<(l); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void randomizeArray(int array[], int l) {
	srand(time(0));
	for(int i=0; i<l; i++) {
		array[i] = rand() % 100 + 0;
	}
}

void sortArray(int array[], int l) {
	int min = 0;
	int temp = 0;
	for(int i=0; i<l-1; i++) {
		min = i;
		for(int j=i+1; j<l; j++) {
			if(array[j]<array[min]) {
				min = j;
			}
		}	
		if(min!=i) {
			temp = array[i] ;
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

double medianOfArray(int array[], int l) {
	if(l%2 == 0) {
		int number = l/2;
		double med = (array[number-1] + array[number])/2.;
		return med;
	} else {
		int number = l/2;
		double med = array[number];
		return med;
	}
}


void randomizeCString(char array[], int l, char lower, char upper) {
	srand(time(0));
	int top = 1+upper-1;
	int bot = 1+lower-1;
	for(int i=0; i<(l-1); i++) {
		char test = bot + rand() % (top-bot+1);
		array[i] = test;
	}
	array[l] = '\0';
}

void readInputToCString(char array[], int l, char lower, char upper) {
    for(int i=0; i<l-1; i++) {
        char inn;
        std::cout << "input" << std::endl;
        std::cin >> inn;
		char put = std::toupper(inn);
        if(put >= lower and put <= upper) {
        	array[i] = put;
        } else { 
        	i--;
        } 
    }
    array[l] = '\0'; 
}

int countOccurencesOfCharacter(char array[], int l, char asd) {
	int count = 0;
	for(int i=0; i<l; i++) {
		if(array[i] == asd) {
			count++;
		}
	}
	return count;
}