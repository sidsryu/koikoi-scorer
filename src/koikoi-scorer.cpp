#include "koikoi-scorer.h"
#include "point-pile.h"
#include "point-rules.h"
#include "point-counter.h"
#include "monthly-card.h"

using namespace std;

KoikoiScorer::KoikoiScorer()
	: pile(make_unique<PointPile>())
	, rules(make_unique<PointRules>())
	, monthly_card(make_unique<MonthlyCard>())
{}

KoikoiScorer::~KoikoiScorer() = default;

void KoikoiScorer::take(Card card)
{
	pile->take(card);
}

void KoikoiScorer::addRule(Rule rule)
{
	rules->addRule(rule);
}

void KoikoiScorer::setMonth(Month month)
{
	monthly_card->setMonth(month);
}

void KoikoiScorer::clear()
{
	pile->clear();
	rules->clear();
}

int KoikoiScorer::total() const
{
	PointCounter c(*pile, *rules, *monthly_card);
	return c.total();
}
