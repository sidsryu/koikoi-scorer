#pragma once

#include <array>

enum class Card;

class BeginingHands
{
public:
	void deal(Card card);
	void clear();
	int score() const;

private:
	std::array<int, 12> suit_counter {};
};
