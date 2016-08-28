#include "scoring-hand-calculator.h"
#include "point-pile.h"
#include "point-rules.h"
#include "monthly-card.h"
#include "card-define.h"
#include "rule-define.h"
#include "scoring-define.h"

ScoringHandCalculator::ScoringHandCalculator(const PointPile& pile, const PointRules& rules, const MonthlyCard& monthly_card)
	: pile(pile)
	, rules(rules)
	, monthly_card(monthly_card)
{}

void ScoringHandCalculator::calculate()
{
	calculateFiveBrights();
	calculateFourBrights();
	calculateThreeBrights();
	calculateViewingTheFlower();
	calculateViewingTheMoon();
	calculateBoarDeerButterfly();
	calculateRedRibbons();
	calculateBlueRibbons();
	calculateKinds();
	calculateRibbons();
	calculatePlains();
	calculateRainyFourBrights();
	calculateMonthlyCards();
}

void ScoringHandCalculator::each(std::function<void(ScoringHand)> fn)
{
	for (auto it : hands)
	{
		fn(it);
	}
}

void ScoringHandCalculator::calculateFiveBrights()
{
	if (5 == pile.brightCount())
	{
		hands.insert(ScoringHand::FiveBrights);
	}
}

void ScoringHandCalculator::calculateFourBrights()
{
	if (4 == pile.brightCount() && !pile.hasCard(Card::WillowBright))
	{
		hands.insert(ScoringHand::FourBrights);
	}
}

void ScoringHandCalculator::calculateThreeBrights()
{
	if (pile.hasCard(Card::WillowBright))
	{
		if (4 == pile.brightCount() && !rules.hasRule(Rule::RainyFourBrights))
		{
			hands.insert(ScoringHand::ThreeBrights);
		}
	}
	else
	{
		if (3 == pile.brightCount())
		{
			hands.insert(ScoringHand::ThreeBrights);
		}
	}
}

void ScoringHandCalculator::calculateViewingTheFlower()
{
	if (!rules.hasRule(Rule::ViewingTheFlower)) return;
	if (rules.hasRule(Rule::RainBreakViewings))
	{
		if (isRaining()) return;
	}

	if (pile.hasViewingTheFlower())
	{
		hands.insert(ScoringHand::ViewingTheFlower);
	}
}

bool ScoringHandCalculator::isRaining() const
{
	if (pile.hasCard(Card::WillowBright)) return true;
	if (pile.hasCard(Card::WillowPlain)) return true;

	if (rules.hasRule(Rule::WillowIsRain))
	{
		if (pile.hasCard(Card::WillowKind)) return true;
		if (pile.hasCard(Card::WillowRibbon)) return true;
	}

	return false;
}

void ScoringHandCalculator::calculateViewingTheMoon()
{
	if (!rules.hasRule(Rule::ViewingTheMoon)) return;
	if (rules.hasRule(Rule::RainBreakViewings))
	{
		if (isRaining()) return;
	}

	if (pile.hasViewingTheMoon())
	{
		hands.insert(ScoringHand::ViewingTheMoon);
	}
}

void ScoringHandCalculator::calculateBoarDeerButterfly()
{
	if (pile.hasBoarDeerButterfly())
	{
		hands.insert(ScoringHand::BoarDeerButterfly);
	}
}

void ScoringHandCalculator::calculateRedRibbons()
{
	if (pile.hasRedRibbons())
	{
		hands.insert(ScoringHand::RedRibbons);
	}
}

void ScoringHandCalculator::calculateBlueRibbons()
{
	if (pile.hasBlueRibbons())
	{
		hands.insert(ScoringHand::BlueRibbons);
	}
}

void ScoringHandCalculator::calculateRainyFourBrights()
{
	if (!rules.hasRule(Rule::RainyFourBrights)) return;

	if (4 == pile.brightCount() && pile.hasCard(Card::WillowBright))
	{
		hands.insert(ScoringHand::RainyFourBrights);
	}
}

void ScoringHandCalculator::calculateMonthlyCards()
{
	if (!rules.hasRule(Rule::MonthlyCards)) return;

	if (monthly_card.hasMonth(pile))
	{
		hands.insert(ScoringHand::MonthlyCards);
	}
}

void ScoringHandCalculator::calculateKinds()
{
	auto min_count = 5;

	if (rules.hasRule(Rule::ExtraPointAfterBoarDeerButterfly))
	{
		if (pile.hasBoarDeerButterfly())
		{
			min_count = 4;
		}
	}
	
	if (min_count <= pile.kindCount())
	{
		hands.insert(ScoringHand::Kinds);
	}
}

void ScoringHandCalculator::calculateRibbons()
{
	auto min_count = 5;

	if (rules.hasRule(Rule::ExtraPointAfterRedBlueRibbons))
	{
		if (pile.hasRedRibbons() && pile.hasBlueRibbons()) min_count = 7;
		else if (pile.hasRedRibbons()) min_count = 4;
		else if (pile.hasBlueRibbons()) min_count = 4;
	}

	if (min_count <= pile.ribbonCount())
	{
		hands.insert(ScoringHand::Ribbons);
	}
}

void ScoringHandCalculator::calculatePlains()
{
	auto extra_plain = 0;

	if (rules.hasRule(Rule::SakeCupBothKindAndPlain))
	{
		if (pile.hasCard(Card::MumsKind))
		{
			extra_plain = 1;
		}
	}
	
	if (10 <= pile.plainCount() + extra_plain)
	{
		hands.insert(ScoringHand::Plains);
	}
}
