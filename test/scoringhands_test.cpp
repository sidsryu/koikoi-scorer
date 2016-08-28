#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"
#include "score-report.h"

using namespace koikoi;

TEST_GROUP(ScoringHandsTest)
{
	KoikoiScorer s;

	int total()
	{
		return s.report().total;
	}
};

TEST(ScoringHandsTest, FiveBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);
	s.take(Card::WillowBright);

	CHECK_EQUAL(10, total());
}

TEST(ScoringHandsTest, FourBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(8, total());
}

TEST(ScoringHandsTest, RainyFourBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);	
	s.take(Card::WillowBright);

	CHECK_EQUAL(5, total());
}

TEST(ScoringHandsTest, ThreeBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);

	CHECK_EQUAL(5, total());

	s.clear();
	s.take(Card::PineBright);
	s.take(Card::CherryBright);	
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, total());

	s.clear();
	s.take(Card::PineBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, total());

	s.clear();
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);

	CHECK_EQUAL(5, total());
}

TEST(ScoringHandsTest, RainyThreeBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);	
	s.take(Card::WillowBright);

	CHECK_EQUAL(0, total());
}

TEST(ScoringHandsTest, BoarDeerButterfly)
{
	s.take(Card::CloverKind);
	s.take(Card::MapleKind);
	s.take(Card::PeonyKind);

	CHECK_EQUAL(5, total());
}

TEST(ScoringHandsTest, RedRibbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::CherryRibbon);

	CHECK_EQUAL(5, total());
}

TEST(ScoringHandsTest, BlueRibbons)
{
	s.take(Card::MumsRibbon);
	s.take(Card::PeonyRibbon);
	s.take(Card::MapleRibbon);

	CHECK_EQUAL(5, total());
}

TEST(ScoringHandsTest, Kinds)
{
	s.take(Card::CloverKind);
	s.take(Card::MapleKind);
	s.take(Card::PampasKind);
	s.take(Card::IrisKind);

	CHECK_EQUAL(0, total());

	s.take(Card::MumsKind);

	CHECK_EQUAL(1, total());
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

	CHECK_EQUAL(10, total());
}

TEST(ScoringHandsTest, Ribbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::MumsRibbon);
	s.take(Card::PeonyRibbon);

	CHECK_EQUAL(0, total());

	s.take(Card::CloverRibbon);

	CHECK_EQUAL(1, total());
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

	CHECK_EQUAL(16, total());
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

	CHECK_EQUAL(0, total());

	s.take(Card::IrisPlain2);

	CHECK_EQUAL(1, total());

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

	CHECK_EQUAL(15, total());
}
