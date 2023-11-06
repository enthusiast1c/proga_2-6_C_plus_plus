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
    int exit = 0;
    do {
        system("cls");
        puts("Создан оружейный склад.");
        int choice;
        do {
            printf("Выберите действие:\n |1|Вывести оружейный склад\n |2|Добавить солдата\n |3|Добавить оружие\n |4|Добавить выдачу/сдачу оружия\n |5|Завершение программы\nВаш выбор: ");
            scanf("%d", &choice);
            clean();
        } while (choice < 1 || choice >5);
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
            armory.WeaponToArmory(InputWeapon(InputCompany()));
            puts("Нажмите ENTER для добавления снаряжения в список.");
            _getch();
        }
        if (choice == 4) {
            Weapon gun = InputWeapon(InputCompany());
            Soldier sol = InputSoldier();
            armory.WeaponToArmory(gun);
            armory.SoldierToArmory(sol);
            armory.OperationToArmory(InputControl(gun, sol));
            puts("Нажмите ENTER для добавления операции в список.");
            _getch();
        }
        if (choice == 5) {
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