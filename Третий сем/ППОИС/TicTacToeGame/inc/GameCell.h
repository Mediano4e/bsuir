#ifndef TICTACTOEGAME_GAMECELL_H
#define TICTACTOEGAME_GAMECELL_H

#include <iostream>
#include <gtest/gtest.h>


template<class A, class B>
/**
 * \brief Struct pair for return arguments
 * @tparam A for first arg
 * @tparam B for second arg
 * Used only for more comfortable way to get params
*/
struct pair{
    A first;
    B second;
};

/**
 *
 */
class GameCell {
protected:
    bool isEmpty_;
    bool isCross_;

public:
    GameCell();
    explicit GameCell(bool isCross);
    ~GameCell() = default;

    [[nodiscard]]
    bool isEmpty() const;
    [[nodiscard]]
    bool getSymbol() const;
    void setSymbol(bool isCross);

    bool operator==(GameCell gameCell) const;
    bool operator!=(GameCell gameCell) const;
    GameCell& operator=(const GameCell& gameCell);

    friend class GameCellTest;
    FRIEND_TEST(GameCellTest, BasicCellTesting);
};

#endif
