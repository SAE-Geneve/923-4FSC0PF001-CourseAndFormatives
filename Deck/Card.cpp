

#include "Card.h"

#include <string>

std::string ToString(Card _card)
{
	return ToString(_card.rank) + " of " + ToString(_card.suit);
}


std::string ToString(Rank _rank)
{
	switch (_rank)
	{
	case Two:
		return "Two";
		break;
	case Three:
		return "Three";
		break;
	case Four:
		return "Four";
		break;
	case Five:
		return "Five";
		break;
	case Six:
		return "Six";
		break;
	case Seven:
		return "Seven";
		break;
	case Eight:
		return "Eight";
		break;
	case Nine:
		return "Nine";
		break;
	case Ten:
		return "Ten";
		break;
	case Jack:
		return "Jack";
		break;
	case Queen:
		return "Queen";
		break;
	case King:
		return "King";
		break;
	case Ace:
		return "Ace";
		break;
	default:
		return "no_rank";
	}


}
std::string ToString(Suit _suit)
{
	switch (_suit)
	{
	case Hearts:
		return "Hearts";
		break;
	case Spades:
		return "Spades";
		break;
	case Diamonds:
		return "Diamonds";
		break;
	case Clubs:
		return "Clubs";
		break;
	default:
		return "_no_suit";
	}
}