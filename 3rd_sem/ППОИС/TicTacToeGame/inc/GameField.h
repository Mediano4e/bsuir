#ifndef TICTACTOEGAME_GAMEFIELD_H
#define TICTACTOEGAME_GAMEFIELD_H

#include "GameLine.h"

class GameField{
    friend class GameFieldTest;
    FRIEND_TEST(GameFieldTest, BasicFieldTest);
protected:
    GameLine* field_;
    size_t size_;
    size_t freeCells_;

public:
    GameField();
    explicit GameField(size_t size);
    ~GameField() = default;

    [[nodiscard]]
    size_t size() const;
    [[nodiscard]]
    size_t getFreeCells() const;

    GameLine& operator[](size_t ind);
};


#endif
