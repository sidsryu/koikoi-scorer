#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"

TEST_GROUP(ScoringHandsTest)
{
	KoikoiScorer s;
};

TEST(ScoringHandsTest, FiveBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);
	s.take(Card::WillowBright);

	CHECK_EQUAL(10, s.total());
}

TEST(ScoringHandsTest, FourBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(8, s.total());
}

TEST(ScoringHandsTest, RainyFourBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);	
	s.take(Card::WillowBright);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, ThreeBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(Card::PineBright);
	s.take(Card::CherryBright);	
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(Card::PineBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, RainyThreeBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);	
	s.take(Card::WillowBright);

	CHECK_EQUAL(0, s.total());
}

TEST(ScoringHandsTest, ViewingTheFlower)
{
	s.take(Card::CherryBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, ViewingTheMoon)
{
	s.take(Card::PampasBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, BrightViewingCombo)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PaulowniaBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(10, s.total());
		
	s.take(Card::PampasBright);

	CHECK_EQUAL(18, s.total());

	s.take(Card::WillowBright);

	CHECK_EQUAL(20, s.total());
}

TEST(ScoringHandsTest, BoarDeerButterfly)
{
	s.take(Card::CloverKind);
	s.take(Card::MapleKind);
	s.take(Card::PeonyKind);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, RedRibbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::CherryRibbon);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, BlueRibbons)
{
	s.take(Card::MumsRibbon);
	s.take(Card::PeonyRibbon);
	s.take(Card::MapleRibbon);

	CHECK_EQUAL(5, s.total());
}

TEST(ScoringHandsTest, Kinds)
{
	s.take(Card::CloverKind);
	s.take(Card::MapleKind);
	s.take(Card::PampasKind);
	s.take(Card::IrisKind);

	CHECK_EQUAL(0, s.total());

	s.take(Card::MumsKind);

	CHECK_EQUAL(1, s.total());
}

TEST(ScoringHandsTest, AllKinds)
{
	s.take(Card::PlumKind);
	s.take(Card::WisteriaKind);
	s.take(Card::IrisKind);
	s.take(Card::PeonyKind);
	s.take(Card::CloverKind);
	s.take(Card::PampasKind);
	s.take(Card::MumsKind);
	s.take(Card::MapleKind);
	s.take(Card::WillowKind);

	CHECK_EQUAL(10, s.total());
}

TEST(ScoringHandsTest, Ribbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::MumsRibbon);
	s.take(Card::PeonyRibbon);

	CHECK_EQUAL(0, s.total());

	s.take(Card::CloverRibbon);

	CHECK_EQUAL(1, s.total());
}

TEST(ScoringHandsTest, AllRibbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::CherryRibbon);
	s.take(Card::WisteriaRibbon);
	s.take(Card::IrisRibbon);
	s.take(Card::PeonyRibbon);
	s.take(Card::CloverRibbon);
	s.take(Card::MumsRibbon);
	s.take(Card::MapleRibbon);
	s.take(Card::WillowRibbon);

	CHECK_EQUAL(16, s.total());
}
