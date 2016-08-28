#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"
#include "score-report.h"

using namespace koikoi;

TEST_GROUP(KoikoiScorerTest)
{
	KoikoiScorer s;

	int total()
	{
		return s.report().total;
	}
};

TEST(KoikoiScorerTest, Clear)
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

	CHECK_EQUAL(0, total());
}

TEST(KoikoiScorerTest, TakeDuplicatedCard)
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

	CHECK_EQUAL(0, total());
}
