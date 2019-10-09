#include <iostream>
#include <cmath>
#include "cannonball.h"

double accX() {
	return 0;
}
double acclY() {
	double accY = -9.81;
	return accY;
}

double velY(double initVelocity, double time) {
	double acc = acclY();
	double speedY = initVelocity + (acc*time);
	return speedY;
}

double posX(double initPosition, double initVelocity, double time) {
	double acc = accX();
	double pos = initPosition + (initVelocity*time) + ((acc)*(time)*(time)/2);
	return pos;
}

double posY(double initPosition, double initVelocity, double time) {
	double acc = acclY();
	double pos = initPosition + (initVelocity*time) + ((acc)*(time)*(time)/2);
	return pos;
}

void printTime(double time) {
	double h = 0;
	double m = 0;
	double s = 0;

	if(time>=3600) {
		h = time/3600;
		time -= 3600*h;
	}

	if(time>=60) {
		m = time/60;
		time -= 60*m;
	} 
	s = time;
	if(h==0 && m==0) {
		std::cout << s << " sec" << std::endl;
	} else if(h==0 && m!=0) {
		std::cout << m << " min " << " and " << s << " sec";
	} else {
		std::cout << h << " hours, " << m << " min" << " and "
		<< s << " sec";
	}
}

double flightTime(double initVelocity) {
	double acc = acclY();
	double time = (-2*initVelocity)/(acc);
	return time;
}

void getUserInput(double *theta, double *absVelocity) {
	std::cout << "Input degrees " << std::endl;
	std::cin >> *theta;
	std::cout << "input velocity " << std::endl;
	std::cin >> *absVelocity;
}

double degToRad(double deg) {
	double pi = 3.14;
	double rad = (pi/180.)*deg;
}

double getVelocityX(double theta, double absVelocity) {
	double velX = absVelocity*cos(theta);
	return velX;
}

double getVelocityY(double theta, double absVelocity) {
	double velY = absVelocity*sin(theta);
	return velY;
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(degToRad(theta), absVelocity);
	*velocityY = getVelocityY(degToRad(theta), absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	double flight = flightTime(velocityY);
	return posX(0, velocityY, flight);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	double res = getDistanceTraveled(velocityY, velocityY);
	double diff = pow(distanceToTarget - res, 2);
	if(diff == 5) {
		std::cout << "hit" << std::endl;
	} else {
		std::cout << "didnt hit target" << std::endl;
	}
	return diff;
}