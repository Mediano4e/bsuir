#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/GameLine.h"

class GameLineTest : public testing::Test{};

TEST_F(GameLineTest, BasicLineTesting) {
    GameLine n1;
    EXPECT_EQ(n1.size(), 1);
    EXPECT_EQ(n1[0].isEmpty(), true);
    EXPECT_EQ(n1[0].getSymbol(), false);

    GameLine n2(3);
    EXPECT_EQ(n2.size(), 3);
    EXPECT_EQ(n2[2].isEmpty(), true);
    EXPECT_EQ(n2[1].getSymbol(), false);
}

TEST_F(GameLineTest, ResizeTest) {
    GameLine n1;
    EXPECT_EQ(n1.size(), 1);
    n1[0].setSymbol(true);
    EXPECT_TRUE(n1[0].getSymbol());

    n1.resize(5);
    EXPECT_EQ(n1.size(), 5);
    EXPECT_TRUE(n1[0].getSymbol());
    EXPECT_FALSE(n1[2].getSymbol());

    n1[2].setSymbol(true);
    n1.resize(3);
    EXPECT_EQ(n1.size(), 3);
    EXPECT_TRUE(n1[0].getSymbol());
    EXPECT_TRUE(n1[2].getSymbol());
    EXPECT_FALSE(n1[3].getSymbol());
}