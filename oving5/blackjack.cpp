#include "carddeck.h"
#include "card.h"
#include "blackjack.h"
#include <iostream>
						//hvorfor funker ikke *isitAce
bool BlackJack::isAce(Card *isitAce) {
	if(isitAce->getRank() == ACE) {
		return true;
	} else {
		return false;
	}
}

int BlackJack::getCardValue(Card* value) {
	int valve = 0;
	if(value->getRank() == JACK || value->getRank() == QUEEN || value->getRank() == KING) {
		valve = 10;
	} else if(value->getRank()==ACE) {
		valve = -1;
	} else {
		valve = (int)value->getRank();
	}
	return valve;
}

int BlackJack::getPlayerCardValue(Card* value) {
	int valve = getCardValue(value);

	if(valve==-1) {
		int temp = 0;
		bool check = false;
		while(check==false) {
			std::cout << "What value should the ace be? 1 or 11" << std::endl;
			std::cin >> temp;
			if(temp == 1 || temp == 11) {
				check = true;
			}
		}
		valve = temp;
	}
	return valve;
}

int BlackJack::getDealerCardValue(Card* value, int a) {
	int valve = getCardValue(value);
	if(valve == -1) {
		if((a+11) > 21) {
			valve = 1;
		} else {
			valve = 11;
		}
	}
	return valve;
}

bool BlackJack::askPlayerDrawCards() {
	bool test = false;
	int x = -1;
	while(test==false) {
		std::cout << "hit? 1 for yes, 0 for no" << std::endl;
		std::cin >> x;
		if(x == 0 || x == 1) {
			test = true;
		}
	}
	if(x==0) {
		return false;
	} else {
		return true;
	}
}

void BlackJack::drawInitialCards() {
	CardDeck deck;
	deck.shuffle();	
	Card p1 = deck.drawCard();
	Card *p11 = &p1;
	this->playerCardsDrawn++;
	Card p2 = deck.drawCard();
	Card *p22 = &p2;
	this->playerCardsDrawn++;
	std::cout << "Player card1: " << p11->toString_class() << std::endl;
	std::cout << "Player card2: " << p22->toString_class() << std::endl;

	this->playerHand = getPlayerCardValue(p11);
	this->playerHand += getPlayerCardValue(p22);

	Card d1 = deck.drawCard();
	Card *d11 = &d1;
	this->dealerCardsDrawn++;
	Card d2 = deck.drawCard();
	Card *d22 = &d2;
	this->dealerCardsDrawn++;
	std::cout << "Dealer card1: " << d11->toString_class() << std::endl;
	std::cout << "Dealer card2: XXX" << std::endl;
	this->dealerHand = getDealerCardValue(d11, dealerHand);
	this->dealerHand += getDealerCardValue(d22, dealerHand);
}

void BlackJack::playGame() {
	BlackJack game;
	CardDeck deck;
	game.drawInitialCards();
	if(game.playerHand < 21 && game.dealerHand < 21) {
      bool check = true;
      while(check) {
        check = askPlayerDrawCards();
        if(check) {
          Card a = deck.drawCard();
          Card *aa = &a; 
          std::cout << "Card: " << aa->toString_class() << std::endl;
          game.playerHand += getPlayerCardValue(aa);
          game.playerCardsDrawn++;
          if(dealerHand < 17) {

            Card b = deck.drawCard();
            Card *bb = &b;
            game.dealerHand += getDealerCardValue(bb, dealerHand);
            game.dealerCardsDrawn++;
          }
          if(game.playerHand >= 21 || game.dealerHand >= 21) {
              check = false;
          }
        }
    }
        while(game.dealerHand < 17) {
            Card c = deck.drawCard();
            Card *cc = &c;
            game.dealerHand += getDealerCardValue(cc, dealerHand);
            game.dealerCardsDrawn++;
        }

        std::cout << game.playerHand << " " << game.dealerHand << std::endl;

        if(game.playerHand > 21 && game.dealerHand > 21) {
            std::cout << "push" << std::endl;
        }
        else if(game.dealerHand > 21) {
           std::cout << "plaer win" << std::endl;
        }
        else if(game.playerHand > 21) {
            std::cout << "Bust" << std::endl;
        }
        else if(game.dealerHand == 21) {
            std::cout << "Dealer got blackjack" << std::endl;
        }
        else if(game.dealerHand >= game.playerHand) {
            std::cout << "dealer got higher" << std::endl;
        }
        else if(game.playerHand == 21) {
            std::cout << "blackjack" << std::endl;
        }
        else {
            std::cout << "uvon" << std::endl;
        }
    }
}