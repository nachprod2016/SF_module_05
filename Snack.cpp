#include <iostream>
#include "Snack.h"

//Снек
Snack::Snack(std::string name) : name(name), cost(0.0), calories(0){}

Snack::Snack(std::string name, double cost, int calories) : name(name), cost(cost), calories(calories){}

std::string Snack::getName() const
{
    return name;
}

void Snack::setName(std::string name)
{
    this->name = name;
}

double Snack::getCost() const
{
    return cost;
}

void Snack::setCost(double cost)
{
    this->cost = cost;
}

int Snack::getCalories() const
{
    return calories;
}

void Snack::setCalories(int calories)
{
    this->calories = calories;
}

//лоток
SnackSlot::SnackSlot(int sizeSlot) : sizeSlot(sizeSlot)
{
    numSnack = 0;
    snacks = new Snack*[sizeSlot];
    for (int i = 0; i < sizeSlot; i++)
    {
        snacks[i] = nullptr;
    }
}

SnackSlot::~SnackSlot()
{
    for (int i = 0; i < numSnack; i++)
    {
        delete snacks[i];
    }
    delete [] snacks;
}

void SnackSlot::addSnack()
{
    if (numSnack == sizeSlot)
    {
        std::cout << "Лоток полностью заполнен" << std::endl;
        return;
    }
    std::string name_ch;
    double cost;
    int calories, num;
    std::cout << "Название снека: ";
    std::cin >> name_ch;
    std::cout << "Цена снека: ";
    std::cin >> cost;
    std::cout << "Калорийность снека: ";
    std::cin >> calories;
    while (true)
    {
        std::cout << "Количество снеков для загрузки в лоток: ";
        std::cin >> num;
        if (num > 0 && num <= sizeSlot - numSnack)
        {
            break;
        }
        std::cout << "Неверное количество" << std::endl;
    }
    for (int i = numSnack; i < numSnack + num; i++)
    {
        snacks[i] = new Snack(name_ch, cost, calories);
    }
    numSnack += num;
}

void SnackSlot::clearSlot()
{
    if (numSnack == 0)
    {
        std::cout << "Лоток пуст" << std::endl;
    }
    else
    {
        for (int i = 0; i < numSnack; i++)
        {
            delete snacks[i];
            snacks[i] = nullptr;
        }
        numSnack = 0;
    }
}

Snack* SnackSlot::nextSnack() const
{
    return snacks[0];
}

void SnackSlot::takeSnacks()
{
    if (numSnack == 0)
    {
        std::cout << "Лоток пуст" << std::endl;
    }
    else
    {
        delete snacks[0];
        snacks[0] = nullptr;
        for (int i = 1; i < numSnack; i++)
        {
            snacks[i - 1] = snacks[i];
            snacks[i] = nullptr;
        }
        numSnack--;
    }
}

int SnackSlot::getNumSnack() const
{
    return numSnack;
}

int SnackSlot::getSizeSlot() const
{
    return sizeSlot;
}

//Торговый авомат
VendingMachine::VendingMachine(int numSlots, int sizeSlot) : numSlots(numSlots), sizeSlot(sizeSlot), cash(0.0)
{
    snackSlots = new SnackSlot*[numSlots];
    for (int i = 0; i < numSlots; i++)
    {
        snackSlots[i] = new SnackSlot(sizeSlot);
    }
}

VendingMachine::~VendingMachine()
{
    for (int i = 0; i < numSlots; i++)
    {
        delete snackSlots[i];
    }
    delete [] snackSlots;
}

void VendingMachine::showСontent()
{
    for (int i = 0; i < numSlots; i++)
    {
        Snack* ptr = snackSlots[i]->nextSnack();
        int calories, numSnaks;
        double cost;
        char* name;
        char empty[] = "empty\0";
        ptr = snackSlots[i]->nextSnack();
        if (ptr == nullptr)
        {
            cost = 0.0;
            calories = 0;
            numSnaks = 0;
            name = empty;
        }
        else
        {
            cost = ptr->getCost();
            calories = ptr->getCalories();
            name = &(ptr->getName().at(0));
            numSnaks = snackSlots[i]->getNumSnack();
        }
        std::cout << "Код: " << i + 1 << std::endl;
        std::cout << "Название: " << name << std::endl;
        std::cout << "Цена: " << cost << " руб" << std::endl;
        std::cout << "Калорийность: " << calories << " Ккал" << std::endl;
        std::cout << "Количество: " << numSnaks << "/" << sizeSlot << std::endl;
        std::cout << std::endl;
    }
}

void VendingMachine::showCash()
{
    std::cout << "Выручка: " << cash << " руб" << std::endl;  
}

void VendingMachine::takeCash()
{
    cash = 0.0;
}

SnackSlot* VendingMachine::choiceSnackSlot(int a)
{
    SnackSlot* ptr = nullptr;
    if (a >= 0 && a < numSlots)
    {
        ptr = snackSlots[a];
    }
    return ptr;
}

void VendingMachine::addSnacks()
{
    int a;
    std::cout << "Введите код лотка: " << std::endl;
    std::cin >> a;
    SnackSlot* ptr = choiceSnackSlot(a - 1);
    if (ptr != nullptr)
    {
        ptr->addSnack();
    }
}

void VendingMachine::takeSnack()
{
    int a;
    std::cout << "Введите код лотка: " << std::endl;
    std::cin >> a;
    if (a >= 1 && a <= numSlots)
    {
        SnackSlot* ptr = choiceSnackSlot(a - 1);
        if (ptr->nextSnack() != nullptr)
        {
            cash += ptr->nextSnack()->getCost();
            ptr->takeSnacks();
        }
        else
        {
            std::cout << "Лоток пуст!!!" << std::endl;
        }
    }
    else
    {
        std::cout << "Неверный код лотка" << std::endl;
    }
}