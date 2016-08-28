#pragma once

#include <set>
#include <functional>

namespace koikoi {
enum class ScoringHand;
class PointPile;
class PointRules;
class MonthlyCard;

class ScoringHandCalculator
{
public:
	ScoringHandCalculator(const PointPile& pile, const PointRules& rules, const MonthlyCard& monthly_card);
	void calculate();
	void each(std::function<void(ScoringHand)> fn);

private:
	void calculateFiveBrights();
	void calculateFourBrights();
	void calculateThreeBrights();
	void calculateViewingTheFlower();
	void calculateViewingTheMoon();
	void calculateBoarDeerButterfly();
	void calculateRedRibbons();
	void calculateBlueRibbons();
	void calculateRainyFourBrights();
	void calculateMonthlyCards();
	void calculateKinds();
	void calculateRibbons();
	void calculatePlains();

	bool isRaining() const;

private:
	const PointPile& pile;
	const PointRules& rules;
	const MonthlyCard& monthly_card;

	std::set<ScoringHand> hands;
};
}
