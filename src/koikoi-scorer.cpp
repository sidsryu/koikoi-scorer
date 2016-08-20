#include "koikoi-scorer.h"

using namespace std;

void KoikoiScorer::take(int card)
{
	cards.push_back(card);
}

void KoikoiScorer::clear()
{
	cards.clear();
}

int KoikoiScorer::total() const
{
	int bright_count = 0;
	bool is_willow_bright = false;

	for (auto it : cards)
	{
		if (it == 11)	bright_count++;
		if (it == 31)	bright_count++;
		if (it == 81)	bright_count++;
		if (it == 121)	bright_count++;

		if (it == 111)  is_willow_bright = true;
	}

	if (bright_count == 4 && is_willow_bright) return 10;
	if (bright_count == 4) return 8;
	if (bright_count == 3) return 5;

	return 0;
}
