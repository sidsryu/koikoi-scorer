#pragma once

#include <memory>

enum class Card;
enum class Rule;
class PointPile;
class PointRules;

class KoikoiScorer
{
public:
	KoikoiScorer();
	virtual ~KoikoiScorer();

	void take(Card card);
	void addRule(Rule option);
	void clear();

	int total() const;

private:
	std::unique_ptr<PointPile> pile;	
	std::unique_ptr<PointRules> rules;
};
