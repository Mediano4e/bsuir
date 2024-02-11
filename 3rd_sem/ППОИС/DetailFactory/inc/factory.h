#ifndef DETAILFACTORY_FACTORY_H
#define DETAILFACTORY_FACTORY_H

#include <vector>

#include "machines.h"
#include "employees.h"

class Factory {
private:
    bool working_;
    unsigned money_ = 100000;
    std::unordered_map<std::string, unsigned> stock = {
            {"rubber", 20000},
            {"steel", 20000},
            {"aluminium", 20000},
            {"glass", 20000}
    };
    std::unordered_map<unsigned short, unsigned> priceList_ = {
            {1, 50000},
            {2, 40000},
            {3, 30000},
            {4, 25000}
    };
    std::vector<Detail*> createdDetails_;
    std::vector<Machine*> machines_;
    Manager manager_;
    Controller controller_;
public:
    Factory();
    ~Factory();

    void createDetail(unsigned short type);
    void sellDetails();
    void showMoney();
};

#endif
