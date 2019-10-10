#pragma once
#include <string>
#include "Car.h"

class Person {
	private:
		std::string name;
		std::string email;
		Car *Car;
	public:
		Person(std::string nameSet) {
			this->name = nameSet;
		}
		Person(std::string nameSet, std::string emailSet) : Person(nameSet) {
			this->email = emailSet;
		}
		bool hasAvailableSeats();
		std::string getName() const;
		std::string getEmail() const;
		void setName(std::string setName);
		void setEmail(std::string setEmail);
		friend std::ostream& operator<<(std::ostream& os, const Person& pers);
		//friend bool operator<(const Person&);
		//bool bool operator ==(const Person&);

};