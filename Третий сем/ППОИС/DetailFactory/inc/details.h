#ifndef DETAILFACTORY_DETAILS_H
#define DETAILFACTORY_DETAILS_H

#include <iostream>
#include <string>
#include <unordered_map>

class Detail {
protected:
    unsigned short type_;
    unsigned quality_;
public:
    virtual ~Detail() = default;

    [[nodiscard]]
    unsigned short getType() const;

    [[nodiscard]]
    unsigned getQuality() const;

    virtual void printInfo() = 0;
};

class Engine : public Detail {
private:
    unsigned power_;
public:
    std::unordered_map<std::string, unsigned> requiredMaterials_;

    Engine();
    explicit Engine(unsigned power);
    Engine(unsigned power, unsigned quality);
    ~Engine() override = default;

    void printInfo() override;
};

class Transmission : public Detail {
private:
    unsigned shafts_;
public:
    std::unordered_map<std::string, unsigned> requiredMaterials_;

    Transmission();
    explicit Transmission(unsigned shafts);
    Transmission(unsigned shafts, unsigned quality);
    ~Transmission() override = default;

    void printInfo() override;
};

class Body : public Detail {
private:
    std::string bodyType_;
    short unsigned doorAmount_;
public:
    std::unordered_map<std::string, unsigned> requiredMaterials_;

    Body();
    Body(std::string bodyType, short unsigned doorAmount);
    Body(std::string bodyType, short unsigned doorAmount, unsigned quality);
    ~Body() override = default;

    void printInfo() override;
};

class FuelTank : public Detail {
private:
    unsigned volume_;
public:
    std::unordered_map<std::string, unsigned> requiredMaterials_;

    FuelTank();
    explicit FuelTank(unsigned volume);
    FuelTank(unsigned volume, unsigned quality);
    ~FuelTank() override = default;

    void printInfo() override;
};

#endif
