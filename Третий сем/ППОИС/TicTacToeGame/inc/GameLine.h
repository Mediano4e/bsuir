#ifndef TICTACTOEGAME_GAMELINE_H
#define TICTACTOEGAME_GAMELINE_H

#include "GameCell.h"

class GameLine{
    friend class GameLineTest;
    FRIEND_TEST(GameLineTest, NullPointerTest);
protected:
    GameCell* line_;
    size_t size_;

public:
    GameLine();
    explicit GameLine(size_t size);
    ~GameLine();

    [[nodiscard]]
    size_t size() const;
    void resize(size_t size);

    GameCell& operator[](size_t ind);
};

#endif
