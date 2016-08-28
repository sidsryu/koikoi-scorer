#include "card-functor.h"
#include "card-define.h"
#include "month-define.h"

namespace koikoi {
bool IsBright::operator()(const Card& card) const
{
	if (card == Card::PineBright) return true;
	if (card == Card::CherryBright) return true;
	if (card == Card::PampasBright) return true;
	if (card == Card::WillowBright) return true;
	if (card == Card::PaulowniaBright) return true;

	return false;
}

bool IsKind::operator()(const Card& card) const
{
	if (card == Card::PlumKind) return true;
	if (card == Card::WisteriaKind) return true;
	if (card == Card::IrisKind) return true;
	if (card == Card::PeonyKind) return true;
	if (card == Card::CloverKind) return true;
	if (card == Card::PampasKind) return true;
	if (card == Card::MumsKind) return true;
	if (card == Card::MapleKind) return true;
	if (card == Card::WillowKind) return true;

	return false;
}

bool IsRibbon::operator()(const Card& card) const
{
	if (card == Card::PineRibbon) return true;
	if (card == Card::PlumRibbon) return true;
	if (card == Card::CherryRibbon) return true;
	if (card == Card::WisteriaRibbon) return true;
	if (card == Card::IrisRibbon) return true;
	if (card == Card::PeonyRibbon) return true;
	if (card == Card::CloverRibbon) return true;
	if (card == Card::MumsRibbon) return true;
	if (card == Card::MapleRibbon) return true;
	if (card == Card::WillowRibbon) return true;

	return false;
}

bool IsPlain::operator()(const Card& card) const
{
	if (card == Card::PinePlain1) return true;
	if (card == Card::PinePlain2) return true;
	if (card == Card::PlumPlain1) return true;
	if (card == Card::PlumPlain2) return true;
	if (card == Card::CherryPlain1) return true;
	if (card == Card::CherryPlain2) return true;
	if (card == Card::WisteriaPlain1) return true;
	if (card == Card::WisteriaPlain2) return true;
	if (card == Card::IrisPlain1) return true;
	if (card == Card::IrisPlain2) return true;
	if (card == Card::PeonyPlain1) return true;
	if (card == Card::PeonyPlain2) return true;
	if (card == Card::CloverPlain1) return true;
	if (card == Card::CloverPlain2) return true;
	if (card == Card::PampasPlain1) return true;
	if (card == Card::PampasPlain2) return true;
	if (card == Card::MumsPlain1) return true;
	if (card == Card::MumsPlain2) return true;
	if (card == Card::MaplePlain1) return true;
	if (card == Card::MaplePlain2) return true;
	if (card == Card::WillowPlain) return true;
	if (card == Card::PaulowniaPlain1) return true;
	if (card == Card::PaulowniaPlain2) return true;
	if (card == Card::PaulowniaPlain3) return true;

	return false;
}

Month ToMonth::operator()(const Card& card) const
{
	if (card == Card::PineBright) return Month::January;
	if (card == Card::PineRibbon) return Month::January;
	if (card == Card::PinePlain1) return Month::January;
	if (card == Card::PinePlain2) return Month::January;
	if (card == Card::PlumKind) return Month::February;
	if (card == Card::PlumRibbon) return Month::February;
	if (card == Card::PlumPlain1) return Month::February;
	if (card == Card::PlumPlain2) return Month::February;
	if (card == Card::CherryBright) return Month::March;
	if (card == Card::CherryRibbon) return Month::March;
	if (card == Card::CherryPlain1) return Month::March;
	if (card == Card::CherryPlain2) return Month::March;
	if (card == Card::WisteriaKind) return Month::April;
	if (card == Card::WisteriaRibbon) return Month::April;
	if (card == Card::WisteriaPlain1) return Month::April;
	if (card == Card::WisteriaPlain2) return Month::April;
	if (card == Card::IrisKind) return Month::May;
	if (card == Card::IrisRibbon) return Month::May;
	if (card == Card::IrisPlain1) return Month::May;
	if (card == Card::IrisPlain2) return Month::May;
	if (card == Card::PeonyKind) return Month::June;
	if (card == Card::PeonyRibbon) return Month::June;
	if (card == Card::PeonyPlain1) return Month::June;
	if (card == Card::PeonyPlain2) return Month::June;
	if (card == Card::CloverKind) return Month::July;
	if (card == Card::CloverRibbon) return Month::July;
	if (card == Card::CloverPlain1) return Month::July;
	if (card == Card::CloverPlain2) return Month::July;
	if (card == Card::PampasBright) return Month::August;
	if (card == Card::PampasKind) return Month::August;
	if (card == Card::PampasPlain1) return Month::August;
	if (card == Card::PampasPlain2) return Month::August;
	if (card == Card::MumsKind) return Month::September;
	if (card == Card::MumsRibbon) return Month::September;
	if (card == Card::MumsPlain1) return Month::September;
	if (card == Card::MumsPlain2) return Month::September;
	if (card == Card::MapleKind) return Month::October;
	if (card == Card::MapleRibbon) return Month::October;
	if (card == Card::MaplePlain1) return Month::October;
	if (card == Card::MaplePlain2) return Month::October;
	if (card == Card::WillowBright) return Month::November;
	if (card == Card::WillowKind) return Month::November;
	if (card == Card::WillowRibbon) return Month::November;
	if (card == Card::WillowPlain) return Month::November;
	if (card == Card::PaulowniaBright) return Month::December;
	if (card == Card::PaulowniaPlain1) return Month::December;
	if (card == Card::PaulowniaPlain2) return Month::December;
	if (card == Card::PaulowniaPlain3) return Month::December;

	return Month::January;
}
}
