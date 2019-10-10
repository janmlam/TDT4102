#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include "SimpleSet.h"
#include "Person.h"
#include <forward_list>
#include <list>

void replace(std::vector<std::string> &strings, std::string old, std::string replacement) {
	for (auto it = strings.begin(); it != strings.end(); ++it) {
		if (!old.compare(*it)) {
			it = strings.erase(it);
			it = strings.insert(it, replacement);
		}
	}
}

template <class T>
void shuffle(T *orig, int size) {
	// using fisher-yates
	std::set<T> hatSet{ orig, orig + size };
	int index = 0;
	while (hatSet.size() > 0) {
		auto it = hatSet.begin();
		advance(it, rand() % hatSet.size());
		orig[index++] = *it;
		hatSet.erase(it);
	}
}

template <class T>
T maximum(T a, T b) {
	return ((a >= b) ? a : b);
}

void insertOrdered(std::forward_list<Person> &l, Person p) {
	if (l.empty()) {
		l.insert_after(l.before_begin(), p);
		return;
	}

	auto it = l.before_begin();
	while (true) {
		auto oldIterator = it;
		if (++it == l.end()) {
			l.insert_after(oldIterator, p);
			return;
		}
		else if (p <= *it) {
			l.insert_after(oldIterator, p);
			return;
		}
	}
}
void insertOrdered(std::list<Person> &l, Person p) {
	if (l.empty()) {
		l.insert(l.begin(), p);
		return;
	}

	for (auto it = l.begin(); it != l.end(); ++it) {
		if (p <= *it) {
			l.insert(it, p);
			return;
		}
	}
}

int main() {
	/*
	std::vector<std::string> test = { "Lorem", "Ipsum", "Dolor", "Sit", "Amet","Lorem", "Consectetur" };

	for (auto i = test.begin(); i != test.end(); ++i) {
		std::cout << *i << std::endl;
	}
	
	for (auto i = test.rbegin(); i != test.rend(); ++i) {
		std::cout << *i << std::endl;
	}

	replace(test, "Lorem", "Latin");
	for (auto i = test.begin(); i != test.end(); ++i) {
		std::cout << *i << std::endl;
	}
	*/
	/*
	std::set<int> ints;
	for (int i = 0; i <= 100; ++i) {
		ints.insert(i);
	}
	
	for (auto i = ints.begin(); i != ints.end();) {
		if (*i % 2 == 0 && *i != 2 && *i != 0) {
			i = ints.erase(i);
		}
		else {
			++i;
		}
	}
	*/
	/*
	for (int j = 3; j <= 100; ++j) {
		for (auto i = ints.begin(); i != ints.end(); ++i) {
			if (*i % j == 0 && *i != j)
				i = ints.erase(i);
		}
	}*/

	/*
	SimpleSet<int> simpleInts;
	for (int i = 1; i <= 100; ++i) {
		simpleInts.insert(i);
	}

	for (int i = 2; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (j % i == 0 && j != i)
				simpleInts.remove(j);
		}
	}
	std::cout << simpleInts << std::endl;
	*/
	/*
	
	int aasd[] = { 1,2,3,4,5 };
	shuffle(aasd, 5);
	for (int i = 0; i < 5; i++) {
		std::cout << aasd[i] << std::endl;
	}
	
	double a = 3.7;
	double b = 3.6;
	double c = maximum(a, b);
	std::cout << c << std::endl;
	
	SimpleSet<double> simpleDubs;

	for (double i = 0.0; i < 1.2; i += 0.1) {
		std::cout << i << std::endl;
		simpleDubs.insert(i);
	}

	std::cout << simpleDubs << std::endl;
	*/
	
	
	Person Aa("A", "a");
	Person Bb("B", "b");
	Person Cc("C", "c");
	Person Dd("D", "d");
	
	std::forward_list<Person> kids;

	insertOrdered(kids, Dd);
	insertOrdered(kids, Bb);
	insertOrdered(kids, Aa);
	insertOrdered(kids, Cc);

	for (Person &p : kids) {
		std::cout << p << std::endl;
	}

	std::list<Person> barn;
	insertOrdered(barn, Dd);
	insertOrdered(barn, Bb);
	insertOrdered(barn, Aa);
	insertOrdered(barn, Cc);

	for (Person &p : barn) {
		std::cout << p << std::endl;
	}x
	return 0;
	

}

