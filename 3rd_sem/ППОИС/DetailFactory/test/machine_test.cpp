#include "gtest/gtest.h"
#include "machines.h"

class MachineTest : public testing::Test{};

TEST_F(MachineTest, BasicTesting){
    EngineMachine e1;
    EXPECT_NE(e1.chanceCount(), 101);
    e1.work();
    for (auto i = 0; i < 12; i++) {
        e1.decreaseCondition();
    }
    e1.signalize();
    bool flag;
    for (auto i = 0; i < 10; i++){
        flag = e1.work();
    }
    EXPECT_EQ(e1.getType(), 1);
    Engine e = e1.getDummy();

    TransmissionMachine t1;
    t1.work();
    for (auto i = 0; i < 12; i++) {
        t1.decreaseCondition();
    }
    t1.signalize();
    for (auto i = 0; i < 10; i++){
        flag = t1.work();
    }
    EXPECT_EQ(t1.getType(), 2);
    Transmission t = t1.getDummy();

    BodyMachine b1;
    b1.work();
    for (auto i = 0; i < 30; i++) {
        b1.decreaseCondition();
    }
    b1.signalize();
    for (auto i = 0; i < 10; i++){
        flag = b1.work();
    }
    EXPECT_EQ(b1.getType(), 3);
    Body b = b1.getDummy();

    FuelTankMachine f1;
    f1.work();
    for (auto i = 0; i < 12; i++) {
        f1.decreaseCondition();
    }
    f1.signalize();
    for (auto i = 0; i < 10; i++){
        flag = f1.work();
    }
    EXPECT_EQ(f1.getType(), 4);
    FuelTank f = f1.getDummy();

}