#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "library.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Company company = InputCompany();
    Weapon weapon = InputWeapon(company);
    Soldier soldier = InputSoldier();
    Control operation = InputControl(weapon, soldier);
    Armory armory = InputArmory(weapon, soldier, operation);
    OrderingOperations order;
    int exit = 0;
    do {
        system("cls");
        puts("Создан оружейный склад.");
        int choice;
        do {
            printf("Выберите действие:\n |1|Вывести оружейный склад\n |2|Добавить солдата\n |3|Добавить оружие\n |4|Добавить выдачу/сдачу оружия\n |5|Отсортировать операции\n |6|Завершение программы\nВаш выбор: ");
            scanf("%d", &choice);
            clean();
        } while (choice < 1 || choice > 6);
        if (choice == 1) {
            armory.OutputArmory();
            puts("Нажмите любую клавишу для продолжения...");
            _getch();
        }
        if (choice == 2) {
            armory.SoldierToArmory(InputSoldier());
            puts("Нажмите ENTER для добавления солдата в список.");
            _getch();
        }
        if (choice == 3) {
            Weapon gun = InputWeapon(InputCompany());
            armory + gun;
            puts("Нажмите ENTER для добавления снаряжения в список.");
            _getch();
        }
        if (choice == 4) {
            puts("Желаете использовать имеющееся оружие?\n|1|Да\n|2|Нет");
            int k;
            do {
                scanf("%d", &k);
                clean();
            } while (k < 1 || k > 2);
            Weapon w;
            if (k == 1) {
                system("cls");
                armory.OutputArmory();
                puts("Введите номер оружия из списка:");
                int NumOfWeapon;
                do {
                    scanf("%d", &NumOfWeapon);
                    clean();
                } while (NumOfWeapon<1 || NumOfWeapon>armory.GetNweapons());
                w = armory.weapons.at(NumOfWeapon - 1);
            }
            else {
                w = InputWeapon(InputCompany());
                armory.WeaponToArmory(w);
            }
            puts("Желаете использовать имеющегося солдата ?\n|1|Да\n|2|Нет");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Soldier s;
            if (k == 1) {
                system("cls");
                armory.OutputArmory();
                puts("Введите номер солдата из списка:");
                int NumOfSoldier;
                do {
                    scanf("%d", &NumOfSoldier);
                    clean();
                } while (NumOfSoldier<1 || NumOfSoldier>armory.GetNsoldiers());
                s = armory.soldiers.at(NumOfSoldier - 1);
            }
            else {
                s = InputSoldier();
                armory.SoldierToArmory(s);
            }
            armory.OperationToArmory(InputControl(w, s));
            puts("Нажмите ENTER для добавления операции в список.");
            _getch();
        }
        if (choice == 5) {
            system("cls");
            ArmoryToOrder(armory, order);
            order.OutputOrder();
            _getch();
        }
        if (choice == 6) {
            int yesno;
            do {
                printf("Вы уверены, что хотите выйти?\n|1|Да\n|2|Нет\nВаш выбор: ");
                scanf("%d", &yesno);
                clean();
            } while (yesno != 1 && yesno != 2);
            if (yesno == 1) {
                exit = 1;
            }
        }
    } while (exit == 0);
    return 0;

}