#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"
#include "card-define.h"
#include "rule-define.h"
#include "month-define.h"
#include "score-report.h"

using namespace std;

TEST_GROUP(MontylyCardTest)
{
	KoikoiScorer s;

	void setup()
	{
		s.addRule(Rule::MonthlyCards);
	}

	void takeCards(Card c1, Card c2, Card c3, Card c4)
	{
		s.take(c1);
		s.take(c2);
		s.take(c3);
		s.take(c4);
	}

	int total()
	{
		return s.report().total;
	}
};

TEST(MontylyCardTest, MonthlyCards)
{
	s.take(Card::PineBright);
	s.take(Card::PineRibbon);
	s.take(Card::PinePlain1);

	s.setMonth(Month::January);
	
	CHECK_EQUAL(0, total());

	s.take(Card::PinePlain2);

	CHECK_EQUAL(4, total());

	s.setMonth(Month::February);

	CHECK_EQUAL(0, total());
}

TEST(MontylyCardTest, MonthlyCardsJanuary)
{
	takeCards(Card::PineBright, Card::PineRibbon, Card::PinePlain1, Card::PinePlain2);
	s.setMonth(Month::January);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsFebruary)
{
	takeCards(Card::PlumKind, Card::PlumRibbon, Card::PlumPlain1, Card::PlumPlain2);
	s.setMonth(Month::February);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsMarch)
{
	takeCards(Card::CherryBright, Card::CherryRibbon, Card::CherryPlain1, Card::CherryPlain2);
	s.setMonth(Month::March);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsApril)
{
	takeCards(Card::WisteriaKind, Card::WisteriaRibbon, Card::WisteriaPlain1, Card::WisteriaPlain2);
	s.setMonth(Month::April);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsMay)
{
	takeCards(Card::IrisKind, Card::IrisRibbon, Card::IrisPlain1, Card::IrisPlain2);
	s.setMonth(Month::May);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsJune)
{
	takeCards(Card::PeonyKind, Card::PeonyRibbon, Card::PeonyPlain1, Card::PeonyPlain2);
	s.setMonth(Month::June);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsJuly)
{
	takeCards(Card::CloverKind, Card::CloverRibbon, Card::CloverPlain1, Card::CloverPlain2);
	s.setMonth(Month::July);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsAugust)
{
	takeCards(Card::PampasBright, Card::PampasKind, Card::PampasPlain1, Card::PampasPlain2);
	s.setMonth(Month::August);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsSeptember)
{
	takeCards(Card::MumsKind, Card::MumsRibbon, Card::MumsPlain1, Card::MumsPlain2);
	s.setMonth(Month::September);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsOctober)
{
	takeCards(Card::MapleKind, Card::MapleRibbon, Card::MaplePlain1, Card::MaplePlain2);
	s.setMonth(Month::October);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsNovember)
{
	takeCards(Card::WillowBright, Card::WillowKind, Card::WillowRibbon, Card::WillowPlain);
	s.setMonth(Month::November);

	CHECK_EQUAL(4, total());
}

TEST(MontylyCardTest, MonthlyCardsDecember)
{
	takeCards(Card::PaulowniaBright, Card::PaulowniaPlain1, Card::PaulowniaPlain2, Card::PaulowniaPlain3);
	s.setMonth(Month::December);

	CHECK_EQUAL(4, total());
}
