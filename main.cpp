#include <gtest/gtest.h>
#include "candle.h"


TEST(CandleTest, BodyContainsGreen) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_TRUE(candle.body_contains(1.2));
  EXPECT_FALSE(candle.body_contains(1.6));
}

TEST(CandleTest, BodyContainsRed) {
  Candle candle(1.5, 2.0, 0.5, 1.0);
  EXPECT_TRUE(candle.body_contains(1.2));
  EXPECT_FALSE(candle.body_contains(1.6));
}

TEST(CandleTest, BodyContainsEqual) {
  Candle candle(1.0, 2.0, 0.5, 1.0);
  EXPECT_TRUE(candle.body_contains(1.0));
  EXPECT_FALSE(candle.body_contains(1.1));
}

TEST(CandleTest, ContainsWithinRange) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_TRUE(candle.contains(1.2));
  EXPECT_FALSE(candle.contains(2.1));
}

TEST(CandleTest, ContainsBoundary) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_TRUE(candle.contains(2.0));
  EXPECT_FALSE(candle.contains(0.4));
}

TEST(CandleTest, ContainsOutsideRange) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_FALSE(candle.contains(2.5));
  EXPECT_FALSE(candle.contains(-0.5));
}

TEST(CandleTest, FullSizePositive) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_DOUBLE_EQ(candle.full_size(), 1.5);
}

TEST(CandleTest, FullSizeZero) {
  Candle candle(1.0, 1.0, 1.0, 1.0);
  EXPECT_DOUBLE_EQ(candle.full_size(), 0.0);
}

TEST(CandleTest, FullSizeNegative) {
  Candle candle(1.0, 0.5, 2.0, 1.5);
  EXPECT_DOUBLE_EQ(candle.full_size(), 1.5);
}

TEST(CandleTest, BodySizePositive) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_DOUBLE_EQ(candle.body_size(), 0.5);
}

TEST(CandleTest, BodySizeZero) {
  Candle candle(1.0, 2.0, 0.5, 1.0);
  EXPECT_DOUBLE_EQ(candle.body_size(), 0.0);
}

TEST(CandleTest, BodySizeNegative) {
  Candle candle(1.5, 2.0, 0.5, 1.0);
  EXPECT_DOUBLE_EQ(candle.body_size(), 0.5);
}

TEST(CandleTest, IsRedTrue) {
  Candle candle(1.5, 2.0, 0.5, 1.0);
  EXPECT_TRUE(candle.is_red());
}

TEST(CandleTest, IsRedFalse) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsRedEqual) {
  Candle candle(1.0, 2.0, 0.5, 1.0);
  EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsGreenTrue) {
  Candle candle(1.0, 2.0, 0.5, 1.5);
  EXPECT_TRUE(candle.is_green());
}

TEST(CandleTest, IsGreenFalse) {
  Candle candle(1.5, 2.0, 0.5, 1.0);
  EXPECT_FALSE(candle.is_green());
}

TEST(CandleTest, IsGreenEqual) {
  Candle candle(1.0, 2.0, 0.5, 1.0);
  EXPECT_FALSE(candle.is_green());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
