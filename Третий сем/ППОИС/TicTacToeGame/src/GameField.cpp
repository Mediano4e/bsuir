#include "GameField.h"

GameField::GameField() {
    size_ = 1;
    freeCells_ = size_ * size_;
    field_ = new GameLine[size_];
}

GameField::GameField(size_t size) {
    size_ = size;
    freeCells_ = size_ * size_;
    field_ = new GameLine[size_];

    for (size_t i = 0; i < size_; i++) {
        field_[i].resize(size_);
    }
}

size_t GameField::size() const {
    return size_;
}

size_t GameField::getFreeCells() const {
    return freeCells_;
}

GameLine& GameField::operator[](size_t ind) {
    return field_[ind];
}
