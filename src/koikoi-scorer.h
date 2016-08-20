#pragma once

#include <vector>

class KoikoiScorer
{
public:
    void take(int card);
	void clear();
    int total() const;

private:
	std::vector<int> cards;
};
