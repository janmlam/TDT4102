#pragma once
#include <string>
#include <iostream>
#include <forward_list>
#include <list>

class Person {
	private:
		std::string firstName;
		std::string lastName;
	public:
		Person(const std::string firstName, const std::string lastName);
		std::string getFirstName() const;
		std::string getLastName() const;
		
		bool operator<(const Person &rhs);
		bool operator>(const Person &rhs);
		bool operator<=(const Person &rhs);
		bool operator==(const Person &rhs);

		friend std::ostream& operator<<(std::ostream& os, const Person& person);


};