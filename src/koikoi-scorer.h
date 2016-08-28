#pragma once

#include <memory>

namespace koikoi {
enum class Card;
enum class Rule;
enum class Month;
class PointPile;
class PointRules;
class MonthlyCard;
struct ScoreReport;

class KoikoiScorer
{
public:
	KoikoiScorer();
	virtual ~KoikoiScorer();

	void take(Card card);
	void addRule(Rule option);
	void setMonth(Month month);
	void clear();

	ScoreReport report() const;

private:
	std::unique_ptr<PointPile> pile;
	std::unique_ptr<PointRules> rules;
	std::unique_ptr<MonthlyCard> monthly_card;
};
}
