#include "ReverseForm.h"

bitset<32> ReverseForm::convertNumber(int number) {
    bitset<32> bitSequence;

    if (number == 0)
        return bitSequence;

    bool sign = false;
    if (number < 0) {
        sign = true;
        number *= -1;
    }

    for (size_t i = 0; i < bitSequence.size(); i++)
        bitSequence[i] = sign;

    size_t index = bitSequence.size() - 1;
    int binaryDivider = 1;

    while (number / 2 >= binaryDivider) {
        index--;
        binaryDivider *= 2;
    }

    while(binaryDivider >= 1) {
        if (number >= binaryDivider) {
            number -= binaryDivider;
            bitSequence[index] = !sign;
        }
        else
            bitSequence[index] = sign;

        index++;
        binaryDivider /= 2;
    }

    return bitSequence;
}

ReverseForm::ReverseForm() {
    resetValue(0);
}

ReverseForm::ReverseForm(int number) {
    resetValue(number);
}

int ReverseForm::toInt() {
    int divider = 1;
    int result = 0;
    bool sign = bitSequence_[0];

    if (bitSequence_[bitSequence_.size() - 1] == !sign)
        result++;

    for (size_t i = bitSequence_.size() - 2; i > 0; i--) {
        divider *= 2;
        if (bitSequence_[i] == !sign)
            result += divider;
    }

    if (sign)
        result *= -1;

    return result;
}

ReverseForm ReverseForm::Abs(const ReverseForm &number) {
    if (!number.bitSequence_[0])
        return number;

    ReverseForm result = number;
    for (size_t i = 1; i < number.bitSequence_.size(); i++)
        result.bitSequence_[i] = !result.bitSequence_[i];

    return result;
}

ostream& operator<<(ostream& os, ReverseForm& number) {
    os << number.toString() << '(' << number.toInt() << ')';
    return os;
}