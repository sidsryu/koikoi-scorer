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
	score += viewingScore();

	score = sevenDoubleScore(score);	
	return score;
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
	bool is_bdb = false;
	
	// Boar-Deer-Butterfly
	if (hasCard(Card::CloverKind)
		&& hasCard(Card::MapleKind) && hasCard(Card::PeonyKind))
	{
		score += 5;
		is_bdb = true;
	}

	// Rule
	size_t extra_point_begin_count = 5;
	if (hasRule(Rule::ExtraPointAfterBoarDeerButterfly) && is_bdb)
	{
		extra_point_begin_count = 4;
	}

	// Kinds
	if (extra_point_begin_count <= kinds.size())
	{
		score += kinds.size() - (extra_point_begin_count-1);
	}

	return score;
}

int KoikoiScorer::ribbonsScore() const
{
	int score = 0;
	bool is_red_ribbons = false;
	bool is_blue_ribbons = false;

	// RedRibbon
	if (hasCard(Card::PineRibbon)
		&& hasCard(Card::PlumRibbon) && hasCard(Card::CherryRibbon))
	{
		score += 5;
		is_red_ribbons = true;
	}

	// BlueRibbon
	if (hasCard(Card::MumsRibbon)
		&& hasCard(Card::PeonyRibbon) && hasCard(Card::MapleRibbon))
	{
		score += 5;
		is_blue_ribbons = true;
	}
	
	// Rule
	size_t extra_point_begin_count = 5;
	if (hasRule(Rule::ExtraPointAfterRedBlueRibbons))
	{
		if (is_red_ribbons) extra_point_begin_count = 4;
		if (is_blue_ribbons) extra_point_begin_count = 4;
		if (is_red_ribbons && is_blue_ribbons) extra_point_begin_count = 7;
	}

	// Ribbons
	if (extra_point_begin_count <= ribbons.size())
	{
		score += ribbons.size() - (extra_point_begin_count-1);
	}

	return score;
}

int KoikoiScorer::plainsScore() const
{
	int extra_plains = 0;
	if (hasRule(Rule::SakeCupBothKindAndPlain) && hasCard(Card::MumsKind))
	{
		extra_plains = 1;
	}

	int total_plains = plains.size() + extra_plains;
	if (10 <= total_plains)
	{
		return total_plains - 9;
	}

	return 0;
}

int KoikoiScorer::viewingScore() const
{
	if (!hasCard(Card::MumsKind)) return 0;

	int score = 0;

	if (hasRule(Rule::ViewingTheFlower) && hasCard(Card::CherryBright)) score += 5;
	if (hasRule(Rule::ViewingTheMoon) && hasCard(Card::PampasBright)) score += 5;

	return score;
}

int KoikoiScorer::sevenDoubleScore(int total_score) const
{
	if (hasRule(Rule::SevenOrMoreDoubled) && 7 <= total_score)
	{
		return total_score * 2;
	}

	return total_score;
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
