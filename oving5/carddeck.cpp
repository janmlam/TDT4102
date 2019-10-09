#include <iostream>
#include <algorithm>
#include "carddeck.h"
#include "card.h"
#include <ctime>  
#include <cstdlib> 


CardDeck::CardDeck() {
	this->currentCardIndex = 0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<13; j++) {
			Card cardToDeck(static_cast<Suit>(i), static_cast<Rank>(j));
			this->cardsTot.push_back(cardToDeck);
		}
	}
}

void CardDeck::swap(int a, int b) {
	Card temp = cardsTot[a];
	cardsTot[a] = cardsTot[b];
	cardsTot[b] = temp;
}

void CardDeck::print() {
	for(Card printCard : this->cardsTot) {
		std::cout << printCard.toString_class() << std::endl;
	}
}

void CardDeck::printShort() {
	for(Card printCard : this->cardsTot) {
		std::cout << printCard.toStringShort_class() << std::endl;
	}
}

void CardDeck::shuffle() {
	std::srand(std::time(0));
	std::random_shuffle(this->cardsTot.begin(), this->cardsTot.end());
}

Card CardDeck::drawCard() {
	Card topCard = cardsTot[currentCardIndex];
	currentCardIndex++;
	return topCard;
}