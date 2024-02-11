#include "gtest/gtest.h"
#include "TicTacToe.h"

class TicTacToeTest : public testing::Test{};

TEST_F(TicTacToeTest, BasicTicTacToeTest){
    TicTacToe game1;
    EXPECT_EQ(game1.size(), 3);
    EXPECT_EQ(game1.getFreeCells(), 9);
    EXPECT_NE(game1.field_, nullptr);

    TicTacToe game2(2);
    EXPECT_EQ(game2.size(), 3);
    EXPECT_EQ(game2.getFreeCells(), 9);
    EXPECT_NE(game2.field_, nullptr);

    TicTacToe game3(32);
    EXPECT_EQ(game3.size(), 3);
    EXPECT_EQ(game3.getFreeCells(), 9);
    EXPECT_NE(game3.field_, nullptr);

    TicTacToe game4(5);
    EXPECT_EQ(game4.size(), 5);
    EXPECT_EQ(game4.getFreeCells(), 25);
    EXPECT_NE(game4.field_, nullptr);
}

TEST_F(TicTacToeTest, CheckoutsTest){
    EXPECT_FALSE(TicTacToe::checkInput("1"));
    EXPECT_FALSE(TicTacToe::checkInput(" 1      "));
    EXPECT_FALSE(TicTacToe::checkInput(",9"));
    EXPECT_FALSE(TicTacToe::checkInput("a9"));
    EXPECT_FALSE(TicTacToe::checkInput("A!"));
    EXPECT_FALSE(TicTacToe::checkInput("A   "));
    EXPECT_FALSE(TicTacToe::checkInput("A12f"));
    EXPECT_FALSE(TicTacToe::checkInput("A !1"));

    EXPECT_TRUE(TicTacToe::checkInput("A1"));
    EXPECT_TRUE(TicTacToe::checkInput("A123"));
    EXPECT_TRUE(TicTacToe::checkInput("A 1"));
}

TEST_F(TicTacToeTest, StringParsingTest) {
    pair<char, size_t> expected = {'C', 3};
    std::string input = "C3";
    pair<char, size_t> output = TicTacToe::stringParsing(input);

    EXPECT_EQ(expected.first, output.first);
    EXPECT_EQ(expected.second, output.second);

    pair<char, size_t> expected2 = {'C', 0};
    std::string input2 = "C0";
    pair<char, size_t> output2 = TicTacToe::stringParsing(input2);

    EXPECT_EQ(expected2.first, output2.first);
    EXPECT_EQ(expected2.second, output2.second);
}

TEST_F(TicTacToeTest, CordTranslateTest){
    pair<size_t, size_t> expected = {2, 2};
    pair<char, size_t> input = {'C', 3};
    pair<size_t, size_t> output = TicTacToe::inputTranslate(input);

    EXPECT_EQ(expected.first, output.first);
    EXPECT_EQ(expected.second, output.second);
}

TEST_F(TicTacToeTest, IsInsideTest) {
    TicTacToe test(5);

    pair<size_t, size_t> input1 = {0, 0};
    pair<size_t, size_t> input2 = {6, 0};
    pair<size_t, size_t> input3 = {0, 6};

    EXPECT_TRUE(test.isInside(input1));
    EXPECT_FALSE(test.isInside(input2));
    EXPECT_FALSE(test.isInside(input3));
}

TEST_F(TicTacToeTest, GetCellTest) {
    TicTacToe test(5);

    pair<size_t, size_t> cords = {0, 0};
    EXPECT_TRUE(test.getCell(cords, true));
    EXPECT_FALSE(test.getCell(cords, true));

    cords = {5, 0};
    EXPECT_FALSE(test.getCell(cords, true));

    cords = {0, 5};
    EXPECT_FALSE(test.getCell(cords, true));
}

TEST_F(TicTacToeTest, WinCheckTest){
    TicTacToe test(24);

    test.field_[1][1].setSymbol(true);
    test.field_[2][2].setSymbol(true);
    EXPECT_TRUE(test.winCheck({0,0}, true));
    EXPECT_FALSE(test.winCheck({0,0}, false));

    test.field_[23][23].setSymbol(true);
    test.field_[21][21].setSymbol(true);
    EXPECT_TRUE(test.winCheck({22,22}, true));
    EXPECT_FALSE(test.winCheck({22,22}, false));

    TicTacToe test2(7);
    test2.field_[0][0].setSymbol(true);
    test2.field_[1][0].setSymbol(false);
    test2.field_[0][1].setSymbol(false);
    test2.field_[1][2].setSymbol(true);
    test2.field_[2][1].setSymbol(true);
    test2.field_[2][0].setSymbol(true);
    test2.field_[0][2].setSymbol(false);
    test2.field_[2][2].setSymbol(false);
    test2.print_field();
    EXPECT_FALSE(test2.winCheck({1,1}, false));
    EXPECT_FALSE(test2.winCheck({1,1}, true));

}

TEST_F(TicTacToeTest, PrintFieldTest) {
    TicTacToe test(14);
    test.field_[0][0].setSymbol(true);
    test.field_[1][1].setSymbol(false);
    EXPECT_NO_FATAL_FAILURE(test.print_field());
}