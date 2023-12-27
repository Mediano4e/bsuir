#ifndef DETAILFACTORY_MACHINES_H
#define DETAILFACTORY_MACHINES_H

#include "details.h"
#include "gtest/gtest.h"

class Machine {
protected:
    unsigned condition_;
    unsigned short type_;

    [[nodiscard]]
    unsigned chanceCount() const;

    virtual void decreaseCondition() = 0;
    virtual void signalize() = 0;
public:
    virtual ~Machine()= default;
    [[nodiscard]]
    unsigned getType() const;

    bool work();
};

class EngineMachine : public Machine {
    friend class MachineTest;

    FRIEND_TEST(MachineTest, BasicTesting);
protected:
    Engine dummy_;
    void signalize() override;
    void decreaseCondition() override;
public:
    EngineMachine();
    ~EngineMachine() override = default;

    Engine getDummy();
};

class TransmissionMachine : public Machine {
    friend class MachineTest;

    FRIEND_TEST(MachineTest, BasicTesting);
protected:
    Transmission dummy_;
    void signalize() override;
    void decreaseCondition() override;
public:
    TransmissionMachine();
    ~TransmissionMachine() override = default;

    Transmission getDummy();
};

class BodyMachine : public Machine {
    friend class MachineTest;

    FRIEND_TEST(MachineTest, BasicTesting);
protected:
    Body dummy_;
    void signalize() override;
    void decreaseCondition() override;
public:
    BodyMachine();
    ~BodyMachine() override = default;

    Body getDummy();
};

class FuelTankMachine : public Machine {
    friend class MachineTest;

    FRIEND_TEST(MachineTest, BasicTesting);
protected:
    FuelTank dummy_;
    void signalize() override;
    void decreaseCondition() override;
public:
    FuelTankMachine();
    ~FuelTankMachine() override = default;

    FuelTank getDummy();
};

#endif
