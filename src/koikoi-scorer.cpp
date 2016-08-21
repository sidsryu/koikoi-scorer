#include "koikoi-scorer.h"
#include "card-define.h"
#include <algorithm>

using namespace std;

void KoikoiScorer::take(Card card)
{
	cards.insert(card);

	if (isBright(card)) brights.insert(card);
	if (isKind(card)) kinds.insert(card);
	if (isRibbon(card)) ribbons.insert(card);
	if (isPlain(card)) plains.insert(card);
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

	// Kinds
	if (5 <= kinds.size())
	{
		score += kinds.size() - 4;
	}

	// Ribbons
	if (5 <= ribbons.size())
	{
		score += ribbons.size() - 4;
	}

	// Plains
	if (10 <= plains.size())
	{
		score += plains.size() - 9;
	}

	// Viewing
	if (hasCard(Card::MumsKind))
	{
		if (hasCard(Card::PampasBright)) score += 5;
		if (hasCard(Card::CherryBright)) score += 5;
	}

	// Boar-Deer-Butterfly
	if (hasCard({ Card::CloverKind, Card::MapleKind, Card::PeonyKind }))
	{
		score += 5;
	}

	// RedRibbon
	if (hasCard({ Card::PineRibbon, Card::PlumRibbon, Card::CherryRibbon }))
	{
		score += 5;
	}

	// BlueRibbon
	if (hasCard({ Card::MumsRibbon, Card::PeonyRibbon, Card::MapleRibbon }))
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

bool KoikoiScorer::isKind(Card card) const
{
	if (card == Card::PlumKind) return true;
	if (card == Card::WisteriaKind) return true;
	if (card == Card::IrisKind) return true;
	if (card == Card::PeonyKind) return true;
	if (card == Card::CloverKind) return true;
	if (card == Card::PampasKind) return true;
	if (card == Card::MumsKind) return true;
	if (card == Card::MapleKind) return true;
	if (card == Card::WillowKind) return true;

	return false;
}

bool KoikoiScorer::isRibbon(Card card) const
{
	if (card == Card::PineRibbon) return true;
	if (card == Card::PlumRibbon) return true;
	if (card == Card::CherryRibbon) return true;
	if (card == Card::WisteriaRibbon) return true;
	if (card == Card::IrisRibbon) return true;
	if (card == Card::PeonyRibbon) return true;
	if (card == Card::CloverRibbon) return true;
	if (card == Card::MumsRibbon) return true;
	if (card == Card::MapleRibbon) return true;
	if (card == Card::WillowRibbon) return true;

	return false;
}

bool KoikoiScorer::isPlain(Card card) const
{
	if (card == Card::PinePlain1) return true;
	if (card == Card::PinePlain2) return true;
	if (card == Card::PlumPlain1) return true;
	if (card == Card::PlumPlain2) return true;
	if (card == Card::CherryPlain1) return true;
	if (card == Card::CherryPlain2) return true;
	if (card == Card::WisteriaPlain1) return true;
	if (card == Card::WisteriaPlain2) return true;
	if (card == Card::IrisPlain1) return true;
	if (card == Card::IrisPlain2) return true;
	if (card == Card::PeonyPlain1) return true;
	if (card == Card::PeonyPlain2) return true;
	if (card == Card::CloverPlain1) return true;
	if (card == Card::CloverPlain2) return true;
	if (card == Card::PampasPlain1) return true;
	if (card == Card::PampasPlain2) return true;
	if (card == Card::MumsPlain1) return true;
	if (card == Card::MumsPlain2) return true;
	if (card == Card::MaplePlain1) return true;
	if (card == Card::MaplePlain2) return true;
	if (card == Card::WillowPlain) return true;
	if (card == Card::PaulowniaPlain1) return true;
	if (card == Card::PaulowniaPlain2) return true;
	if (card == Card::PaulowniaPlain3) return true;

	return false;
}

bool KoikoiScorer::hasCard(Card card) const
{
	auto it = cards.find(card);
	return it != cards.end();
}

bool KoikoiScorer::hasCard(initializer_list<Card> l) const
{
	for (auto it : l)
	{
		if (!hasCard(it))	return false;
	}

	return true;
}
