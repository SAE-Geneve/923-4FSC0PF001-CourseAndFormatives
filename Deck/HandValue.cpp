#include "HandValue.h"

#include <map>
#include <set>

std::string ToString(HandValue _value)
{
	switch (_value)
	{
	case HighCard: return "High Card";  break;
	case Pair: return "Pair"; break;
	case TwoPairs: return "Two Pairs"; break;
	case Brelan: return "Brelan"; break;
	case Square: return "Square"; break;
	case Full: return "Full"; break;
	case Suit: return "Suit"; break;
	case Color: return "Color"; break;
	case Flush: return "Flush"; break;

	default: 
		return "_no_value_";
	}


}

HandValue Evaluate(const std::vector<Card>& _hand)
{

	// Compose Player and table Hands ------------
	std::vector<Card> _compoundHand;

	for (auto c : _hand)
		_compoundHand.emplace_back(c);

	for (auto c : Table)
		_compoundHand.emplace_back(c);

	if (HasPair(_compoundHand))
		return Pair;
	else if (HasTwoPairs(_compoundHand))
		return TwoPairs;
	else if (HasBrelan(_compoundHand))
		return Brelan;
	else if (HasSquare(_compoundHand))
		return Square;
	else
		return HighCard;

}

std::map<Rank, int> MapOccurences(const std::vector<Card>& compoundHand)
{

	std::map<Rank, int> occurences;

	for(auto c : compoundHand)
	{
		if (occurences.find(c.rank) == occurences.end())
		{
			occurences[c.rank] = 1;
		}else
		{
			occurences[c.rank]++;
		}
	}

	return occurences;

}

bool HasPair(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = MapOccurences(compoundHand);

	for(std::pair<Rank, int> p : occurences)
	{
		if(p.second == 2)
		{
			return true;
		}
	}

	return false;
	
}
bool HasTwoPairs(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = MapOccurences(compoundHand);
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
bool HasBrelan(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = MapOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 3)
		{
			return true;
		}
	}

	return false;

}
bool HasSquare(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = MapOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 4)
		{
			return true;
		}
	}

	return false;

}
