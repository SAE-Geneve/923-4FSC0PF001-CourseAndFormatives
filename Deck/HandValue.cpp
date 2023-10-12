#include "HandValue.h"

#include <algorithm>
#include <map>
#include <set>

std::string ToString(HandValue _value)
{
	switch (_value)
	{
	case HighCard: return "High Card";  break;
	case Pair: return "Pair"; break;
	case TwoPairs: return "Two Pairs"; break;
	case ThreeOfAKind: return "Brelan"; break;
	case FourOfAKind: return "FourOfAKind"; break;
	case FullHouse: return "Full House"; break;
	case Straight: return "Straight"; break;
	case StraightFlush: return "Straight Flush"; break;
	case Flush: return "Flush"; break;

	default:
		return "_no_value_";
	}


}

HandValue Evaluate(const std::vector<Card>& hand)
{

	// Compose Player and table Hands ------------
	std::vector<Card> compoundHand;

	for (auto c : hand)
		compoundHand.emplace_back(c);

	for (auto c : Table)
		compoundHand.emplace_back(c);

	// -------------------------------------------------------------------------------------------
	/*if (HasStraightFlush(compoundHand)){
		return StraightFlush;
	}
	else*/


	if (HasFourOfAKind(compoundHand)){
		return FourOfAKind;
	}
	else if (HasFlush(compoundHand)){
		return Flush;
	}
	else if (HasThreeOfAKind(compoundHand)){
		return ThreeOfAKind;
	}
	else if (HasTwoPairs(compoundHand)){
		return TwoPairs;
	}
	else if (HasPair(compoundHand)){
		return Pair;
	}
	else{
		return HighCard;
	}

}

std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand)
{

	std::map<Rank, int> rankOccurences;

	for (auto c : compoundHand)
	{
		if (rankOccurences.find(c.rank) == rankOccurences.end())
		{
			rankOccurences[c.rank] = 1;
		}
		else
		{
			rankOccurences[c.rank]++;
		}
	}

	return rankOccurences;

}
std::map<Suit, int> SuitOccurences(const std::vector<Card>& compoundHand)
{

	std::map<Suit, int> suitOccurences;

	for (auto c : compoundHand)
	{
		if (suitOccurences.find(c.suit) == suitOccurences.end())
		{
			suitOccurences[c.suit] = 1;
		}
		else
		{
			suitOccurences[c.suit]++;
		}
	}

	return suitOccurences;
}

bool HasPair(const std::vector<Card>& compoundHand)
{
	// Constitution du comptage ---------------------------------------------------
	std::map<Rank, int> rankOccurences;
	for (auto c : compoundHand)
	{
		if (rankOccurences.find(c.rank) == rankOccurences.end())
		{
			rankOccurences[c.rank] = 1;
		}
		else
		{
			rankOccurences[c.rank]++;
		}
	}

	// Utilisation du comptage ---------------------------------------------------
	for (auto p : rankOccurences)
	{
		if (p.second == 2)
		{
			return true;
		}
	}
	return false;

}
bool HasTwoPairs(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);
	Rank firstPair;

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2)
		{
			firstPair = p.first;
		}
	}
	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2 && firstPair != p.first)
		{
			return true;
		}
	}


	return false;

}
bool HasThreeOfAKind(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 3)
		{
			return true;
		}
	}

	return false;

}
bool HasFourOfAKind(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 4)
		{
			return true;
		}
	}

	return false;

}
bool HasFlush(const std::vector<Card>& compoundHand)
{
	const std::map<Suit, int> occurences = SuitOccurences(compoundHand);

	if (std::any_of(occurences.cbegin(), occurences.cend(), [](std::pair<Suit, int> o) {return o.second >= 5; }))
		return true;
	
	return false;
}
