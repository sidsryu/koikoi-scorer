#pragma once

class PointPile;
class PointRules;

class PointCounter
{
public:
	PointCounter(const PointPile& pile, const PointRules& rules);

	int total();

private:
	void scoreBrights();
	void scoreKinds();
	void scoreRibbons();
	void scorePlains();
	void scoreSpecial();
	int scoreFinal(int score) const;

	int minKinds() const;
	int minRibbons() const;
	int extraPlains() const;

private:
	const PointPile& pile;
	const PointRules& rules;
	int score { 0 };
};
