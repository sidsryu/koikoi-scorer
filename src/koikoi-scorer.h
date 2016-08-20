#pragma once

#include <vector>
#include "card-define.h"

class KoikoiScorer
{
public:
    void take(Card card);
	void clear();
    int total() const;

private:
	std::vector<Card> cards;
};
