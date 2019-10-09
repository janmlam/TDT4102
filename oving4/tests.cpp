#include <iostream>
#include "tests.h"
#include "utilities.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}

void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes2(&v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations << std::endl;
}

void testTablesSorting() {
	int percentage[20];
	randomizeArray(percentage, 20);
	printArray(percentage, 20);
	sortArray(percentage, 20);
	printArray(percentage, 20);
	medianOfArray(percentage, 20);
	printArray(percentage, 20);
	//swapNumbers(&percentage[0], &percentage[1]);
	swapNumbers(percentage, percentage+1);
	printArray(percentage, 20);
	/*
	int temp = percentage[0];
	percentage[0] = percentage[1];
	percentage[1] = temp;
	printArray(percentage, 20);
	*/
}

void testCStrings() {
	/* opp44 til og med h)
	char grades[9];
	randomizeCString(grades, 9, 'A', 'F');
	std::cout << grades << std::endl;
	int num = 0;
	int gradecount[5];
	for(int i=0; i<6; i++) {
		char curr = 'A'+i;
		int count = countOccurencesOfCharacter(grades, 9, curr);
		gradecount[i] = count;
	}
	printArray(gradecount, 6);
	double sum = 0.;
	int point = 1;
	for(int i=0; i<6; i++) {
		sum += gradecount[i]*point;
		point++;
	}
	sum = sum/8;
	//std::cout << sum << std::endl;
	*/

	//start j
	char fem[41];
	readInputToCString(fem, 41, 'A', 'E');
	int femCount[4];
	for(int i=0; i<5; i++) {
		char curr = 'A'+i;
		int count = countOccurencesOfCharacter(fem, 41, curr);
		femCount[i] = count;
	}
	std::cout << average(femCount, 5) << std::endl;
}

double average(int array[], int l) {
	double sum = 0;
	int point = 1;
	for(int i=0; i<5; i++) {
		sum += array[i]*point;
		point++;
	}
	sum = sum/40;
	return sum;
}