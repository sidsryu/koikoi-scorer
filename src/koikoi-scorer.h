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
	int specialScore() const;
	int finalScore(int total_score) const;

	bool hasBoarDeerButterfly() const;
	bool hasRedRibbons() const;
	bool hasBlueRibbons() const;
	bool hasViewingTheFlower() const;
	bool hasViewingTheMoon() const;
	bool hasCard(Card card) const;	
	bool hasRule(Rule rule) const;

	std::size_t countForKindsPoint() const;
	std::size_t countForRibbonsPoint() const;
	int extraPlainCount() const;

private:
	std::set<Card> cards;
	std::set<Card> brights;
	std::set<Card> kinds;
	std::set<Card> ribbons;
	std::set<Card> plains;

	std::set<Rule> rules;
};
