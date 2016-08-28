#pragma once

#include <map>

namespace koikoi {
enum class ScoringHand;
class PointPile;
class PointRules;

class ScoreTable
{
public:
	ScoreTable(const PointPile& pile, const PointRules& rules);
	int score(ScoringHand hand) const;

private:
	void defaultTable();
	void modifyTable();

	int scoreKinds() const;
	int scoreRibbons() const;
	int scorePlains() const;

private:
	const PointPile& pile;
	const PointRules& rules;

	std::map<ScoringHand, int> scores;
};
}
