#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"

TEST_GROUP(OptionRulesTest)
{
	KoikoiScorer s;
};

TEST(OptionRulesTest, ScoreDoubledWhenSevenOrMorePoints)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);
	s.take(Card::WillowBright);

	s.option();

	CHECK_EQUAL(20, s.total());
}

TEST(OptionRulesTest, SakeCupToCountKindAndPlain)
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

	s.take(Card::PlumKind);
	s.take(Card::WisteriaKind);
	s.take(Card::IrisKind);
	s.take(Card::PeonyKind);

	s.take(Card::MumsKind);

	CHECK_EQUAL(1, s.total());

	s.option();

	CHECK_EQUAL(2, s.total());
}

TEST(OptionRulesTest, ViewingTheFlower)
{
	s.take(Card::CherryBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(0, s.total());

	s.option();

	CHECK_EQUAL(5, s.total());
}

TEST(OptionRulesTest, ViewingTheMoon)
{
	s.take(Card::PampasBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(0, s.total());

	s.option();

	CHECK_EQUAL(5, s.total());
}

TEST(OptionRulesTest, BrightViewingCombo)
{
	s.option(false);

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
