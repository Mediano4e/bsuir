#ifndef LAB1_DIRECTFORM_H
#define LAB1_DIRECTFORM_H

#include "BinaryInt.h"

class DirectForm : public BinaryInt {
private:
    bitset<32> convertNumber(int number) override;
    [[nodiscard]]
    bool isGreater(const DirectForm& number, bool leftPriority) const;
    [[nodiscard]]
    bool unsignedEqual(const DirectForm& number) const;
    [[nodiscard]]
    bool leftUnsignedGreater(const DirectForm& number) const;
    [[nodiscard]]
    DirectForm unsignedSum(const DirectForm& number) const;
    [[nodiscard]]
    DirectForm unsignedDifFromGreater(const DirectForm& number) const;
    [[nodiscard]]
    DirectForm unsignedDivision(const DirectForm& number) const;
public:
    DirectForm();
    DirectForm(int number);
    ~DirectForm() = default;

    int toInt() override;
    static DirectForm Abs(const DirectForm& number);

    bool operator == (const DirectForm& number) const;
    bool operator != (const DirectForm& number) const;
    bool operator > (const DirectForm& number) const;
    bool operator < (const DirectForm& number) const;

    DirectForm operator + (const DirectForm& number) const;
    DirectForm operator - (const DirectForm& number) const;
    DirectForm operator * (const DirectForm& number) const;
    DirectForm operator / (const DirectForm& number) const;
};

istream& operator>>(istream& in, DirectForm& number);
ostream& operator<<(ostream& os, DirectForm& number);

#endif
