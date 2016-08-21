#include "koikoi-scorer.h"
#include "card-define.h"
#include "card-functor.h"
#include "rule-define.h"
#include <algorithm>

using namespace std;

void KoikoiScorer::take(Card card)
{
	cards.insert(card);

	if (IsBright()(card)) brights.insert(card);
	if (IsKind()(card)) kinds.insert(card);
	if (IsRibbon()(card)) ribbons.insert(card);
	if (IsPlain()(card)) plains.insert(card);
}

void KoikoiScorer::clear()
{
	cards.clear();

	brights.clear();
	kinds.clear();
	ribbons.clear();
	plains.clear();
}

void KoikoiScorer::addRule(Rule rule)
{
	rules.insert(rule);
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
	int extra_plain = 0;
	if (hasRule(Rule::SakeCup) && hasCard(Card::MumsKind))
	{
		extra_plain = 1;
	}

	if (10 <= plains.size() + extra_plain)
	{
		score += plains.size() + extra_plain - 9;
	}

	// Viewing
	if (hasCard(Card::MumsKind))
	{
		if (hasRule(Rule::ViewingTheFlower) && hasCard(Card::CherryBright)) score += 5;
		if (hasRule(Rule::ViewingTheMoon) && hasCard(Card::PampasBright)) score += 5;
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

	// Options
	if (hasRule(Rule::SevenDouble) && 7 <= score) score *= 2;

	return score;
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

bool KoikoiScorer::hasRule(Rule rule) const
{
	auto it = rules.find(rule);
	return it != rules.end();
}
