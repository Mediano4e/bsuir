#ifndef DETAILFACTORY_EMPLOYEES_H
#define DETAILFACTORY_EMPLOYEES_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "details.h"
#include "machines.h"
#include "gtest/gtest.h"

class Employee {
protected:
    unsigned workPrice_;
    unsigned shifts_;
    unsigned currentPrice_;

public:
    [[nodiscard]]
    unsigned requestedMoney() const;
    void getPaid(unsigned & money);
};

class Manager : public Employee {
    friend class EmployeeTest;

    FRIEND_TEST(EmployeeTest, BasicTesting);
private:
    std::unordered_map<std::string, unsigned> *stock_;
    std::unordered_map<std::string, unsigned> priceList_;

public:
    Manager() = default;
    explicit Manager(std::unordered_map<std::string, unsigned> * stock);
    Manager(std::unordered_map<std::string, unsigned> * stock, unsigned workPrice);
    ~Manager() = default;

    bool checkMaterial(std::string material, unsigned amount);
    void getMaterial(std::string material, unsigned amount);
    void showStock();

    bool work(std::unordered_map<std::string, unsigned> materials);

};

class Controller : public Employee {
    friend class EmployeeTest;

    FRIEND_TEST(EmployeeTest, BasicTesting);
private:
    std::vector<Machine*> machines_;

    ssize_t findMachine(unsigned short type);

public:
    Controller() = default;
    explicit Controller(std::vector<Machine*> machines);
    ~Controller() = default;

    Detail* makeDetail(unsigned short detailType);
};

#endif
