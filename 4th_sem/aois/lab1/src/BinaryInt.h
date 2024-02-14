#ifndef LAB1_BINARYINT_H
#define LAB1_BINARYINT_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class BinaryInt {
private:
    bitset<32> bitSequence_;
public:
    virtual int getIntBack() = 0;

    virtual ostream& operator<<(ostream& os) = 0;
};

class A : public BinaryInt{
private:

public:

};

#endif
