#include "begining-hands.h"
#include "card-define.h"
#include "card-functor.h"

using namespace std;

namespace koikoi {
void BeginingHands::deal(Card card)
{
	auto month = static_cast<int>(ToMonth()(card));
	suit_counter[month - 1]++;
}

void BeginingHands::clear()
{
	suit_counter = {};
}

int BeginingHands::score() const
{
	int pair_count = 0;

	for (auto it : suit_counter)
	{
		if (it == 0) continue;
		if (4 <= it) return 6;
		if (2 == it) pair_count++;
	}

	if (4 <= pair_count) return 6;

	return 0;
}
}
