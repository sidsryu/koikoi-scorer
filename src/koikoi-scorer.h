#pragma once

#include <set>
#include <initializer_list>

enum class Card;

class KoikoiScorer
{
public:
    void take(Card card);
	void clear();
    int total() const;

private:
	bool hasCard(Card card) const;
	bool hasCard(std::initializer_list<Card> l) const;

private:
	std::set<Card> cards;
	std::set<Card> brights;
	std::set<Card> kinds;
	std::set<Card> ribbons;
	std::set<Card> plains;
};
