#include "koikoi-scorer.h"

using namespace std;

void KoikoiScorer::take(Card card)
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
	bool is_sake_cup = false;
	bool is_moon = false;
	bool is_flower = false;

	for (auto it : cards)
	{
		if (it == Card::PineBright) bright_count++;
		if (it == Card::CherryBright)
		{
			bright_count++;
			is_flower = true;
		}

		if (it == Card::PampasBright)
		{
			bright_count++;
			is_moon = true;
		}

		if (it == Card::PaulowniaBright) bright_count++;

		if (it == Card::WillowBright) is_willow_bright = true;


		if (it == Card::MumsKind)
		{
			is_sake_cup = true;
		}
	}

	if (bright_count == 4 && is_willow_bright) return 10;
	if (bright_count == 4) return 8;
	if (bright_count == 3) return 5;
	if (is_sake_cup && is_moon) return 5;
	if (is_sake_cup && is_flower) return 5;
	
	return 0;
}
