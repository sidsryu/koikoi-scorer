#include "koikoi-scorer.h"
#include "point-pile.h"
#include "point-rules.h"
#include "monthly-card.h"
#include "scoring-hand-calculator.h"
#include "score-table.h"
#include "rule-define.h"
#include "score-report.h"

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

ScoreReport KoikoiScorer::report() const
{
	// check scoring hand
	ScoringHandCalculator s(*pile, *rules, *monthly_card);
	s.calculate();

	// scoring
	ScoreReport report;
	ScoreTable table(*pile, *rules);

	s.each([&report, &table](ScoringHand hand) {
		auto score = table.score(hand);

		report.scores.insert({ hand, score });
		report.score += score;
	});

	// final scoring modify
	if (rules->hasRule(Rule::SevenOrMoreDoubled))
	{
		if (7 <= report.score) report.multiple = 2;
	}

	report.total = report.score * report.multiple;
	return report;
}
