#pragma once

#include <memory>

enum class Card;
enum class Rule;
enum class Month;
class PointPile;
class PointRules;
class MonthlyCard;

class KoikoiScorer
{
public:
	KoikoiScorer();
	virtual ~KoikoiScorer();

	void take(Card card);
	void addRule(Rule option);
	void setMonth(Month month);
	void clear();

	int total() const;

private:
	std::unique_ptr<PointPile> pile;
	std::unique_ptr<PointRules> rules;
	std::unique_ptr<MonthlyCard> monthly_card;
};
