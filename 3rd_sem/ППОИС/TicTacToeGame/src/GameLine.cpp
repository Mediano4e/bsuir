#include "GameLine.h"

GameLine::GameLine() {
    size_ = 1;
    line_ = new GameCell[size_];
}

GameLine::GameLine(size_t size) {
    size_ = size;
    line_ = new GameCell[size_];
}

GameLine::~GameLine() {
    delete[] line_;
}

size_t GameLine::size() const {
    return size_;
}

void GameLine::resize(size_t size) {
    auto newLine = new GameCell[size];

    for (size_t i = 0; i < size_ && i < size; i++) {
        newLine[i] = line_[i];
    }

    delete[] line_;

    size_ = size;
    line_ = newLine;
}

GameCell& GameLine::operator[](size_t ind){
    return line_[ind];
}
