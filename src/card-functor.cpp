#include "card-functor.h"
#include "card-define.h"

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

int Month::operator()(const Card& card) const
{
	if (card == Card::PineBright) return 1;
	if (card == Card::PineRibbon) return 1;
	if (card == Card::PinePlain1) return 1;
	if (card == Card::PinePlain2) return 1;
	if (card == Card::PlumKind) return 2;
	if (card == Card::PlumRibbon) return 2;
	if (card == Card::PlumPlain1) return 2;
	if (card == Card::PlumPlain2) return 2;
	if (card == Card::CherryBright) return 3;
	if (card == Card::CherryRibbon) return 3;
	if (card == Card::CherryPlain1) return 3;
	if (card == Card::CherryPlain2) return 3;
	if (card == Card::WisteriaKind) return 4;
	if (card == Card::WisteriaRibbon) return 4;
	if (card == Card::WisteriaPlain1) return 4;
	if (card == Card::WisteriaPlain2) return 4;
	if (card == Card::IrisKind) return 5;
	if (card == Card::IrisRibbon) return 5;
	if (card == Card::IrisPlain1) return 5;
	if (card == Card::IrisPlain2) return 5;
	if (card == Card::PeonyKind) return 6;
	if (card == Card::PeonyRibbon) return 6;
	if (card == Card::PeonyPlain1) return 6;
	if (card == Card::PeonyPlain2) return 6;
	if (card == Card::CloverKind) return 7;
	if (card == Card::CloverRibbon) return 7;
	if (card == Card::CloverPlain1) return 7;
	if (card == Card::CloverPlain2) return 7;
	if (card == Card::PampasBright) return 8;
	if (card == Card::PampasKind) return 8;
	if (card == Card::PampasPlain1) return 8;
	if (card == Card::PampasPlain2) return 8;
	if (card == Card::MumsKind) return 9;
	if (card == Card::MumsRibbon) return 9;
	if (card == Card::MumsPlain1) return 9;
	if (card == Card::MumsPlain2) return 9;
	if (card == Card::MapleKind) return 10;
	if (card == Card::MapleRibbon) return 10;
	if (card == Card::MaplePlain1) return 10;
	if (card == Card::MaplePlain2) return 10;
	if (card == Card::WillowBright) return 11;
	if (card == Card::WillowKind) return 11;
	if (card == Card::WillowRibbon) return 11;
	if (card == Card::WillowPlain) return 11;
	if (card == Card::PaulowniaBright) return 12;
	if (card == Card::PaulowniaPlain1) return 12;
	if (card == Card::PaulowniaPlain2) return 12;
	if (card == Card::PaulowniaPlain3) return 12;

	return 0;
}
