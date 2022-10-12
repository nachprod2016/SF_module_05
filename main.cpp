#include <iostream>
#include <locale>
#include "Snack.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    VendingMachine* vm = nullptr;
    bool flag = true;
    int choice;
    while (flag)
    {
        
        std::cout << "1 - Создать торговый автомат" << std::endl;
        std::cout << "2 - Режим настройки торгового автомата" << std::endl;
        std::cout << "3 - Режим работы торгового автомата" << std::endl;
        std::cout << "4 - Удалить торговый автомат" << std::endl;
        std::cout << "0 - Выйти из программы" << std::endl;
        std::cout << "Выберите опцию: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
            case 1:
            {
                if (vm != nullptr)
                {
                    std::cout << "Торговый автомат уже создан!!!" << std::endl;
                }
                else
                {
                    int numSnackSlots, sizeSnackSlots;
                    std::cout << "Введите количество лотков для снеков: ";
                    std::cin >> numSnackSlots;
                    std::cout << "Количество снеков в лотке: ";
                    std::cin >> sizeSnackSlots;
                    vm = new VendingMachine(numSnackSlots, sizeSnackSlots);
                }
                break;
            }
            case 2:
            {
                if (vm != nullptr)
                {
                    bool flagSet = true;
                    int c;
                    while (flagSet)
                    {
                        std::cout << "1 - Показать содержимое лотков торгового автомата" << std::endl;
                        std::cout << "2 - Показать выручку" << std::endl;
                        std::cout << "3 - Забрать выручку" << std::endl;
                        std::cout << "4 - Очистить содержимое лотка" << std::endl;
                        std::cout << "5 - Загрузить снеки в лоток" << std::endl;
                        std::cout << "0 - Выйти из режима настройки торгового автомата" << std::endl;
                        std::cout << "Выберите опцию: ";
                        std::cin >> c;
                        std::cout << std::endl;
                        switch (c)
                        {
                            case 1:
                            {
                                vm->showСontent();
                                break;
                            }
                            case 2:
                            {
                                vm->showCash();
                                break;
                            }
                            case 3:
                            {
                                vm->takeCash();
                                break;
                            }
                            case 4:
                            {
                                int a;
                                std::cout << "Введите код лотка: ";
                                std::cin >> a;
                                SnackSlot* ptr = vm->choiceSnackSlot(a - 1);
                                if (ptr != nullptr)
                                {
                                    ptr->clearSlot();
                                }
                                break;
                            }
                            case 5:
                            {
                                vm->addSnacks();
                                break;
                            }
                            case 0:
                            {
                                flagSet = false;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Торговый автомат еще не создан!" << std::endl;
                }
                break;
            }
            case 3:
            {
                if (vm != nullptr)
                {
                    bool flagGet = true;
                    int c;
                    while (flagGet)
                    {
                        std::cout << "1 - Купить снек" << std::endl;
                        std::cout << "0 - Выйти из режима покупки" << std::endl;
                        std::cin >> c;
                        switch (c)
                        {
                            case 1:
                            {
                                vm->showСontent();
                                vm->takeSnack();
                                break;
                            }
                            case 0:
                            {
                                flagGet = false;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Торговый автомат еще не создан!" << std::endl;
                }
                break;
            }
            case 4:
            {
                if (vm != nullptr)
                {
                    VendingMachine* ptr = vm;
                    vm = nullptr;
                    delete ptr;
                }
                else
                {
                    std::cout << "Торговый автомат еще не создан!" << std::endl;
                }
                break;
            }
            case 0:
            {
                flag = false;
                break;
            }
        }
    }
    return 0;
}