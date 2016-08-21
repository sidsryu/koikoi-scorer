#pragma once

enum class Card
{
	PineBright = 11,
	PineRibbon = 12,
	PinePlain1 = 13,
	PinePlain2 = 14,
	PlumKind = 21,
	PlumRibbon = 22,
	PlumPlain1 = 23,
	PlumPlain2 = 24,
	CherryBright = 31,
	CherryRibbon = 32,
	CherryPlain1 = 33,
	CherryPlain2 = 34,
	WisteriaKind = 41,
	WisteriaRibbon = 42,
	WisteriaPlain1 = 43,
	WisteriaPlain2 = 44,
	IrisKind = 51,
	IrisRibbon = 52,
	IrisPlain1 = 53,
	IrisPlain2 = 54,
	PeonyKind = 61,
	PeonyRibbon = 62,
	PeonyPlain1 = 63,
	PeonyPlain2 = 64,
	CloverKind = 71,
	CloverRibbon = 72,
	CloverPlain1 = 73,
	CloverPlain2 = 74,
	PampasBright = 81,
	PampasKind = 82,
	PampasPlain1 = 83,
	PampasPlain2 = 84,
	MumsKind = 91,
	MumsRibbon = 92,
	MumsPlain1 = 93,
	MumsPlain2 = 94,
	MapleKind = 101,
	MapleRibbon = 102,
	MaplePlain1 = 103,
	MaplePlain2 = 104,
	WillowBright = 111,
	WillowKind = 112,
	WillowRibbon = 113,
	WillowPlain = 114,
	PaulowniaBright = 121,
	PaulowniaPlain1 = 122,
	PaulowniaPlain2 = 123,
	PaulowniaPlain3 = 134,
};

// NOTE: Custome hash for enum class.
// NOTE: It is code that for C++14 not full supported compilers.
#include <functional>

namespace std {
template <> struct hash<Card>
{
	size_t operator()(const Card& card) const
	{
		using type = underlying_type_t<Card>;

		auto value = static_cast<type>(card);
		return hash<type>()(value);
	}
};
}
