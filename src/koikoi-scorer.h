#pragma once

#include <set>
#include "card-define.h"

class KoikoiScorer
{
public:
    void take(Card card);
	void clear();
    int total() const;

private:
	bool isBright(Card card) const;
	bool hasCard(Card card) const;

private:	
	std::set<Card> cards;
	std::set<Card> brights;
};
