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

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
