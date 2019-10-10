#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void writing() {
	std::ofstream file1;
	file1.open("opp1.txt");
	bool file_open = true;
	while (file_open == true) {
		std::string word = "";
		std::cout << "type to write to file, type quit to exit" << std::endl;
		std::cin >> word;
		if (word == "quit") {
			file_open = false;
			file1.close();
		} else {
			file1 << word;
			file1 << std::endl;
		}
	}
}

void copyFile() {
	std::ifstream infile;
	infile.open("opp1.txt");

	std::ofstream outfile; 
	outfile.open("copied.txt");

	int i = 1;
	do {
		std::string lineToFile = "";
		lineToFile.append(std::to_string(i));
		lineToFile.append("\t");
		std::string copy_string = "";
		std::getline(infile, copy_string);
		lineToFile.append(copy_string);
		std::cout << lineToFile << std::endl;
		outfile << lineToFile;
		outfile << std::endl;
		i++;
	} while (infile.eof() == false);
	infile.close();
	outfile.close();
}

void womanLiesStatsDont() {
	std::ifstream file;
	file.open("charas.txt");
	int totalLetters = 0;
	int amounts[26] = { 0 };
	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j',
						'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't',
						'u', 'v', 'w', 'x', 'y', 'z' };

	while (file.eof() == false) {
		std::string oneLine = "";
		std::getline(file, oneLine);
		std::transform(oneLine.begin(), oneLine.end(), oneLine.begin(), ::tolower);
		for (int i = 0; i < 26; i++) {
			amounts[i] += std::count(oneLine.begin(), oneLine.end(), letters[i]);
			totalLetters += std::count(oneLine.begin(), oneLine.end(), letters[i]);
		}
	}
	std::cout << "Stats: " << std::endl;
	std::cout << "Total numbers of letters: " << totalLetters << std::endl;
	for (int i = 0; i < 26; i++) {
		std::cout << letters[i] << ": " << amounts[i];
		if ((i+1) % 4 == 0) {
			std::cout << "\n";
		} else {
			std::cout << "\t";
		}
	}
	std::cout << std::endl;
}

bool abc(char c) {
	if (c >= 97 && c <= 122) {
		return false;
	}
	else {
		return false;
	}
}

void test() {
	char a = 97;
	std::cout << a << std::endl;
}

void statsNeverLie() {
	std::ifstream file;
	file.open("stats.txt");
	int totalLetters = 0;
	int amounts[26] = { 0 };
	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't',
		'u', 'v', 'w', 'x', 'y', 'z' };

	while (file.eof() == false) {
		std::string oneLine = "stats.txt";
		std::getline(file, oneLine);

		std::transform(oneLine.begin(), oneLine.end(), oneLine.begin(), ::tolower);
		std::cout << oneLine << std::endl;
		
		std::cout << oneLine << std::endl;
		for (std::string::iterator letter = oneLine.begin(); letter != oneLine.end();) 
			std::cout << letter << std::endl;
			letter++;
		}
		std::cout << oneLine << std::endl;
		/*
		for (int i = 0; i < 26; i++) { //counting chracters
			amounts[i] += std::count(oneLine.begin(), oneLine.end(), letters[i]);
			totalLetters += std::count(oneLine.begin(), oneLine.end(), letters[i]);
		}
		*/
	}
	/*
	std::cout << "Stats: " << std::endl;
	std::cout << "Total numbers of letters: " << totalLetters << std::endl;
	for (int i = 0; i < 26; i++) {
		std::cout << letters[i] << ": " << amounts[i];
		if ((i + 1) % 4 == 0) {
			std::cout << "\n";
		}
		else {
			std::cout << "\t";
		}
	}
	std::cout << std::endl;
	*/
}