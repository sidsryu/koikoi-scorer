#pragma once

#include <map>

namespace koikoi {
enum class ScoringHand;

struct ScoreReport
{
public:
	std::map<ScoringHand, int> scores;
	int score { 0 };
	int multiple { 1 };
	int total { 0 };
};
}
