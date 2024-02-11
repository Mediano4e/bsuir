#include "factory.h"

Factory::Factory() {
    working_ = true;

    machines_.push_back(new EngineMachine);
    machines_.push_back(new TransmissionMachine);
    machines_.push_back(new BodyMachine);
    machines_.push_back(new FuelTankMachine);

    Manager manager(&this->stock);
    Controller controller(this->machines_);

    manager_ = manager;
    controller_ = controller;
}

Factory::~Factory() {
    for (auto machine : machines_){
        delete machine;
    }

    for (auto detail : createdDetails_){
        delete detail;
    }
}

void Factory::createDetail(unsigned short type) {
    if (type == 1) {
        Engine example;
        if (manager_.work(example.requiredMaterials_)) {
            Detail *detail = controller_.makeDetail(type);
            if (detail != nullptr)
                createdDetails_.push_back(detail);
        }
    }
    else if (type == 2) {
        Transmission example;
        if (manager_.work(example.requiredMaterials_)) {
            Detail *detail = controller_.makeDetail(type);
            if (detail != nullptr)
                createdDetails_.push_back(detail);
        }
    }
    else if (type == 3) {
        Body example;
        if (manager_.work(example.requiredMaterials_)) {
            Detail *detail = controller_.makeDetail(type);
            if (detail != nullptr)
                createdDetails_.push_back(detail);
        }
    }
    else if (type == 4) {
        FuelTank example;
        if (manager_.work(example.requiredMaterials_)) {
            Detail *detail = controller_.makeDetail(type);
            if (detail != nullptr)
                createdDetails_.push_back(detail);
        }
    }
    else return;

    manager_.getPaid(money_);
    controller_.getPaid(money_);
}

void Factory::sellDetails() {
    while (!createdDetails_.empty()) {
        Detail* detail = createdDetails_.back();
        createdDetails_.pop_back();


        money_ += priceList_[detail->getType()];
        delete detail;
    }
}

void Factory::showMoney() {
    std::cout << "Current finances of factory are " << money_ << "\n";
}