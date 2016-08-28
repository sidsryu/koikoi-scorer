#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"
#include "rule-define.h"
#include "month-define.h"

TEST_GROUP(OptionRulesTest)
{
	KoikoiScorer s;

	void setRainyViewing()
	{
		s.take(Card::CherryBright);
		s.take(Card::PampasBright);
		s.take(Card::MumsKind);

		s.addRule(Rule::ViewingTheFlower);
		s.addRule(Rule::ViewingTheMoon);
		s.addRule(Rule::RainBreakViewings);
	}
};

TEST(OptionRulesTest, ScoreDoubledWhenSevenOrMorePoints)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::PaulowniaBright);
	s.take(Card::WillowBright);

	s.addRule(Rule::SevenOrMoreDoubled);

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

	s.addRule(Rule::SakeCupBothKindAndPlain);

	CHECK_EQUAL(2, s.total());
}

TEST(OptionRulesTest, ViewingTheFlower)
{
	s.take(Card::CherryBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(0, s.total());

	s.addRule(Rule::ViewingTheFlower);

	CHECK_EQUAL(5, s.total());
}

TEST(OptionRulesTest, ViewingTheMoon)
{
	s.take(Card::PampasBright);
	s.take(Card::MumsKind);

	CHECK_EQUAL(0, s.total());

	s.addRule(Rule::ViewingTheMoon);

	CHECK_EQUAL(5, s.total());
}

TEST(OptionRulesTest, BrightViewingCombo)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PaulowniaBright);	
	s.take(Card::PampasBright);
	s.take(Card::WillowBright);

	s.take(Card::MumsKind);

	CHECK_EQUAL(10, s.total());

	s.addRule(Rule::ViewingTheFlower);
	
	CHECK_EQUAL(15, s.total());

	s.addRule(Rule::ViewingTheMoon);

	CHECK_EQUAL(20, s.total());
}

TEST(OptionRulesTest, ExtraPointAfterBoarDeerButterfly)
{
	s.take(Card::CloverKind);
	s.take(Card::MapleKind);
	s.take(Card::PeonyKind);

	s.take(Card::PlumKind);

	s.addRule(Rule::ExtraPointAfterBoarDeerButterfly);

	CHECK_EQUAL(6, s.total());
}

TEST(OptionRulesTest, ExtraPointAfterRedBlueRibbons)
{
	s.take(Card::PineRibbon);
	s.take(Card::PlumRibbon);
	s.take(Card::CherryRibbon);

	s.take(Card::MumsRibbon);
	s.take(Card::PeonyRibbon);

	s.addRule(Rule::ExtraPointAfterRedBlueRibbons);

	CHECK_EQUAL(7, s.total());

	s.take(Card::MapleRibbon);

	CHECK_EQUAL(10, s.total());

	s.take(Card::WillowRibbon);

	CHECK_EQUAL(11, s.total());
}

TEST(OptionRulesTest, RainyFourBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);
	s.take(Card::WillowBright);

	s.addRule(Rule::RainyFourBrights);

	CHECK_EQUAL(7, s.total());
}

TEST(OptionRulesTest, SixPointsThreeBrights)
{
	s.take(Card::PineBright);
	s.take(Card::CherryBright);
	s.take(Card::PampasBright);	

	s.addRule(Rule::SixPointsThreeBrights);

	CHECK_EQUAL(6, s.total());
}

TEST(OptionRulesTest, RainyViewingRainMan)
{
	setRainyViewing();
	s.take(Card::WillowBright);

	CHECK_EQUAL(0, s.total());
}

TEST(OptionRulesTest, RainyViewingLightning)
{
	setRainyViewing();
	s.take(Card::WillowPlain);

	CHECK_EQUAL(0, s.total());
}

TEST(OptionRulesTest, RainyViewingWillow)
{
	setRainyViewing();

	s.take(Card::WillowKind);
	s.take(Card::WillowRibbon);

	CHECK_EQUAL(10, s.total());

	s.addRule(Rule::WillowIsRain);

	CHECK_EQUAL(0, s.total());
}
