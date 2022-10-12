#pragma once
#include <string>

class Snack
{
    private:
    std::string name;
    double cost;
    int calories;

    public:
    explicit Snack(std::string name);
    Snack(std::string name, double cost, int calories);
    std::string getName() const;
    void setName(std::string name);
    double getCost() const;
    void setCost(double cost);
    int getCalories() const;
    void setCalories(int calories);
};

class SnackSlot
{
    private:
    const int sizeSlot;
    int numSnack;
    Snack** snacks;

    public:
    explicit SnackSlot(int sizeSlot);
    ~SnackSlot();
    void addSnack();
    void clearSlot();
    Snack* nextSnack() const;
    void takeSnacks();
    int getNumSnack() const;
    int getSizeSlot() const;
};

class VendingMachine
{
    private:
    int numSlots;
    int sizeSlot;
    double cash;
    SnackSlot** snackSlots;


    public:
    explicit VendingMachine(int numSlots,  int sizeSlot);
    ~VendingMachine();
    int getNumSlots() const;
    void addSnacks();
    void takeSnack();
    void showСontent();
    void showCash();
    void takeCash();
    SnackSlot* choiceSnackSlot(int a);
};