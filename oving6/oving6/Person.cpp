#include "Person.h"
#include "Car.h"
#include <string>
#include <iostream>

bool Person::hasAvailableSeats() {
	bool car_seats_free = false;
	if ((this->Car != nullptr) && ((this->Car)->hasFreeSeats()) == true) {
		car_seats_free = true;
	}
	return car_seats_free;
}


std::string Person::getName() const{
	return this->name;
}

std::string Person::getEmail() const{
	return this->email;
}

void Person::setName(std::string setName){
	this->name = setName;
}

void Person::setEmail(std::string setEmail){
	this->email = setEmail;
}

std::ostream& operator<<(std::ostream& os, const Person& pers) {
	os << pers.getName() << " and " << pers.getEmail();
	return os;

}