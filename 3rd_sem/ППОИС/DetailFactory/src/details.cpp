#include "details.h"

unsigned short Detail::getType() const {
    return type_;
}

unsigned int Detail::getQuality() const {
    return quality_;
}

Engine::Engine() {
    type_ = 1;
    requiredMaterials_ = {
            {"steel", 500},
            {"rubber", 100},
            {"aluminium", 50}
    };

    quality_ = 100;
    power_ = 150;
}

Engine::Engine(unsigned int power) {
    type_ = 1;
    requiredMaterials_ = {
            {"steel", power * 2},
            {"rubber", 100},
            {"aluminium", 50}
    };

    quality_ = 100;
    power_ = power;
}

Engine::Engine(unsigned int power, unsigned int quality) {
    type_ = 1;
    requiredMaterials_ = {
            {"steel", power * 2},
            {"rubber", 100},
            {"aluminium", 50}
    };

    quality_ = quality;
    power_ = power;
}

void Engine::printInfo() {
    std::cout << "[ Engine with " << power_ << " hp (" << quality_ << "% quality) ]" << std::endl;
}

Transmission::Transmission() {
    type_ = 2;
    requiredMaterials_ = {
            {"steel", 100},
            {"rubber", 120},
            {"aluminium", 350}
    };

    quality_ = 100;
    shafts_ = 2;
}

Transmission::Transmission(unsigned int shafts) {
    type_ = 2;
    requiredMaterials_ = {
            {"steel", shafts * 50},
            {"rubber", shafts * 60},
            {"aluminium", 350}
    };

    quality_ = 100;
    shafts_ = shafts;
}

Transmission::Transmission(unsigned int shafts, unsigned int quality) {
    type_ = 2;
    requiredMaterials_ = {
            {"steel", shafts * 50},
            {"rubber", shafts * 60},
            {"aluminium", 350}
    };

    quality_ = quality;
    shafts_ = shafts;
}

void Transmission::printInfo() {
    std::cout << "[ Transmission with " << shafts_ << " shafts (" << quality_ << "%) ]" << std::endl;
}

Body::Body() {
    type_ = 3;
    requiredMaterials_ = {
            {"glass", 60},
            {"rubber", 20},
            {"aluminium", 650}
    };

    quality_ = 100;
    bodyType_ = "hatchback";
    doorAmount_ = 2;
}

Body::Body(std::string bodyType, unsigned short doorAmount) {
    type_ = 3;
    requiredMaterials_ = {
            {"glass", 40 + 20 * doorAmount},
            {"rubber", 10 * doorAmount},
            {"aluminium", 500 + 75 * doorAmount}
    };

    quality_ = 100;
    bodyType_ = bodyType;
    doorAmount_ = 2;
}

Body::Body(std::string bodyType, unsigned short doorAmount, unsigned quality) {
    type_ = 3;
    requiredMaterials_ = {
            {"glass", 40 + 20 * doorAmount},
            {"rubber", 10 * doorAmount},
            {"aluminium", 500 + 75 * doorAmount}
    };

    quality_ = quality;
    bodyType_ = bodyType;
    doorAmount_ = 2;
}

void Body::printInfo() {
    std::cout << "[ " << bodyType_ << " with " << doorAmount_ << " doors (" << quality_ << "%) ]" << std::endl;
}

FuelTank::FuelTank() {
    type_ = 4;
    requiredMaterials_ = {
            {"rubber", 10},
            {"aluminium", 100}
    };
    volume_ = 50;
    quality_ = 100;
}

FuelTank::FuelTank(unsigned int volume) {
    type_ = 4;
    requiredMaterials_ = {
            {"rubber", 10},
            {"aluminium", 2 * volume}
    };
    volume_ = volume;
    quality_ = 100;
}

FuelTank::FuelTank(unsigned int volume, unsigned int quality) {
    type_ = 4;
    requiredMaterials_ = {
            {"rubber", 10},
            {"aluminium", 2 * volume}
    };
    volume_ = volume;
    quality_ = quality;
}

void FuelTank::printInfo() {
    std::cout << "[ Fuel tank for " << volume_ << " liters of gas (" << quality_ << "%) ]" << std::endl;
}