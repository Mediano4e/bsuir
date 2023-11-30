#include "GameCell.h"

/**
 *
 */
GameCell::GameCell() {
    isEmpty_ = true;
    isCross_ = false;
}

GameCell::GameCell(bool isCross) {
    isEmpty_ = false;
    isCross_ = isCross;
}

bool GameCell::isEmpty() const{
    return isEmpty_;
}

bool GameCell::getSymbol() const {
    if (isEmpty_) return false;
    return isCross_;
}

void GameCell::setSymbol(bool isCross) {
    isEmpty_ = false;
    isCross_ = isCross;
}

bool GameCell::operator==(GameCell gameCell) const {
    if (isEmpty_ != gameCell.isEmpty())
        return false;

    if (isCross_ != gameCell.getSymbol())
        return false;

    return true;
}

bool GameCell::operator!=(GameCell gameCell) const {
    if (isEmpty_ != gameCell.isEmpty())
        return true;

    if (isCross_ != gameCell.getSymbol())
        return true;

    return false;
}

GameCell& GameCell::operator=(const GameCell &gameCell) {
    if (&gameCell != this) {
        this->isEmpty_ = gameCell.isEmpty_;
        this->isCross_ = gameCell.isCross_;
    }

    return *this;
}
