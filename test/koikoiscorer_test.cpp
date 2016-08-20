#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"

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

	CHECK_EQUAL(15, s.total());

	s.take(Card::WillowBright);

	CHECK_EQUAL(20, s.total());
}
