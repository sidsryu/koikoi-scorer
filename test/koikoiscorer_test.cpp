#include "CppUTest/TestHarness.h"
#include "koikoi-scorer.h"

TEST_GROUP(ScoringHandsTest)
{
	KoikoiScorer s;
};

TEST(ScoringHandsTest, FiveBrights)
{
	s.take(11);
	s.take(31);
	s.take(81);
	s.take(121);
	s.take(111);

	CHECK_EQUAL(10, s.total());
}

TEST(ScoringHandsTest, FourBrights)
{
	s.take(11);
	s.take(31);
	s.take(81);
	s.take(121);

	CHECK_EQUAL(8, s.total());
}

TEST(ScoringHandsTest, ThreeBrights)
{
	s.take(11);
	s.take(31);
	s.take(81);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(11);
	s.take(31);
	s.take(121);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(11);
	s.take(81);
	s.take(121);

	CHECK_EQUAL(5, s.total());

	s.clear();
	s.take(31);
	s.take(81);
	s.take(121);

	CHECK_EQUAL(5, s.total());
}
