#include "koikoi-scorer.h"
#include "point-pile.h"
#include "point-rules.h"
#include "point-counter.h"

using namespace std;

KoikoiScorer::KoikoiScorer()
	: pile(make_unique<PointPile>())
	, rules(make_unique<PointRules>())
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

void KoikoiScorer::clear()
{
	pile->clear();
	rules->clear();
}

int KoikoiScorer::total() const
{
	PointCounter c(*pile, *rules);
	return c.total();
}
