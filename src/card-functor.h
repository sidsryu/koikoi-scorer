#pragma once

enum class Card;

struct IsBright
{
	bool operator()(const Card& card) const;
};

struct IsKind
{
	bool operator()(const Card& card) const;
};

struct IsRibbon
{
	bool operator()(const Card& card) const;
};

struct IsPlain
{
	bool operator()(const Card& card) const;
};

struct Month
{
	int operator()(const Card& card) const;
};
