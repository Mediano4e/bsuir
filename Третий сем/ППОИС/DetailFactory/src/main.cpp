#include "factory.h"

int main() {
    Factory factory;

    factory.createDetail(1);
    factory.createDetail(3);
    factory.createDetail(4);
    factory.createDetail(1);

    factory.showMoney();

    factory.sellDetails();

    factory.showMoney();

    return 0;
}