#include "score-table.h"
#include "scoring-define.h"
#include "point-rules.h"
#include "point-pile.h"
#include "rule-define.h"
#include "card-define.h"

ScoreTable::ScoreTable(const PointPile& pile, const PointRules& rules)
	: pile(pile)
	, rules(rules)
{
	defaultTable();
	modifyTable();
}

void ScoreTable::defaultTable()
{
	scores.insert({ ScoringHand::FiveBrights, 10 });
	scores.insert({ ScoringHand::FourBrights, 8 });
	scores.insert({ ScoringHand::ThreeBrights, 5 });
	scores.insert({ ScoringHand::ViewingTheFlower, 5 });
	scores.insert({ ScoringHand::ViewingTheMoon, 5 });
	scores.insert({ ScoringHand::BoarDeerButterfly, 5 });
	scores.insert({ ScoringHand::RedRibbons, 5 });
	scores.insert({ ScoringHand::BlueRibbons, 5 });
	scores.insert({ ScoringHand::Kinds, 1 });
	scores.insert({ ScoringHand::Ribbons, 1 });
	scores.insert({ ScoringHand::Plains, 1 });
	scores.insert({ ScoringHand::RainyFourBrights, 7 });
	scores.insert({ ScoringHand::MonthlyCards, 4 });
}

void ScoreTable::modifyTable()
{
	if (rules.hasRule(Rule::SixPointsThreeBrights))
	{
		scores[ScoringHand::ThreeBrights] = 6;
	}
}

int ScoreTable::score(ScoringHand hand) const
{
	auto it = scores.find(hand);
	if (it == scores.end())	return 0;

	// special scoring hands
	if (hand == ScoringHand::Kinds) return scoreKinds();
	if (hand == ScoringHand::Ribbons) return scoreRibbons();
	if (hand == ScoringHand::Plains) return scorePlains();

	return it->second;
}

int ScoreTable::scoreKinds() const
{
	auto count = pile.kindCount();

	if (rules.hasRule(Rule::ExtraPointAfterBoarDeerButterfly))
	{
		if (pile.hasBoarDeerButterfly()) return count - 3;
	}

	return count - 4;
}

int ScoreTable::scoreRibbons() const
{
	auto count = pile.ribbonCount();

	if (rules.hasRule(Rule::ExtraPointAfterRedBlueRibbons))
	{
		if (pile.hasRedRibbons() && pile.hasBlueRibbons()) return count - 6;
		if (pile.hasBlueRibbons()) return count - 3;
		if (pile.hasRedRibbons()) return count - 3;
	}
	
	return count - 4;
}

int ScoreTable::scorePlains() const
{
	auto count = pile.plainCount();

	if (rules.hasRule(Rule::SakeCupBothKindAndPlain))
	{
		if (pile.hasCard(Card::MumsKind)) return count - 8;
	}

	return count - 9;
}
