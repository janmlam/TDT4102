#include <iostream>
#include <string>
#include "card.h"


std::string suitToString(Suit suit_in) {
	std::string txt_suit_out = "";
	switch(suit_in) {
		case CLUBS : txt_suit_out = "CLUBS"; break;
		case DIAMONDS : txt_suit_out = "DIAMONDS"; break;
		case HEARTS : txt_suit_out = "HEARTS"; break;
		case SPADES : txt_suit_out = "SPADES"; break;
	}
	return txt_suit_out;
}

std::string rankToString(Rank rank_in) {
	std::string txt_rank_out = "";
	switch(rank_in) {
		case TWO : txt_rank_out = "TWO"; break;
		case THREE : txt_rank_out = "THREE"; break;
		case FOUR : txt_rank_out = "FOUR"; break;
		case FIVE : txt_rank_out = "FIVE"; break;
		case SIX : txt_rank_out = "SIX"; break;
		case SEVEN : txt_rank_out = "SEVEN"; break;
		case EIGHT : txt_rank_out = "EIGHT"; break;
		case NINE : txt_rank_out = "NINE"; break;
		case TEN : txt_rank_out = "TEN"; break;
		case JACK : txt_rank_out = "JACK"; break;
		case QUEEN : txt_rank_out = "QUEEN"; break;
		case KING : txt_rank_out = "KING"; break;
		case ACE : txt_rank_out = "ACE"; break;
	}
	return txt_rank_out;
}

std::string toString(CardStruct card_in) {
	std::string txt_card_out = rankToString(card_in.rank_in);
	txt_card_out.append(" of ");
	txt_card_out.append(suitToString(card_in.suit_in));
	return txt_card_out;
}

std::string toStringShort(CardStruct card_in) {
	std::string txt_card_out = (suitToString(card_in.suit_in)).substr(0,1);
	int rank = (int)card_in.rank_in+2;
	txt_card_out.append(std::to_string(rank));
	return txt_card_out;
}

void Card::initialize(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	this-> valid = true;
}

Suit Card::getSuit() {
	return this->suit;
}

Rank Card::getRank() {
	return this->rank;
}

std::string Card::toString_class() {
	CardStruct asd;
	asd.suit_in = this->suit;
	asd.rank_in = this->rank;
	std::string output = "";
	if((this->valid) == false) {
		output = "invalid card";
	} else {
		
		output = toString(asd);
	}
	return output;
}

std::string Card::toStringShort_class() {
	CardStruct asd;
	asd.suit_in = this->suit;
	asd.rank_in = this->rank;
	std::string output = "";
	if((this->valid) == false) {
		output = "invalid card";
	} else {
		
		output = toStringShort(asd);
	}
	return output;
}

Card::Card() {
	this->valid = false;
}

Card::Card(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	this->valid = true;
}