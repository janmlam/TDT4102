#include "Car.h"
#include <iostream>

Car::Car(int free) {
	this->freeSeats = free;
}

bool Car::hasFreeSeats() const{
	bool free = false;
	if ((this->freeSeats) > 0) {
		free = true;
	}
	return free;
}

void Car::reserveFreeSeat() {
	this->freeSeats--;
}