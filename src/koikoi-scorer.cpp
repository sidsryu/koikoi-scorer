#include "koikoi-scorer.h"
#include "point-pile.h"
#include "point-rules.h"
#include "monthly-card.h"
#include "scoring-hand-calculator.h"
#include "score-table.h"
#include "rule-define.h"

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
	// check scoring hand
	ScoringHandCalculator s(*pile, *rules, *monthly_card);
	s.calculate();

	// scoring
	int score = 0;
	ScoreTable table(*pile, *rules);

	s.each([&score, &table](ScoringHand hand) {
		score += table.score(hand);
	});

	// final scoring modify
	if (rules->hasRule(Rule::SevenOrMoreDoubled))
	{
		if (7 <= score) score *= 2;
	}

	return score;
}
