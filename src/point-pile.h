#pragma once

#include <set>

namespace koikoi {
enum class Card;

class PointPile
{
public:
	void take(Card card);
	void clear();

	int brightCount() const;
	int kindCount() const;
	int ribbonCount() const;
	int plainCount() const;

	bool hasCard(Card card) const;
	bool hasBoarDeerButterfly() const;
	bool hasRedRibbons() const;
	bool hasBlueRibbons() const;
	bool hasViewingTheFlower() const;
	bool hasViewingTheMoon() const;

private:
	std::set<Card> cards;
	std::set<Card> brights;
	std::set<Card> kinds;
	std::set<Card> ribbons;
	std::set<Card> plains;
};
}
