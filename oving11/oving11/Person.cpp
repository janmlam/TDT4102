#include "Person.h"
#include <string>
#include <iostream>
#include <forward_list>
#include <list>

Person::Person(const std::string firstName, const std::string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}

std::string Person::getFirstName() const{
	return this->firstName;
}

std::string Person::getLastName() const {
	return this->lastName;
}

bool Person::operator<(const Person & rhs){
	if (firstName < rhs.firstName)
		return true;
	else if (lastName < rhs.lastName)
		return true;
	return false;
}

bool Person::operator>(const Person & rhs) {
	if (firstName > rhs.firstName)
		return true;
	else if (lastName > rhs.lastName)
		return true;
	return false;
}

bool Person::operator<=(const Person & rhs) {
	return (*this < rhs || *this == rhs);
}

bool Person::operator==(const Person & rhs) {
	return (firstName == rhs.firstName && lastName == rhs.lastName);
}

std::ostream& operator<<(std::ostream& os, const Person& pers) {
	std::cout << "firstname: " << pers.getFirstName() << " last name:  " << pers.getLastName();
	return std::cout;
}