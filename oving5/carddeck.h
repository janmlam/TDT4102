#pragma once
#include <iostream>
#include <vector>
#include "card.h"


class CardDeck {
	private:
		std::vector<Card> cardsTot;
		int currentCardIndex;
		void swap(int a, int b);
	public:
		CardDeck();
		void print();
		void printShort();
		void shuffle();
		Card drawCard();
};