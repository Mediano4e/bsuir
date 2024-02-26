#ifndef LAB1_ADDITIONALFORM_H
#define LAB1_ADDITIONALFORM_H

#include "BinaryInt.h"

class AdditionalForm : public BinaryInt {
private:
    bitset<32> convertNumber(int number) override;
    [[nodiscard]]
    bool isGreater(const AdditionalForm& number, bool leftPriority) const;
    [[nodiscard]]
    bool unsignedEqual(const AdditionalForm& number) const;
    [[nodiscard]]
    bool leftUnsignedGreater(const AdditionalForm& number) const;
    [[nodiscard]]
    AdditionalForm unsignedSum(const AdditionalForm& number) const;
    [[nodiscard]]
    AdditionalForm unsignedDifFromGreater(const AdditionalForm& number) const;
    [[nodiscard]]
    AdditionalForm unsignedDivision(const AdditionalForm& number) const;
public:
    AdditionalForm();
    AdditionalForm(int number);
    ~AdditionalForm() = default;

    int toInt() override;
    static AdditionalForm Abs(const AdditionalForm& number);

    bool operator == (const AdditionalForm& number) const;
    bool operator != (const AdditionalForm& number) const;
    bool operator > (const AdditionalForm& number) const;
    bool operator < (const AdditionalForm& number) const;

    AdditionalForm operator + (const AdditionalForm& number) const;
    AdditionalForm operator - (const AdditionalForm& number) const;
    AdditionalForm operator * (const AdditionalForm& number) const;
    AdditionalForm operator / (const AdditionalForm& number) const;
};

istream& operator>>(istream& in, AdditionalForm& number);
ostream& operator<<(ostream& os, AdditionalForm& number);

#endif
