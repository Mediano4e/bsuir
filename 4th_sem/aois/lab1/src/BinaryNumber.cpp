#include <iostream>
#include "BinaryNumber.h"

BinaryNumber::BinaryNumber() {
    number_.push_back('0');
}

BinaryNumber::BinaryNumber(int number) {
    if (number == 0) {
        number_.push_back('0');
        return;
    }

    int maxDivider = 1;
    while (number / 2 > maxDivider) {
        maxDivider *= 2;
    }

    while(maxDivider >= 1) {
        if (number >= maxDivider) {
            number -= maxDivider;
            number_ = number_ + '1';
        }
        else
            number_ = number_ + '0';

        maxDivider /= 2;
    }
}

string BinaryNumber::getBinaryNumber() {
    return number_;
}

ostream& operator<<(ostream& os, BinaryNumber& number) {
    cout << number.getBinaryNumber().size() << endl;
    os << number.getBinaryNumber();
    return os;
}
