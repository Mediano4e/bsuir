#include "machines.h"

#define ENGINE_MIN_CHANCE 30

unsigned Machine::chanceCount() const {
    srand(time(nullptr));

    return rand() % (condition_ + 1);
}

unsigned int Machine::getType() const {
    return type_;
}

bool Machine::work() {
    signalize();

    unsigned chance = chanceCount();

    if (chance <= ENGINE_MIN_CHANCE) {
        std::cout << "Failed" << std::endl;
        return false;
    }

    decreaseCondition();

    return true;
}

void EngineMachine::signalize() {
    std::cout << "Creating engine " << std::endl;
}

void EngineMachine::decreaseCondition() {
    if (condition_ <= 55)
        return;

    condition_ -= 5;
}

void TransmissionMachine::signalize() {
    std::cout << "Creating transmission " << std::endl;
}

void TransmissionMachine::decreaseCondition() {
    if (condition_ <= 40)
        return;

    condition_ -= 8;
}

void BodyMachine::signalize() {
    std::cout << "Creating car's body " << std::endl;
}

void BodyMachine::decreaseCondition() {
    if (condition_ <= 50)
        return;

    condition_ -= 3;
}

void FuelTankMachine::signalize() {
    std::cout << "Creating fuel tank " << std::endl;
}

void FuelTankMachine::decreaseCondition() {
    if (condition_ <= 45)
        return;

    condition_ -= 10;
}

EngineMachine::EngineMachine() {
    Engine a;
    dummy_ = a;
    condition_ = 100;
    type_ = 1;
}

TransmissionMachine::TransmissionMachine() {
    Transmission a;
    dummy_ = a;
    condition_ = 100;
    type_ = 2;
}

BodyMachine::BodyMachine() {
    Body a;
    dummy_ = a;
    condition_ = 100;
    type_ = 3;
}

FuelTankMachine::FuelTankMachine() {
    FuelTank a;
    dummy_ = a;
    condition_ = 100;
    type_ = 4;
}

Engine EngineMachine::getDummy() {
    return dummy_;
}

Transmission TransmissionMachine::getDummy() {
    return dummy_;
}

Body BodyMachine::getDummy() {
    return dummy_;
}

FuelTank FuelTankMachine::getDummy() {
    return dummy_;
}