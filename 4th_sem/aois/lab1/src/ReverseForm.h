#ifndef LAB1_REVERSEFORM_H
#define LAB1_REVERSEFORM_H

#include "BinaryInt.h"

class ReverseForm : public BinaryInt {
private:
    bitset<32> convertNumber(int number) override;
    [[nodiscard]]
    bool isGreater(const ReverseForm& number, bool leftPriority) const;
    [[nodiscard]]
    bool unsignedEqual(const ReverseForm& number) const;
    [[nodiscard]]
    bool leftUnsignedGreater(const ReverseForm& number) const;
    [[nodiscard]]
    ReverseForm unsignedSum(const ReverseForm& number) const;
    [[nodiscard]]
    ReverseForm unsignedDifFromGreater(const ReverseForm& number) const;
    [[nodiscard]]
    ReverseForm unsignedDivision(const ReverseForm& number) const;
public:
    ReverseForm();
    ReverseForm(int number);
    ~ReverseForm() = default;

    int toInt() override;
    static ReverseForm Abs(const ReverseForm& number);

    bool operator == (const ReverseForm& number) const;
    bool operator != (const ReverseForm& number) const;
    bool operator > (const ReverseForm& number) const;
    bool operator < (const ReverseForm& number) const;

    ReverseForm operator + (const ReverseForm& number) const;
    ReverseForm operator - (const ReverseForm& number) const;
    ReverseForm operator * (const ReverseForm& number) const;
    ReverseForm operator / (const ReverseForm& number) const;
};

istream& operator>>(istream& in, ReverseForm& number);
ostream& operator<<(ostream& os, ReverseForm& number);


#endif
