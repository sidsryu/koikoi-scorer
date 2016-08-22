#include "point-counter.h"
#include "point-pile.h"
#include "point-rules.h"
#include "card-define.h"
#include "rule-define.h"

using namespace std;

PointCounter::PointCounter(const PointPile& pile, const PointRules& rules)
	: pile(pile)
	, rules(rules)
{}

int PointCounter::total()
{
	scoreBrights();
	scoreKinds();
	scoreRibbons();
	scorePlains();
	scoreSpecial();

	return scoreFinal(score);
}

void PointCounter::scoreBrights()
{
	auto bright_count = pile.brightCount();

	if (pile.hasCard(Card::WillowBright))
	{
		if (5 == bright_count) score += 10;
		if (4 == bright_count) score += 5;
	}
	else
	{
		if (4 == bright_count) score += 8;
		if (3 == bright_count) score += 5;
	}
}

void PointCounter::scoreKinds()
{
	if (pile.hasBoarDeerButterfly()) score += 5;

	auto count = minKinds();
	if (count <= pile.kindCount())
	{
		score += pile.kindCount() - (count - 1);
	}
}

void PointCounter::scoreRibbons()
{
	if (pile.hasRedRibbons()) score += 5;
	if (pile.hasBlueRibbons()) score += 5;

	auto count = minRibbons();
	if (count <= pile.ribbonCount())
	{
		score += pile.ribbonCount() - (count - 1);
	}
}

void PointCounter::scorePlains()
{
	auto total_plains = pile.plainCount() + extraPlains();
	if (10 <= total_plains)
	{
		score += total_plains - 9;
	}
}

void PointCounter::scoreSpecial()
{	
	if (rules.hasRule(Rule::ViewingTheFlower))
	{
		if (pile.hasViewingTheFlower()) score += 5;
	}

	if (rules.hasRule(Rule::ViewingTheMoon))
	{
		if (pile.hasViewingTheMoon()) score += 5;
	}
}

int PointCounter::scoreFinal(int total_score) const
{
	if (rules.hasRule(Rule::SevenOrMoreDoubled))
	{
		if (7 <= total_score) return total_score * 2;
	}

	return total_score;
}

int PointCounter::minKinds() const
{
	if (rules.hasRule(Rule::ExtraPointAfterBoarDeerButterfly))
	{
		if (pile.hasBoarDeerButterfly()) return 4;
	}

	return 5;
}

int PointCounter::minRibbons() const
{
	if (rules.hasRule(Rule::ExtraPointAfterRedBlueRibbons))
	{
		if (pile.hasRedRibbons() && pile.hasBlueRibbons()) return 7;
		if (pile.hasRedRibbons()) return 4;
		if (pile.hasBlueRibbons()) return 4;
	}

	return 5;
}

int PointCounter::extraPlains() const
{
	if (rules.hasRule(Rule::SakeCupBothKindAndPlain))
	{
		if (pile.hasCard(Card::MumsKind)) return 1;
	}

	return 0;
}
