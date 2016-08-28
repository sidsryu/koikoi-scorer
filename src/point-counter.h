#pragma once

class PointPile;
class PointRules;
class MonthlyCard;

class PointCounter
{
public:
	PointCounter(const PointPile& pile, const PointRules& rules, const MonthlyCard& monthly_card);

	int total();

private:
	void scoreBrights();
	void scoreKinds();
	void scoreRibbons();
	void scorePlains();
	void scoreViewing();
	void scoreMonthly();
	int scoreFinal(int score) const;

	int minKinds() const;
	int minRibbons() const;
	int extraPlains() const;

private:
	const PointPile& pile;
	const PointRules& rules;
	const MonthlyCard& monthly_card;

	int score { 0 };
};
