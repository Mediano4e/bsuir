#ifndef LAB1_DIRECTFORM_H
#define LAB1_DIRECTFORM_H

#include "BinaryInt.h"

class DirectForm : public BinaryInt {
private:
    bitset<32> convertNumber(int number) override;
    [[nodiscard]]
    bool isGreater(const DirectForm& number, bool leftPriority) const;
public:
    DirectForm();
    DirectForm(int number);
    ~DirectForm() = default;

    int toInt() override;

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
ostream& operator <<(ostream& os, DirectForm& number);

#endif
