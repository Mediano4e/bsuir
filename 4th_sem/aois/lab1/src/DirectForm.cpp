#include "DirectForm.h"

bitset<32> DirectForm::convertNumber(int number) {
    bitset<32> bitSequence;

    if (number == 0)
        return bitSequence;

    //Initializing sign bit
    if (number < 0) {
        bitSequence[0] = 1;
        number *= -1;
    }

    size_t index = bitSequence.size() - 1;
    int binaryDivider = 1;

    //As we always convert int, so there can't be too large numbers, and we don't need negative index checkout
    //This loop searches for max condition od binary divider and index of this divider in bit sequence
    while (number / 2 >= binaryDivider) {
        index--;
        binaryDivider *= 2;
    }

    while(binaryDivider >= 1) {
        if (number >= binaryDivider) {
            number -= binaryDivider;
            bitSequence[index] = 1;
        }

        index++;
        binaryDivider /= 2;
    }

    return bitSequence;
}

bool DirectForm::isGreater(const DirectForm &number, bool leftPriority) const {
    //if first number negative, second positive; comparison of sign bits
    if (bitSequence_[0] > number.bitSequence_[0])
        return !leftPriority;
    //if first number positive, second negative; comparison of sign bits
    if (bitSequence_[0] < number.bitSequence_[0])
        return leftPriority;

    for (size_t i = 1; i < bitSequence_.size(); i++) {
        if (bitSequence_[i] > number.bitSequence_[i])
            return bitSequence_[0] != leftPriority;
        if (bitSequence_[i] < number.bitSequence_[i])
            return bitSequence_[0] == leftPriority;
    }

    //if numbers are the same
    return false;
}

DirectForm::DirectForm() {
    resetValue(0);
};

DirectForm::DirectForm(int number) {
    resetValue(number);
}

int DirectForm::toInt() {
    int divider = 1;
    int result = 0;

    if (bitSequence_[bitSequence_.size() - 1] == 1)
        result++;

    for (size_t i = bitSequence_.size() - 2; i > 0; i--) {
        divider *= 2;
        if (bitSequence_[i] == 1)
            result += divider;
    }

    if (bitSequence_[0] == 1)
        result *= -1;

    return result;
}

bool DirectForm::operator==(const DirectForm &number) const {
    return bitSequence_ == number.bitSequence_;
}

bool DirectForm::operator!=(const DirectForm &number) const {
    return bitSequence_ != number.bitSequence_;
}

bool DirectForm::operator>(const DirectForm &number) const {
    return isGreater(number, true);
}

bool DirectForm::operator<(const DirectForm &number) const {
    return isGreater(number, false);
}

istream& operator>>(istream& in, DirectForm& number) {
    int num;
    in >> num;
    number.resetValue(num);
    return in;
}

ostream& operator<<(ostream& os, DirectForm& number) {
    os << number.toString() << '(' << number.toInt() << ')';
    return os;
}