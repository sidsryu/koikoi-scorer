#include "CppUTest/TestHarness.h"
#include "begining-hands.h"
#include "card-define.h"

TEST_GROUP(BeginingHandsTest)
{
	const int WINNING_POINTS { 6 };

	BeginingHands h;
};

TEST(BeginingHandsTest, NoFourHands)
{
	h.deal(Card::PineBright);
	h.deal(Card::PineRibbon);
	h.deal(Card::PinePlain1);
	h.deal(Card::PlumKind);
	h.deal(Card::CherryBright);
	h.deal(Card::CloverKind);
	h.deal(Card::IrisKind);
	h.deal(Card::PeonyKind);

	CHECK_EQUAL(0, h.score());
}

TEST(BeginingHandsTest, PineFourHands)
{
	h.deal(Card::PineBright);
	h.deal(Card::PineRibbon);
	h.deal(Card::PinePlain1);
	h.deal(Card::PinePlain2);

	CHECK_EQUAL(WINNING_POINTS, h.score());
}

TEST(BeginingHandsTest, PlumFourHands)
{
	h.deal(Card::PlumKind);
	h.deal(Card::PlumRibbon);
	h.deal(Card::PlumPlain1);
	h.deal(Card::PlumPlain2);

	CHECK_EQUAL(WINNING_POINTS, h.score());
}

TEST(BeginingHandsTest, PaulowniaFourHands)
{
	h.deal(Card::PaulowniaBright);
	h.deal(Card::PaulowniaPlain1);
	h.deal(Card::PaulowniaPlain2);
	h.deal(Card::PaulowniaPlain3);

	CHECK_EQUAL(WINNING_POINTS, h.score());
}

TEST(BeginingHandsTest, Sticky)
{
	h.deal(Card::PlumRibbon);
	h.deal(Card::PlumPlain1);
	h.deal(Card::WisteriaKind);
	h.deal(Card::WisteriaPlain2);
	h.deal(Card::PaulowniaPlain2);
	h.deal(Card::PaulowniaPlain3);
	h.deal(Card::PampasBright);
	h.deal(Card::PampasPlain1);

	CHECK_EQUAL(WINNING_POINTS, h.score());
}

TEST(BeginingHandsTest, NoSticky)
{
	h.deal(Card::PlumRibbon);
	h.deal(Card::PlumPlain1);
	h.deal(Card::WisteriaKind);
	h.deal(Card::WisteriaPlain2);
	h.deal(Card::PaulowniaPlain2);
	h.deal(Card::PaulowniaPlain3);
	h.deal(Card::PampasBright);
	h.deal(Card::WillowPlain);

	CHECK_EQUAL(0, h.score());
}

TEST(BeginingHandsTest, Clear)
{
	h.deal(Card::PineBright);
	h.deal(Card::PineRibbon);
	h.deal(Card::PinePlain1);
	h.deal(Card::PinePlain2);

	h.clear();

	CHECK_EQUAL(0, h.score());
}
