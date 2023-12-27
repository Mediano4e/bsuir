#include "gtest/gtest.h"
#include "employees.h"

class EmployeeTest : public testing::Test{};

TEST_F(EmployeeTest, BasicTesting) {
    Manager mm;
    std::unordered_map<std::string, unsigned> stock = {
            {"rubber",    20000},
            {"steel",     20000},
            {"aluminium", 20000},
            {"glass",     20000}
    };
    Manager mmm(&stock, 100);
    Manager m(&stock);
    EXPECT_EQ(m.requestedMoney(), 0);
    unsigned money = 10000;
    m.getPaid(money);
    EXPECT_FALSE(m.checkMaterial("d", 100));
    EXPECT_FALSE(m.checkMaterial("steel", 200000));
    EXPECT_TRUE(m.checkMaterial("glass", 100));
    m.getMaterial("glass", 100);
    m.showStock();
    std::unordered_map<std::string, unsigned> material = {
            {"glass", 60},
            {"rubber", 20},
            {"aluminium", 650}
    };
    std::unordered_map<std::string, unsigned> material1 = {
            {"glass", 600000},
            {"rubber", 200000},
            {"aluminium", 650000}
    };
    m.work(material);
    m.work(material1);
    m.currentPrice_ = 10010;
    m.work(material);

    Controller cc;
    std::vector<Machine*> machines_;
    machines_.push_back(new EngineMachine);
    machines_.push_back(new TransmissionMachine);
    machines_.push_back(new BodyMachine);
    machines_.push_back(new FuelTankMachine);
    Controller c(machines_);
    EXPECT_EQ(c.findMachine(5), -1);
    EXPECT_EQ(c.findMachine(1), 0);
}