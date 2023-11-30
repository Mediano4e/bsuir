#ifndef TICTACTOEGAME_TICTACTOE_H
#define TICTACTOEGAME_TICTACTOE_H

#include <iostream>
#include <string>
#include "GameField.h"

/**
 *
 */
class TicTacToe : private GameField{
    friend class TicTacToeTest;

    FRIEND_TEST(TicTacToeTest, BasicTicTacToeTest);
    FRIEND_TEST(TicTacToeTest, CheckoutsTest);
    FRIEND_TEST(TicTacToeTest, StringParsingTest);
    FRIEND_TEST(TicTacToeTest, CordTranslateTest);
    FRIEND_TEST(TicTacToeTest, IsInsideTest);
    FRIEND_TEST(TicTacToeTest, GetCellTest);
    FRIEND_TEST(TicTacToeTest, WinCheckTest);
    FRIEND_TEST(TicTacToeTest, PrintFieldTest);

protected:
    static std::string getInput();
    static bool checkInput(std::string input);
    static pair<char, size_t> stringParsing(std::string input);
    static pair<size_t, size_t> inputTranslate(pair<char, size_t> cords);
    static pair<size_t, size_t> inputProcessing();
    bool isInside(pair<size_t, size_t> cords);

    bool getCell(pair<size_t, size_t> cords, bool player);
    bool winCheck(pair<size_t, size_t> cords, bool player);
    bool gameMove(bool player);
    void print_field();

public:
    TicTacToe();
    explicit TicTacToe(size_t size);
    ~TicTacToe() = default;

    void game();
};

#endif
