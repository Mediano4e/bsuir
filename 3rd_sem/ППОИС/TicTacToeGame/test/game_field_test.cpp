#include "gtest/gtest.h"
#include "GameField.h"

class GameFieldTest : public testing::Test{};

TEST_F(GameFieldTest, BasicFieldTest){
    GameField n1;
    EXPECT_EQ(n1.size_, 1);
    EXPECT_EQ(n1.freeCells_, 1);
    EXPECT_NE(n1.field_, nullptr);

    GameField n2(3);
    EXPECT_EQ(n2.size_, 3);
    EXPECT_EQ(n2.freeCells_, 9);
    EXPECT_NE(n2.field_, nullptr);
}

TEST_F(GameFieldTest, OtherTest){
    GameField n1(3);
    EXPECT_EQ(n1.size(), 3);
    EXPECT_EQ(n1.getFreeCells(), 9);

    GameLine t1(3);
    t1[1].setSymbol(true);
    n1[1] = t1;
    EXPECT_TRUE(n1[1][1].getSymbol());
}