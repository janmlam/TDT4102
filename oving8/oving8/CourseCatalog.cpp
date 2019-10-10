#include "CourseCatalog.h"
#include <map>
#include <iostream>
#include <string>


std::ostream & operator<<(std::ostream &ios, const CourseCatalog &cc) {
	for (auto& printer : cc.courses) {
		ios << printer.first << ": " << printer.second << std::endl;
	}
	return ios;
}


void CourseCatalog::addCourse(std::string code, std::string name) {
	courses[code] = name;
}

void CourseCatalog::removeCourse(std::string code) {
	courses.erase(code);
}

std::string CourseCatalog::getCourse(std::string code) {
	if (courses[code] == "") {
		return "no such course";
	}
	else {
		return courses[code];
	}
	
}
