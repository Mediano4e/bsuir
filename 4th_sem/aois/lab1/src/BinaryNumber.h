#ifndef LAB1_BINARYNUMBER_H
#define LAB1_BINARYNUMBER_H

#include <string>
#include <bitset>

using namespace std;

class BinaryNumber {
private:
    string number_;
public:
    BinaryNumber();
    explicit BinaryNumber(int number);
    ~BinaryNumber() = default;

    string getBinaryNumber();
};

ostream& operator<<(ostream& os, BinaryNumber& number);

#endif
