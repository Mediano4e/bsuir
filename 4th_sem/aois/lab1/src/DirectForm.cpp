#include "DirectForm.h"

bitset<32> DirectForm::convertNumber(int number) {
    bitset<32> bitSequence;

    if (number == 0)
        return bitSequence;

    //Initializing sign bit
    if (number < 0) {
        bitSequence[0] = true;
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
            bitSequence[index] = true;
        }

        index++;
        binaryDivider /= 2;
    }

    return bitSequence;
}

bool DirectForm::unsignedEqual(const DirectForm &number) const {
    for (size_t i = 1; i < bitSequence_.size(); i++)
        if (bitSequence_[i] != number.bitSequence_[i])
            return false;
    return true;
}

bool DirectForm::leftUnsignedGreater(const DirectForm &number) const {
    for (size_t i = 1; i < bitSequence_.size(); i++) {
        if (bitSequence_[i] > number.bitSequence_[i])
            return true;
        if (bitSequence_[i] < number.bitSequence_[i])
            return false;
    }
    return false;
}

DirectForm DirectForm::unsignedSum(const DirectForm &number) const {
    DirectForm result;
    bool overPart = false;
    for (size_t i = bitSequence_.size() - 1; i > 0; i--) {
        if (bitSequence_[i] != number.bitSequence_[i]) {
            if (overPart)
                result.bitSequence_[i] = false;
            else
                result.bitSequence_[i] = true;
        }

        else if (bitSequence_[i] == 1) {
            if (overPart)
                result.bitSequence_[i] = true;
            else {
                result.bitSequence_[i] = false;
                overPart = true;
            }
        }

        else {
             if (overPart) {
                 result.bitSequence_[i] = true;
                 overPart = false;
             }
             else
                result.bitSequence_[i] = false;
        }
    }

    return result;
}

DirectForm DirectForm::unsignedDifFromGreater(const DirectForm &number) const {
    DirectForm result = *this;

    for (size_t i = bitSequence_.size() - 1; i > 0; i--) {
        if (result.bitSequence_[i] == number.bitSequence_[i])
            result.bitSequence_[i] = false;
        else if (result.bitSequence_[i] < number.bitSequence_[i]) {
            size_t j = i - 1;
            while (result.bitSequence_[j] != 1)
                j--;
            result.bitSequence_[j] = false;
            while (j != i) {
                j++;
                result.bitSequence_[j] = true;
            }
        }
    }

    return result;
}

bool DirectForm::isGreater(const DirectForm &number, bool leftPriority) const {
    if (bitSequence_[0] > number.bitSequence_[0])
        return !leftPriority;

    if (bitSequence_[0] < number.bitSequence_[0])
        return leftPriority;

    for (size_t i = 1; i < bitSequence_.size(); i++) {
        if (bitSequence_[i] > number.bitSequence_[i])
            return bitSequence_[0] != leftPriority;
        if (bitSequence_[i] < number.bitSequence_[i])
            return bitSequence_[0] == leftPriority;
    }

    return false;
}

DirectForm::DirectForm() {
    resetValue(0);
}

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

DirectForm DirectForm::Abs(const DirectForm& number) {
    DirectForm result = number;
    result.bitSequence_[0] = false;
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

DirectForm DirectForm::operator+(const DirectForm &number) const {
    DirectForm result;
    if (bitSequence_[0] == number.bitSequence_[0]) {
        result = unsignedSum(number);
        result.bitSequence_[0] = bitSequence_[0];
    }
    else if (leftUnsignedGreater(number)) {
        result = unsignedDifFromGreater(number);
        result.bitSequence_[0] = bitSequence_[0];
    }
    else {
        result = number.unsignedDifFromGreater(*this);
        result.bitSequence_[0] = number.bitSequence_[0];
    }
    return result;
}

DirectForm DirectForm::operator-(const DirectForm &number) const {
    DirectForm result;
    if (bitSequence_[0] != number.bitSequence_[0]) {
        result = unsignedSum(number);
        result.bitSequence_[0] = bitSequence_[0];
    }
    else if (leftUnsignedGreater(number)) {
        result = unsignedDifFromGreater(number);
        result.bitSequence_[0] = bitSequence_[0];
    }
    else if (*this == number) {
        return result;
    }
    else {
        result = number.unsignedDifFromGreater(*this);
        result.bitSequence_[0] = !bitSequence_[0];
    }

    return result;
}

DirectForm DirectForm::operator*(const DirectForm &number) const {
    DirectForm result;

    if (bitSequence_[0] != number.bitSequence_[0])
        result.bitSequence_[0] = true;

    for (size_t i = 1; i < bitSequence_.size(); i++) {
        DirectForm temp = *this;

        size_t j = 1;
        for (; j + i - 1 < bitSequence_.size(); j++)
            temp.bitSequence_[j] = temp.bitSequence_[j + i - 1];
        for (; j < bitSequence_.size(); j++)
            temp.bitSequence_[j] = false;

        if (number.bitSequence_[number.bitSequence_.size() - i])
            result = result + temp;
    }

    return result;
}

DirectForm DirectForm::unsignedDivision(const DirectForm &divisor) const {
    DirectForm result, dividend;
    bool firstIteration = true;
    size_t index = 1;

    while (index < bitSequence_.size()) {
        for (;divisor.leftUnsignedGreater(dividend) && index < bitSequence_.size(); index++) {
            dividend = dividend * 2;
            dividend.bitSequence_[31] = bitSequence_[index];

            if (result != 0 && !firstIteration)
                result = result * 2;

            firstIteration = false;
        }

        if (divisor.leftUnsignedGreater(dividend))
            continue;

        dividend = dividend - divisor;
        if (dividend != 0)
            firstIteration = true;

        result = result * 2;
        result.bitSequence_[31] = true;
    }

    for (size_t i = bitSequence_.size() - 1; i > index; result = result * 2, i--) {}

    return result;
}

DirectForm DirectForm::operator/(const DirectForm &number) const {
    DirectForm result;

    if (result == number)
        throw invalid_argument("Division by zero can't be solved");

    if (!leftUnsignedGreater(number))
        return result;

    bool sign(bitSequence_[0] != number.bitSequence_[0]);

    if (unsignedEqual(number)) {
        result.bitSequence_[31] = true;
        result.bitSequence_[0] = sign;
        return result;
    }

    result = unsignedDivision(Abs(number));
    result.bitSequence_[0] = sign;

    return result;
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