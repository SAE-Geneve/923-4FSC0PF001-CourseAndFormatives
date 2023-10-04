#include "Decks.h"
#include <iostream>
#include <random>

std::vector<Card> Deck;
std::vector<Card> Table;
std::vector<Card> HandPlayer;
std::vector<Card> HandBot;

void FillDeck()
{
	for (int r = Rank::Two; r <= Rank::Ace; r++)
	{
		for (int s = Suit::Hearts; s <= Suit::Clubs; s++)
		{
			Card newCard;
			newCard.rank = (Rank)r;
			newCard.suit = (Suit)s;
			Deck.emplace_back(newCard);
		}
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(Deck.begin(), Deck.end(), g);

}

Card GiveACard()
{

	Card cardADonner{Rank(-1), Suit(-1)};

	if(Deck.size() > 0)
	{
		cardADonner = Deck.at(0);
		Deck.erase(Deck.begin());
	}
		
	return cardADonner;
}

void ToString(std::string _deckName, std::vector<Card> _deck)
{
	std::cout << std::endl << _deckName << " ---------------------------" << std::endl;

	for (Card c : _deck)
	{
		std::cout << ToString(c) << std::endl;
	}
}
