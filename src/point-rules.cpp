#include "point-rules.h"
#include "rule-define.h"

void PointRules::addRule(Rule rule)
{
	rules.insert(rule);
}

void PointRules::clear()
{
	rules.clear();
}

bool PointRules::hasRule(Rule rule) const
{
	auto it = rules.find(rule);
	return it != rules.end();
}
