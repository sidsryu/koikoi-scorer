#pragma once

enum class Card;
enum class Month;

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

struct ToMonth
{
	Month operator()(const Card& card) const;
};
