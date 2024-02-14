#include <iostream>
#include "src/BinaryNumber.h"

int main() {
    bitset<8> set(0b01010101);
    cout << set << endl;
    int number =  2147483647;
    BinaryNumber binaryForm(number);
    cout << "number = " << number << " = " << binaryForm << std::endl;

    return 0;
}
