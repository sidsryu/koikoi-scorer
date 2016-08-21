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

void KoikoiScorer::addRule(Rule rule)
{
	rules.insert(rule);
}

void KoikoiScorer::clear()
{
	cards.clear();
	brights.clear();
	kinds.clear();
	ribbons.clear();
	plains.clear();

	rules.clear();
}

int KoikoiScorer::total() const
{
	int score = 0;

	score += brightsScore();
	score += kindsScore();
	score += ribbonsScore();
	score += plainsScore();
	score += specialScore();

	return finalScore(score);
}

int KoikoiScorer::brightsScore() const
{
	if (hasCard(Card::WillowBright))
	{
		if (5 == brights.size()) return 10;
		if (4 == brights.size()) return 5;
	}
	else
	{
		if (4 == brights.size()) return 8;
		if (3 == brights.size()) return 5;
	}

	return 0;
}

int KoikoiScorer::kindsScore() const
{
	int score = 0;

	if (hasBoarDeerButterfly()) score += 5;

	size_t count = countForKindsPoint();
	if (count <= kinds.size())
	{
		score += kinds.size() - (count-1);
	}

	return score;
}

int KoikoiScorer::ribbonsScore() const
{
	int score = 0;

	if (hasRedRibbons()) score += 5;
	if (hasBlueRibbons()) score += 5;

	size_t count = countForRibbonsPoint();
	if (count <= ribbons.size())
	{
		score += ribbons.size() - (count-1);
	}

	return score;
}

int KoikoiScorer::plainsScore() const
{
	int total_plains = plains.size() + extraPlainCount();
	if (10 <= total_plains)
	{
		return total_plains - 9;
	}

	return 0;
}

int KoikoiScorer::specialScore() const
{
	int score = 0;

	if (hasRule(Rule::ViewingTheFlower))
	{
		if (hasViewingTheFlower()) score += 5;		
	}

	if (hasRule(Rule::ViewingTheMoon))
	{
		if (hasViewingTheMoon()) score += 5;
	}

	return score;
}

int KoikoiScorer::finalScore(int total_score) const
{
	if (hasRule(Rule::SevenOrMoreDoubled))
	{
		if (7 <= total_score) return total_score * 2;
	}

	return total_score;
}

bool KoikoiScorer::hasBoarDeerButterfly() const
{
	return hasCard(Card::CloverKind)
		&& hasCard(Card::MapleKind) && hasCard(Card::PeonyKind);
}

bool KoikoiScorer::hasRedRibbons() const
{
	return hasCard(Card::PineRibbon)
		&& hasCard(Card::PlumRibbon) && hasCard(Card::CherryRibbon);
}

bool KoikoiScorer::hasBlueRibbons() const
{
	return hasCard(Card::MumsRibbon)
		&& hasCard(Card::PeonyRibbon) && hasCard(Card::MapleRibbon);
}

bool KoikoiScorer::hasViewingTheFlower() const
{
	return  hasCard(Card::CherryBright) && hasCard(Card::MumsKind);
}

bool KoikoiScorer::hasViewingTheMoon() const
{
	return hasCard(Card::PampasBright) && hasCard(Card::MumsKind);
}

size_t KoikoiScorer::countForKindsPoint() const
{
	if (hasRule(Rule::ExtraPointAfterBoarDeerButterfly))
	{
		if (hasBoarDeerButterfly()) return 4;
	}

	return 5;
}

size_t KoikoiScorer::countForRibbonsPoint() const
{
	if (hasRule(Rule::ExtraPointAfterRedBlueRibbons))
	{
		if (hasRedRibbons() && hasBlueRibbons()) return 7;
		if (hasRedRibbons()) return 4;
		if (hasBlueRibbons()) return 4;
	}

	return 5;
}

int KoikoiScorer::extraPlainCount() const
{
	if (hasRule(Rule::SakeCupBothKindAndPlain))
	{
		if (hasCard(Card::MumsKind)) return 1;
	}

	return 0;
}

bool KoikoiScorer::hasCard(Card card) const
{
	auto it = cards.find(card);
	return it != cards.end();
}

bool KoikoiScorer::hasRule(Rule rule) const
{
	auto it = rules.find(rule);
	return it != rules.end();
}
