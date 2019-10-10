#pragma once
#include <iostream>
#include <map>
#include <string>

class CourseCatalog {
	private:
		std::map<std::string, std::string> courses;
	public:
		friend std::ostream& operator<<(std::ostream &ios, const CourseCatalog &cc);
		void addCourse(std::string code, std::string name);
		void removeCourse(std::string code);
		std::string getCourse(std::string code);

};
