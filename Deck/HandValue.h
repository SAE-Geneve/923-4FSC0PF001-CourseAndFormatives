#pragma once

#include <vector>
#include <map>

#include "Decks.h"

enum HandValue
{
	HighCard,
	Pair,
	TwoPairs,
	Brelan,
	Square,
	Full,
	Suit,
	Color,
	Flush
};

std::string ToString(HandValue _value);

HandValue Evaluate(const std::vector<Card>& _Hand);

std::map<Rank, int> MapOccurences(const std::vector<Card>& compoundHand);

bool HasPair(const std::vector<Card>& _compoundHand);
bool HasTwoPairs(const std::vector<Card>& _compoundHand);
bool HasBrelan(const std::vector<Card>& _compoundHand);
bool HasSquare(const std::vector<Card>& _compoundHand);
bool HasFull(const std::vector<Card>& _compoundHand);
bool HasSuite(const std::vector<Card>& _compoundHand);
bool HasColor(const std::vector<Card>& _compoundHand);
bool HasFlush(const std::vector<Card>& _compoundHand);
