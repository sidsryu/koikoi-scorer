#include "koikoi-scorer.h"

using namespace std;

void KoikoiScorer::take(Card card)
{
	cards.insert(card);
	if (isBright(card)) brights.insert(card);
}

void KoikoiScorer::clear()
{
	cards.clear();
	brights.clear();
}

int KoikoiScorer::total() const
{
	int score = 0;

	// Brights
	if (hasCard(Card::WillowBright))
	{
		if (5 == brights.size()) score += 10;
		if (4 == brights.size()) score += 5;
	}
	else
	{
		if (4 == brights.size()) score += 8;
		if (3 == brights.size()) score += 5;
	}

	// Viewing
	if (hasCard(Card::MumsKind))
	{
		if (hasCard(Card::PampasBright)) score += 5;
		if (hasCard(Card::CherryBright)) score += 5;
	}

	// Boar-Deer-Butterfly
	if (hasCard(Card::CloverKind) && hasCard(Card::MapleKind)
		&& hasCard(Card::PeonyKind))
	{
		score += 5;
	}

	return score;
}

bool KoikoiScorer::isBright(Card card) const
{
	if (card == Card::PineBright) return true;
	if (card == Card::CherryBright) return true;
	if (card == Card::PampasBright) return true;
	if (card == Card::WillowBright) return true;
	if (card == Card::PaulowniaBright) return true;

	return false;
}

bool KoikoiScorer::hasCard(Card card) const
{
	auto it = cards.find(card);
	return it != cards.end();
}
