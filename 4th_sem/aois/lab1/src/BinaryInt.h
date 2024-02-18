#ifndef LAB1_BINARYINT_H
#define LAB1_BINARYINT_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class BinaryInt {
protected:
    bitset<32> bitSequence_;

    virtual bitset<32> convertNumber(int number) = 0;

public:
    void resetValue(int number);
    virtual string toString();
    virtual int toInt() = 0;
};

#endif
