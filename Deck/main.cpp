#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <vector>

#include "Card.h"
#include "Decks.h"
#include "HandValue.h"

int main()
{

	Card oneCard;
	oneCard.rank = Ace;
	oneCard.suit = Spades;
	std::cout << ToString(oneCard) << std::endl;

	const Card anotherCard = GiveACard();
	std::cout << ToString(anotherCard) << std::endl;

	FillDeck();

	// 1ere donne : 1 carte à chaque joueur
	HandPlayer.push_back(GiveACard());
	HandBot.push_back(GiveACard());

	HandPlayer.push_back(GiveACard());
	HandBot.push_back(GiveACard());

	// Flop
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());

	// Turn
	Table.push_back(GiveACard());

	// River
	Table.push_back(GiveACard());


	ToString("Deck", Deck);
	ToString("Table", Table);
	ToString("Player", HandPlayer);
	ToString("Bot", HandBot);

	const HandValue playerValue = Evaluate(HandPlayer);
	const HandValue botValue = Evaluate(HandBot);

	if(playerValue > botValue)
	{
		std::cout << "Player Won : " << ToString(playerValue) << std::endl;
	}else if(playerValue < botValue)
	{
		std::cout << "Bot Won : " << ToString(botValue) << std::endl;
	}else
	{
		std::cout << "SPLIT" << std::endl;
	}
	
}
