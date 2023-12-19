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
    Company<string> company = InputCompany();
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
            printf("Выберите действие:\n |1|Вывести оружейный склад\n |2|Добавить солдата\n |3|Добавить оружие\n |4|Добавить выдачу/сдачу оружия\n |5|Отсортировать операции\n |6|Организация взвода\n |7|Конструкция try-catch\n |8|Тестирование виртуальной функции\n |9|Завершение программы\nВаш выбор: ");
            scanf("%d", &choice);
            clean();
        } while (choice < 1 || choice > 9);
        if (choice == 1) {
            armory.OutputArmory();
            puts("Нажмите любую клавишу для продолжения...");
            _getch();
        }
        else if (choice == 2) {
            armory.SoldierToArmory(InputSoldier());
            puts("Нажмите ENTER для добавления солдата в список.");
            _getch();
        }
        else if (choice == 3) {
            system("cls");
            int k;
            do {
                printf("Добавление снаряжения:\n|1|Добавить оружие\n|2|Добавить оружие с модификацией\n|3|Вернуться назад\nВаш выбор: ");
                do {
                    scanf("%d", &k);
                    clean();
                } while (k < 1 || k > 3);
                if (k == 1) {
                    Weapon gun = InputWeapon(InputCompany());
                    armory + gun;
                    puts("Нажмите ENTER для добавления снаряжения в список.");
                    _getch();
                }
                else if (k == 2) {
                    Weapon gun = InputWeapon(InputCompany());
                    WeaponMode weaponmode;
                    weaponmode = gun;
                    printf("\nВведите количество модификаций (не более 2)\nВаш выбор: ");
                    int k;
                    do {
                        scanf("%d", &k);
                    } while (k < 1 || k > 2);
                    string str;
                    for (int i = 0; i < k; i++) {
                        cout << "Введите " << i + 1 << " модификацию:" << endl;
                        cin >> str;
                        weaponmode.AddMode(str);
                    }
                    armory.WeaponModeToArmory(weaponmode);
                    puts("Нажмите ENTER для добавления снаряжения в список.");
                    _getch();
                    system("cls");
                }
            } while (k != 3);
        }
        else if (choice == 4) {
            printf("\nЖелаете использовать имеющееся оружие?\n|1|Да\n|2|Нет\nВаш выбор: ");
            int k;
            do {
                scanf("%d", &k);
                clean();
            } while (k < 1 || k > 2);
            Weapon w;
            if (k == 1) {
                system("cls");
                armory.OutputArmory();
                printf("\nВведите номер оружия из списка: ");
                int NumOfWeapon;
                do {
                    scanf("%d", &NumOfWeapon);
                    clean();
                } while (NumOfWeapon<1 || NumOfWeapon>(armory.GetNweapons()- WeaponMode::GetCountMode()));
                w = armory.weapons.at(NumOfWeapon - 1);
            }
            else {
                w = InputWeapon(InputCompany());
                armory.WeaponToArmory(w);
            }
            printf("\nЖелаете использовать имеющегося солдата ?\n|1|Да\n|2|Нет\nВаш выбор: ");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Soldier s;
            if (k == 1) {
                system("cls");
                armory.OutputArmory();
                printf("\nВведите номер солдата из списка: ");
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
        else if (choice == 5) {
            system("cls");
            ArmoryToOrder(armory, order);
            order.OutputOrder();
            _getch();
        }
        else if (choice == 6) {
            int n;
            static Platoon platoon;
            do {
                system("cls");
                printf("\nОрганизация взвода.Выберите действие:\n\n|1|Добавить солдата\n|2|Вывести взвод\n|3|Вернуться назад\n\nВаш выбор: ");
                do {
                    scanf("%d", &n);
                    clean();
                } while (n < 1 || n > 3);
                if (n == 1) {
                    int id;
                    cout << "\nВведите номер роты ( до " << 1 + platoon.GetNtroop() << " )\n";
                    do {
                        scanf("%d", &id);
                        id -= 1;
                    } while (id < 0 || id > platoon.GetNtroop());
                    system("cls");
                    armory.OutputArmory();
                    printf("\nВведите номер солдата из списка: ");
                    int NumOfSoldier;
                    do {
                        scanf("%d", &NumOfSoldier);
                    } while (NumOfSoldier<1 || NumOfSoldier>armory.GetNsoldiers());
                    Soldier sold = armory.soldiers.at(NumOfSoldier - 1);
                    platoon.AddSoldier(id, sold);
                }
                if (n == 2) {
                    system("cls");
                    platoon.OutputPlatoon();
                    puts("\nНажмите ENTER для возвращения в меню.");
                    _getch();
                }
            } while (n != 3);
        }
        else if (choice == 7) {
            system("cls");
            try {
                Soldier exsold("271277");
            }
            catch(const invalid_argument& exsold){
                cout << exsold.what();
            }
            puts("Нажмите ENTER для возвращения в меню.");
            _getch();
        }
        else if (choice == 8) {
            system("cls");
            puts("Тестирование виртуальной функции.");
            Weapon* weap = &weapon;
            WeaponMode wmod;
            wmod = weapon;
            printf("Введите количество модификаций (не более 2)\nВаш выбор: ");
            int k;
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            string str;
            for (int i = 0; i < k; i++) {
                cout << "Введите " << i + 1 << " модификацию:" << endl;
                cin >> str;
                wmod.AddMode(str);
            }
            WeaponMode* wmode1 = &wmod;
            weap->Output();
            wmode1->Output();
            --wmod;
            puts("Нажмите ENTER для возвращения в меню.");
            _getch();
        }
        else if (choice == 9) {
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