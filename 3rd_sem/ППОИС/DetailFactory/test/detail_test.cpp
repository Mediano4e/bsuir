#include <gtest/gtest.h>
#include "details.h"

class DetailTest : public testing::Test{};

TEST_F(DetailTest, BasicTestings){
    Engine engine1;
    EXPECT_EQ(engine1.getType(), 1);
    EXPECT_EQ(engine1.getQuality(), 100);
    engine1.printInfo();
    Engine engine2(200);
    engine2.printInfo();
    Engine engine3(400, 75);
    engine3.printInfo();

    Transmission tr1;
    EXPECT_EQ(tr1.getType(), 2);
    EXPECT_EQ(tr1.getQuality(), 100);
    tr1.printInfo();
    Transmission tr2(6);
    tr2.printInfo();
    Transmission tr3(4, 75);
    tr3.printInfo();

    Body b1;
    EXPECT_EQ(b1.getType(), 3);
    EXPECT_EQ(b1.getQuality(), 100);
    b1.printInfo();
    Body b2("ad", 8);
    b2.printInfo();
    Body b3("ap", 6, 35);
    b3.printInfo();

    FuelTank t1;
    EXPECT_EQ(t1.getType(), 4);
    EXPECT_EQ(t1.getQuality(), 100);
    t1.printInfo();
    FuelTank t2(250);
    t2.printInfo();
    FuelTank t3(800, 20);
    t3.printInfo();
}