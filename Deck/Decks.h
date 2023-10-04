#pragma once
#include <vector>
#include "Card.h"

extern std::vector<Card> Deck;
extern std::vector<Card> Table;
extern std::vector<Card> HandPlayer;
extern std::vector<Card> HandBot;

void FillDeck();
Card GiveACard();
void ToString(std::string _deckName, std::vector<Card> _deck);
