#pragma once

#include <set>

enum class Rule;

class PointRules
{
public:
	void addRule(Rule rule);	
	void clear();

	bool hasRule(Rule rule) const;

private:
	std::set<Rule> rules;
};
