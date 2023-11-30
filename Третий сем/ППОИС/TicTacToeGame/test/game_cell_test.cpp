#include <gtest/gtest.h>
#include "../inc/GameCell.h"

class GameCellTest : public testing::Test{};

TEST_F(GameCellTest, BasicCellTesting) {
    GameCell n1;
    EXPECT_TRUE(n1.isEmpty_);
    EXPECT_FALSE(n1.isCross_);

    GameCell n2(true);
    EXPECT_FALSE(n2.isEmpty_);
    EXPECT_TRUE(n2.isCross_);
}

TEST_F(GameCellTest, GetSetTesting){
    GameCell n1;
    GameCell n2(true);
    GameCell n3(false);

    EXPECT_TRUE(n1.isEmpty());
    EXPECT_FALSE(n2.isEmpty());
    EXPECT_FALSE(n3.isEmpty());

    EXPECT_FALSE(n1.getSymbol());
    EXPECT_TRUE(n2.getSymbol());
    EXPECT_FALSE(n3.getSymbol());

    n1.setSymbol(true);
    EXPECT_FALSE(n1.isEmpty());
    EXPECT_TRUE(n1.getSymbol());

    n1.setSymbol(false);
    EXPECT_FALSE(n1.isEmpty());
    EXPECT_FALSE(n1.getSymbol());
}

TEST_F(GameCellTest, OperatorTesting){
    GameCell n1;
    GameCell n2(true);

    EXPECT_FALSE(n1 == n2);
    EXPECT_TRUE(n1 != n2);

    n1.setSymbol(true);
    EXPECT_TRUE(n1 == n2);
    EXPECT_FALSE(n1 != n2);

    n1.setSymbol(false);
    EXPECT_FALSE(n1 == n2);
    EXPECT_TRUE(n1 != n2);

    n1 = n2;
    EXPECT_TRUE(n1 == n2);
    EXPECT_FALSE(n1 != n2);

    n1 = n1;
    EXPECT_EQ(n1.isEmpty(), false);
    EXPECT_EQ(n1.getSymbol(), true);
}

int main(int argc, char **argv) {
    ::testing::FLAGS_gtest_color = "yes";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
  const testing::TestInfo* const test_info =
      testing::UnitTest::GetInstance()->current_test_info();

  printf("We are in test %s of test suite %s.\n",
         test_info->name(),
         test_info->test_suite_name());
}
*/