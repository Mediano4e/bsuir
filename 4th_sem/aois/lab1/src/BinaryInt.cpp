#include "BinaryInt.h"

string BinaryInt::toString() {
    string result;
    for (size_t i = 0; i < bitSequence_.size(); i++) {
        if (bitSequence_[i] == 1)
            result.push_back('1');
        else
            result.push_back('0');
    }
    return result;
}

void BinaryInt::resetValue(int number) {
    bitSequence_ = convertNumber(number);
}