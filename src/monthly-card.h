#pragma once

namespace koikoi {
enum class Month;
class PointPile;

class MonthlyCard
{
public:
	MonthlyCard();

	void setMonth(Month month);
	bool hasMonth(const PointPile& pile) const;

private:
	bool hasJanuary(const PointPile& pile) const;
	bool hasFebruary(const PointPile& pile) const;
	bool hasMarch(const PointPile& pile) const;
	bool hasApril(const PointPile& pile) const;
	bool hasMay(const PointPile& pile) const;
	bool hasJune(const PointPile& pile) const;
	bool hasJuly(const PointPile& pile) const;
	bool hasAugust(const PointPile& pile) const;
	bool hasSeptember(const PointPile& pile) const;
	bool hasOctober(const PointPile& pile) const;
	bool hasNovember(const PointPile& pile) const;
	bool hasDecember(const PointPile& pile) const;

private:
	Month month;
};
}