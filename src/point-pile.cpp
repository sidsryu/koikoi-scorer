#include "point-pile.h"
#include "card-define.h"
#include "card-functor.h"

void PointPile::take(Card card)
{
	cards.insert(card);

	if (IsBright()(card)) brights.insert(card);
	if (IsKind()(card)) kinds.insert(card);
	if (IsRibbon()(card)) ribbons.insert(card);
	if (IsPlain()(card)) plains.insert(card);
}

void PointPile::clear()
{
	cards.clear();
	brights.clear();
	kinds.clear();
	ribbons.clear();
	plains.clear();
}

int PointPile::brightCount() const
{
	return static_cast<int>(brights.size());
}

int PointPile::kindCount() const
{
	return static_cast<int>(kinds.size());
}

int PointPile::ribbonCount() const
{
	return static_cast<int>(ribbons.size());
}

int PointPile::plainCount() const
{
	return static_cast<int>(plains.size());
}

bool PointPile::hasCard(Card card) const
{
	auto it = cards.find(card);
	return it != cards.end();	
}

bool PointPile::hasBoarDeerButterfly() const
{
	return hasCard(Card::CloverKind)
		&& hasCard(Card::MapleKind) && hasCard(Card::PeonyKind);
}

bool PointPile::hasRedRibbons() const
{
	return hasCard(Card::PineRibbon)
		&& hasCard(Card::PlumRibbon) && hasCard(Card::CherryRibbon);
}

bool PointPile::hasBlueRibbons() const
{
	return hasCard(Card::MumsRibbon)
		&& hasCard(Card::PeonyRibbon) && hasCard(Card::MapleRibbon);
}

bool PointPile::hasViewingTheFlower() const
{
	return hasCard(Card::CherryBright) && hasCard(Card::MumsKind);
}

bool PointPile::hasViewingTheMoon() const
{
	return hasCard(Card::PampasBright) && hasCard(Card::MumsKind);
}
