#pragma once
#include <iostream>
#include <string>

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct CardStruct {
	Suit suit_in;
	Rank rank_in;
};



std::string suitToString(Suit suit_in);
std::string rankToString(Rank rank_in);
std::string toString(CardStruct card_in);
std::string toStringShort(CardStruct card_in);

class Card {
	private:
		Suit suit;
		Rank rank;
		bool valid = false;
	public:
		void initialize(Suit suit, Rank rank);
		Suit getSuit();
		Rank getRank();
		std::string toString_class();
		std::string toStringShort_class();
		Card();
		Card(Suit suit, Rank rank);
};