#include "employees.h"

Manager::Manager(std::unordered_map<std::string, unsigned> * stock) {
    workPrice_ = 100;
    shifts_ = 0;
    currentPrice_ = 0;
    stock_ = stock;

    priceList_["rubber"] = 10;
    priceList_["glass"] = 20;
    priceList_["steel"] = 30;
    priceList_["aluminum"] = 50;

}

Manager::Manager(std::unordered_map<std::string, unsigned> * stock, unsigned workPrice) {
    workPrice_ = workPrice;
    shifts_ = 0;
    currentPrice_ = 0;
    stock_ = stock;

    priceList_["rubber"] = 10;
    priceList_["glass"] = 20;
    priceList_["steel"] = 30;
    priceList_["aluminum"] = 50;
}

void Employee::getPaid(unsigned int &money) {
    money -= currentPrice_;
    currentPrice_ = 0;
    shifts_ = 0;
}

bool Manager::checkMaterial(std::string material, unsigned amount) {
    for (auto [material_, amount_] : *stock_){
        if (material_ != material)
            continue;
        if (amount_ >= amount)
            return true;
        else
            return false;
    }
    return false;
}

void Manager::getMaterial(std::string material, unsigned amount) {
    (*stock_)[material] -= amount;
    currentPrice_ += priceList_[material] * amount;
}

void Manager::showStock() {
    std::cout << "Current condition of stock: " << std::endl;
    for (auto [material, amount] : *stock_)
        std::cout << "[" << material << " : " << amount << "]" << std::endl;
}

bool Manager::work(std::unordered_map<std::string, unsigned> materials) {
    if (currentPrice_ > 10000){
        std::cout << "Manager don't wnt to work\n";
        return false;
    }

    showStock();

    for (auto & [key, value] : materials){
        if (!checkMaterial(key, value)){
            std::cout << "No " << key << " on the stock\n";
            return false;
        }
    }

    for (auto & [key, value] : materials){
        shifts_++;
        getMaterial(key, value);
    }

    return true;
}

unsigned Employee::requestedMoney() const {
    return currentPrice_ + shifts_ * workPrice_;
}

Controller::Controller(std::vector<Machine*> machines) {
    workPrice_ = 300;
    shifts_ = 0;
    currentPrice_ = 0;
    machines_ = machines;
}

ssize_t Controller::findMachine(unsigned short type) {
    for (ssize_t i = 0; i < machines_.size(); i++) {
        if (machines_[i]->getType() == type)
            return i;
    }
    return -1;
}

Detail* Controller::makeDetail(unsigned short detailType) {
    if (shifts_ > 7){
        std::cout << "Controller don't want to work";
        return nullptr;
    }

    auto ind = findMachine(detailType);
    if (!machines_[ind]->work())
        return nullptr;

    Detail* detail = nullptr;

    if (detailType == 1){
        detail = new Engine;
    }
    if (detailType == 2) {
        detail = new Transmission;
    }
    if (detailType == 3) {
        detail = new Body;
    }
    if (detailType == 4) {
        detail = new FuelTank;
    }

    return detail;
}