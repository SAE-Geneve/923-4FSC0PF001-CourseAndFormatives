#pragma once

#include <vector>
#include <map>

#include "Decks.h"

enum HandValue
{
	HighCard,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush
	
};

std::string ToString(HandValue _value);

HandValue Evaluate(const std::vector<Card>& hand);

std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand);

bool HasPair(const std::vector<Card>& compoundHand);
bool HasTwoPairs(const std::vector<Card>& compoundHand);
bool HasThreeOfAKind(const std::vector<Card>& compoundHand);
bool HasStraight(const std::vector<Card>& compoundHand);
bool HasFlush(const std::vector<Card>& compoundHand);
bool HasFullHouse(const std::vector<Card>& compoundHand);
bool HasFourOfAKind(const std::vector<Card>& compoundHand);
bool HasStraightFlush(const std::vector<Card>& compoundHand);
