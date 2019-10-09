#include "utilities.h"
#include <iostream>
int checkCharactersAndPosition(char code[], char guess[], int l) {
    int counts = 0;
    for(int i=0; i<l; i++) {
        if(code[i] == guess[i]) {
            counts++;
            }
        }
    return counts;
}


int checkCharacters(char code[], char guess[], int SIZE, int LETTERS) {
	int amount_chara_guess = 0;
	for(int i=0; i<(LETTERS+1); i++) {
		char curr = 'A'+i;
		int amount_code = countOccurencesOfCharacter(code, SIZE, curr);
		int amount_guess = countOccurencesOfCharacter(guess, SIZE, curr);
		if(amount_code != 0) {
			if(amount_guess >= amount_code) {
			amount_chara_guess++;
			}
		}
	}
	return amount_chara_guess;
}

void playMastermind() {
	int SIZE = 4;
	int LETTERS = 6;
	int LIFE = 2;

	char letter = 'A'+(LETTERS-1);
	char code[SIZE+1];
	char guess[SIZE+1];
	randomizeCString(code, SIZE+1, 'A', 'A'+(LETTERS-1));	
	std::cout << code << std::endl;

	bool win = false;
	while(LIFE >= 0) {
		std::cout << "Type 4 letters, it must be within A to " << letter
			<< " you have " << LIFE+1 << " chances" << std::endl;
		readInputToCString(guess, SIZE+1, 'A', 'A'+(LETTERS-1));
		if(checkCharactersAndPosition(code, guess, SIZE)>=SIZE) {
			std::cout << "INNI" << std::endl;
			LIFE = -1;
			win = true;
		}
		std::cout << "You have gussed: " << checkCharacters(code, guess, SIZE, LETTERS)
			<< " correct letter(s) and " << checkCharactersAndPosition(code, guess, SIZE)
			<< " of them were correct placed" << std::endl;
		LIFE--;
	}

	if(win == true) {
		std::cout << "gz" << std::endl;
	} else {
		int x = 0;
		std::cout << "nt, retry? 1 for yes 2 for no" << std::endl; 
		std::cin >> x;
		if(x==1) {
			playMastermind();
		}
	}
}