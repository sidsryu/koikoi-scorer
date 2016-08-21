#pragma once

#include <set>
#include <initializer_list>

enum class Card;
enum class Rule;

class KoikoiScorer
{
public:
    void take(Card card);
	void addRule(Rule option);
	void clear();	

    int total() const;

private:
	int brightsScore() const;
	int kindsScore() const;
	int ribbonsScore() const;
	int plainsScore() const;
	int viewingScore() const;	
	int sevenDoubleScore(int score) const;

	bool hasCard(Card card) const;	
	bool hasRule(Rule rule) const;

private:
	std::set<Card> cards;
	std::set<Card> brights;
	std::set<Card> kinds;
	std::set<Card> ribbons;
	std::set<Card> plains;

	std::set<Rule> rules;
};
