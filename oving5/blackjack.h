#pragma once

class BlackJack {
	private:
		CardDeck deck;
		int playerHand;
		int dealerHand;
		int playerCardsDrawn;
		int dealerCardsDrawn;
	public:
		bool isAce(Card *isitAce);
		int getCardValue(Card* value);
		int getPlayerCardValue(Card* value);
		int getDealerCardValue(Card* value, int a);
		bool askPlayerDrawCards();
		void drawInitialCards();
		void playGame();
};