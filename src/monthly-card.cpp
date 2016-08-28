#include "monthly-card.h"
#include "month-define.h"
#include "point-pile.h"
#include "card-define.h"

namespace koikoi {
MonthlyCard::MonthlyCard()
	: month(Month::January)
{}

void MonthlyCard::setMonth(Month month)
{
	this->month = month;
}

bool MonthlyCard::hasMonth(const PointPile& pile) const
{
	switch (month)
	{
	case Month::January: return hasJanuary(pile);
	case Month::February: return hasFebruary(pile);
	case Month::March: return hasMarch(pile);
	case Month::April: return hasApril(pile);
	case Month::May: return hasMay(pile);
	case Month::June: return hasJune(pile);
	case Month::July: return hasJuly(pile);
	case Month::August: return hasAugust(pile);
	case Month::September: return hasSeptember(pile);
	case Month::October: return hasOctober(pile);
	case Month::November: return hasNovember(pile);
	case Month::December: return hasDecember(pile);
	}

	return false;
}

bool MonthlyCard::hasJanuary(const PointPile& pile) const
{
	return pile.hasCard(Card::PineBright)
		&& pile.hasCard(Card::PineRibbon)
		&& pile.hasCard(Card::PinePlain1)
		&& pile.hasCard(Card::PinePlain2);
}

bool MonthlyCard::hasFebruary(const PointPile& pile) const
{
	return pile.hasCard(Card::PlumKind)
		&& pile.hasCard(Card::PlumRibbon)
		&& pile.hasCard(Card::PlumPlain1)
		&& pile.hasCard(Card::PlumPlain2);
}

bool MonthlyCard::hasMarch(const PointPile& pile) const
{
	return pile.hasCard(Card::CherryBright)
		&& pile.hasCard(Card::CherryRibbon)
		&& pile.hasCard(Card::CherryPlain1)
		&& pile.hasCard(Card::CherryPlain2);
}

bool MonthlyCard::hasApril(const PointPile& pile) const
{
	return pile.hasCard(Card::WisteriaKind)
		&& pile.hasCard(Card::WisteriaRibbon)
		&& pile.hasCard(Card::WisteriaPlain1)
		&& pile.hasCard(Card::WisteriaPlain2);
}

bool MonthlyCard::hasMay(const PointPile& pile) const
{
	return pile.hasCard(Card::IrisKind)
		&& pile.hasCard(Card::IrisRibbon)
		&& pile.hasCard(Card::IrisPlain1)
		&& pile.hasCard(Card::IrisPlain2);
}

bool MonthlyCard::hasJune(const PointPile& pile) const
{
	return pile.hasCard(Card::PeonyKind)
		&& pile.hasCard(Card::PeonyRibbon)
		&& pile.hasCard(Card::PeonyPlain1)
		&& pile.hasCard(Card::PeonyPlain2);
}

bool MonthlyCard::hasJuly(const PointPile& pile) const
{
	return pile.hasCard(Card::CloverKind)
		&& pile.hasCard(Card::CloverRibbon)
		&& pile.hasCard(Card::CloverPlain1)
		&& pile.hasCard(Card::CloverPlain2);
}

bool MonthlyCard::hasAugust(const PointPile& pile) const
{
	return pile.hasCard(Card::PampasBright)
		&& pile.hasCard(Card::PampasKind)
		&& pile.hasCard(Card::PampasPlain1)
		&& pile.hasCard(Card::PampasPlain2);
}
bool MonthlyCard::hasSeptember(const PointPile& pile) const
{
	return pile.hasCard(Card::MumsKind)
		&& pile.hasCard(Card::MumsRibbon)
		&& pile.hasCard(Card::MumsPlain1)
		&& pile.hasCard(Card::MumsPlain2);
}

bool MonthlyCard::hasOctober(const PointPile& pile) const
{
	return pile.hasCard(Card::MapleKind)
		&& pile.hasCard(Card::MapleRibbon)
		&& pile.hasCard(Card::MaplePlain1)
		&& pile.hasCard(Card::MaplePlain2);
}

bool MonthlyCard::hasNovember(const PointPile& pile) const
{
	return pile.hasCard(Card::WillowBright)
		&& pile.hasCard(Card::WillowKind)
		&& pile.hasCard(Card::WillowRibbon)
		&& pile.hasCard(Card::WillowPlain);
}

bool MonthlyCard::hasDecember(const PointPile& pile) const
{
	return pile.hasCard(Card::PaulowniaBright)
		&& pile.hasCard(Card::PaulowniaPlain1)
		&& pile.hasCard(Card::PaulowniaPlain2)
		&& pile.hasCard(Card::PaulowniaPlain3);
}
}
