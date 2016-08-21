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

TEST(ScoringHandsTest, AllKindCombo)
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

TEST(ScoringHandsTest, AllRibbonCombo)
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

TEST(ScoringHandsTest, Plains)
{
	s.take(Card::PinePlain1);
	s.take(Card::PinePlain2);
	s.take(Card::PlumPlain1);
	s.take(Card::PlumPlain2);
	s.take(Card::CherryPlain1);
	s.take(Card::CherryPlain2);
	s.take(Card::WisteriaPlain1);
	s.take(Card::WisteriaPlain2);
	s.take(Card::IrisPlain1);

	CHECK_EQUAL(0, s.total());

	s.take(Card::IrisPlain2);

	CHECK_EQUAL(1, s.total());

	s.take(Card::PeonyPlain1);
	s.take(Card::PeonyPlain2);
	s.take(Card::CloverPlain1);
	s.take(Card::CloverPlain2);
	s.take(Card::PampasPlain1);
	s.take(Card::PampasPlain2);
	s.take(Card::MumsPlain1);
	s.take(Card::MumsPlain2);
	s.take(Card::MaplePlain1);
	s.take(Card::MaplePlain2);
	s.take(Card::WillowPlain);
	s.take(Card::PaulowniaPlain1);
	s.take(Card::PaulowniaPlain2);
	s.take(Card::PaulowniaPlain3);

	CHECK_EQUAL(15, s.total());
}

TEST(ScoringHandsTest, Clear)
{
	s.take(Card::PineBright);
	s.take(Card::PineRibbon);
	s.take(Card::PinePlain1);
	s.take(Card::PinePlain2);
	s.take(Card::PlumKind);
	s.take(Card::PlumRibbon);
	s.take(Card::PlumPlain1);
	s.take(Card::PlumPlain2);
	s.take(Card::CherryBright);
	s.take(Card::CherryRibbon);
	s.take(Card::CherryPlain1);
	s.take(Card::CherryPlain2);
	s.take(Card::WisteriaKind);
	s.take(Card::WisteriaRibbon);
	s.take(Card::WisteriaPlain1);
	s.take(Card::WisteriaPlain2);
	s.take(Card::IrisKind);
	s.take(Card::IrisRibbon);
	s.take(Card::IrisPlain1);
	s.take(Card::IrisPlain2);
	s.take(Card::PeonyKind);
	s.take(Card::PeonyRibbon);
	s.take(Card::PeonyPlain1);
	s.take(Card::PeonyPlain2);
	s.take(Card::CloverKind);
	s.take(Card::CloverRibbon);
	s.take(Card::CloverPlain1);
	s.take(Card::CloverPlain2);
	s.take(Card::PampasBright);
	s.take(Card::PampasKind);
	s.take(Card::PampasPlain1);
	s.take(Card::PampasPlain2);
	s.take(Card::MumsKind);
	s.take(Card::MumsRibbon);
	s.take(Card::MumsPlain1);
	s.take(Card::MumsPlain2);
	s.take(Card::MapleKind);
	s.take(Card::MapleRibbon);
	s.take(Card::MaplePlain1);
	s.take(Card::MaplePlain2);
	s.take(Card::WillowBright);
	s.take(Card::WillowKind);
	s.take(Card::WillowRibbon);
	s.take(Card::WillowPlain);
	s.take(Card::PaulowniaBright);
	s.take(Card::PaulowniaPlain1);
	s.take(Card::PaulowniaPlain2);
	s.take(Card::PaulowniaPlain3);

	s.clear();

	CHECK_EQUAL(0, s.total());
}

TEST(ScoringHandsTest, TakeDuplicatedCard)
{
	for (int i = 0; i < 2; i++)
	{
		s.take(Card::PinePlain1);
		s.take(Card::PinePlain2);
		s.take(Card::PlumPlain1);
		s.take(Card::PlumPlain2);
		s.take(Card::CherryPlain1);
		s.take(Card::CherryPlain2);
		s.take(Card::WisteriaPlain1);
		s.take(Card::WisteriaPlain2);
		s.take(Card::IrisPlain1);
	}

	CHECK_EQUAL(0, s.total());
}
