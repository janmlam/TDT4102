#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <map>

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
	while (infile.eof() == false) {
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
	} 
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


void statsNeverLie() {
	std::ifstream file;
	file.open("stats.txt");
	std::map<std::string, int> wordCounts; 
	long wordCount = 0;  
	std::string longestWord = "";
	long lineCount = 0;
	long totalWordLength = 0;
		
	while (file.eof() == false) {
		std::string oneLine = "stats.txt";
		std::getline(file, oneLine);
		std::transform(oneLine.begin(), oneLine.end(), oneLine.begin(), ::tolower);
		std::stringstream ss(oneLine);
		std::string word;
		lineCount++;
		while (ss >> word) {
			char *letters = new char[word.length() + 1];
			size_t index = 0;
			for (char &letter : word) {
				if (letter >= 'a' && letter <= 'z') {
					letters[index++] = letter;
				}
			}
			letters[index] = '\0';
			word = std::string(letters);
			std::cout << word << std::endl;

			totalWordLength += word.length();
			wordCounts[word]++;
			wordCount++;
			if (word.length() > longestWord.length()) {
				longestWord = word;
			}
			delete[] letters;
		}
	}
	file.close();
	std::cout << "Stats: " << std::endl;
	std::cout << "Longest word: " << longestWord << std::endl;
	std::cout << "Amount of words: " << wordCount << std::endl;
	std::cout << "Amount of lines: " << lineCount << std::endl;
	std::cout << "Average word length: " << totalWordLength / wordCount << std::endl;

	for (auto& word : wordCounts) {
		std::cout << word.first << ": " << word.second << std::endl;
	}
}



//string test = "hah'aha";
//strign clean = "";
//for (int i = 0; i < test.length; i++) {
//	if (isalpha(test[i])) {
//		//test.erase(i, 1);
//		test.erase(test.begin() + i);
//	}
//}