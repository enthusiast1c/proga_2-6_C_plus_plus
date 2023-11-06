﻿#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>

// Классы
class Company {
private:
    char* name;
    char* found_date;
    char* address;
public:
    static const int LEN = 30;
    static const int Date = 11;
    Company() {//конструктор без параметров
        char* name = (char*)calloc(LEN, sizeof(char));
        strcpy(name, "Армия ПК");
        char* found_date = (char*)calloc(Date, sizeof(char));
        strcpy(found_date, "22.11.1234");
        char* address = (char*)calloc(LEN, sizeof(char));
        strcpy(address, "Воевая, 7");
    }
    Company(char* name, char* found_date, char* address) { //конструктор с параметрами
        if (strlen(name) == 0 || strlen(address) == 0) {
            exit(-1);
        }
        else if (strlen(found_date) != Date - 1) {
            puts("Некорректная дата");
            exit(-1);
        }
        else {
            this->name = name;
            this->found_date = found_date;
            this->address = address;
        }
    }
    ~Company(){//деструктор
    }
    char* GetName() {
        return name;
    }
    char* GetDate() {
        return found_date;
    }
    char* GetAddress() {
        return address;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetDate(char* found_date) {
        this->found_date = found_date;
    }
    void SetAddress(char* address) {
        this->address = address;
    }
};

class Weapon {
private:
    char* name;
    int rel_year;
    static int NumWeap;
public:
    static const int LEN = 30;
    static const int Date = 11;
    class Company company;
    static int getNumber() {
        return NumWeap;
    }
    Weapon() {
        NumWeap++;
    }
    Weapon( Company company) { //конструктор с одним параметром
        NumWeap++;
        strcpy(this->name, "FAMAS");
        this->rel_year = 2000;
        this->company = company;
    }
    Weapon(char* name, Company company, int rel_year) {//конструктор с параметрами
        NumWeap++;
        if (strlen(name) == 0 || rel_year < 1000) {
            exit(-1);
        }
        else {
            this->name = name;
            this->company = company;
            this->rel_year = rel_year;
        }
    }
    ~Weapon() {//деструктор
    }
    char* GetName() {
        return name;
    }
    int GetYear() {
        return rel_year;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetYear(int rel_year) {
        this->rel_year = rel_year;
    }
};
int Weapon::NumWeap = -1;

class Soldier {
private:
    char* name;
    char* draft_date;
    char* address;
    static int NumSold;
public:
    static const int LEN = 30;
    static const int Date = 11;
    static int getNumber() {
        return NumSold;
    }
    Soldier() {
        NumSold++;
    }
    Soldier(char* name) {//конструктор с одним параметром
        NumSold++;
        this->name = name;
        strcpy(this->draft_date, "11.12.1345");
        strcpy(this->address, "Летная, 13");
    }
    Soldier(char* name, char* draft_date, char* address) {//конструктор с параметрами
        NumSold++;
        if (strlen(name) == 0 || strlen(draft_date) != Date - 1 || strlen(address) == 0) {
            exit(-1);
        }
        else {
            this->name = name;
            this->draft_date = draft_date;
            this->address = address;
        }
    }
    ~Soldier(){//деструктор
    }
    char* GetName() {
        return name;
    }
    char* GetDate() {
        return draft_date;
    }
    char* GetAddress() {
        return address;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetDate(char* draft_date) {
        this->draft_date = draft_date;
    }
    void SetAddress(char* address) {
        this->address = address;
    }
};
int Soldier::NumSold = -1;

class Control {
private:
    char* operation;
    char* date;
    static int NumOper;
public:
    static const int LEN = 30;
    static const int Date = 11;
    class Weapon weapon;
    class Soldier soldier;
    static int getNumber() {
        return NumOper;
    }
    Control() {
        NumOper++;
    }
    Control(char* operation, char* date, Weapon weapon, Soldier soldier) { //конструктор с параметрами
        NumOper++;
        if (strlen(operation) == 0 || strlen(date) != Date - 1) {
            exit(-1);
        }
        else {
            this->weapon = weapon;
            this->soldier = soldier;
            this->operation = operation;
            this->date = date;
        }
    }
    ~Control() {//деструктор
    }
    char* GetOperation() {
        return operation;
    }
    char* GetDate() {
        return date;
    }
    void SetOperation(char* operation) {
        this->operation = operation;
    }
    void SetDate(char* date) {
        this->date = date;
    }
};
int Control::NumOper = 0;

class Armory {
private:
    char* military;
public:
    static const int LEN = 30;
    static const int Date = 11;
    int Nweapons = 1;
    int Nsoldiers = 1;
    int Noperations = 1;
    class Weapon* weapons;
    class Soldier* soldiers;
    class Control* operations;
    Armory(){//конструктор без параметров
    }
    Armory(Weapon weapon, Soldier soldier, Control operation, char* military) { //конструктор с параметрами
        if (strlen(military) == 0) {
            exit(-1);
        }
        else {
            this->military = military;

            this->weapons = (Weapon*)malloc(sizeof(Weapon));
            this->weapons[this->Nweapons - 1] = weapon;

            this->operations = (Control*)malloc(sizeof(Control));
            this->operations[this->Noperations - 1] = operation;

            this->soldiers = (Soldier*)malloc(sizeof(Soldier));
            this->soldiers[this->Nsoldiers - 1] = soldier;
        }
    }
    ~Armory() {//деструктор
    }
    char* GetMilitary() {
        return military;
    }
    void SetMilitary(char* military) {
        this->military = military;
    }
    void WeaponToArmory(Weapon weapon) { // добавление оружия
        this->Nweapons += 1;
        this->weapons = (Weapon*)realloc(this->weapons, sizeof(Weapon) * this->Nweapons);
        this->weapons[this->Nweapons - 1] = weapon;
    }
    void SoldierToArmory(Soldier soldier) { // добавление солдата
        this->Nsoldiers += 1;
        this->soldiers = (Soldier*)realloc(this->soldiers, sizeof(Soldier) * this->Nsoldiers);
        this->soldiers[this->Nsoldiers - 1] = soldier;
    }
    void OperationToArmory(Control operation) { // добавление операций контроля
        this->Noperations += 1;
        this->operations = (Control*)realloc(this->operations, sizeof(Control) * this->Noperations);
        this->operations[this->Noperations - 1] = operation;
    }
    void OutputArmory() {
        printf("\nСписок складского оружия:\nВсего на складе: |%d|\n ",Weapon::getNumber());
        for (int i = 0; i < this->Nweapons; i++) {
            printf("|%d|Название \"%s\"\n   Год выпуска: %d\n   Компания: %s\n   Дата основания: %s\n", i + 1, this->weapons[i].GetName(), this->weapons[i].GetYear(), this->weapons[i].company.GetName(), this->weapons[i].company.GetDate());
        }
        printf("\nСписок призванных солдат:\nВсего на складе: |%d|\n ", Soldier::getNumber());
        for (int i = 0; i < this->Nsoldiers; i++) {
            printf("|%d|ФИО: %s\n   Дата призыва: %s\n   Прописка по адресу: %s\n", i + 1, this->soldiers[i].GetName(), this->soldiers[i].GetDate(), this->soldiers[i].GetAddress());
        }
        printf("\nОперации на складе:\nВсего на складе: |%d|\n ", Control::getNumber());
        for (int i = 0; i < this->Noperations; i++) {
            printf("|%d|Оружие \"%s\"\n   Солдат: %s\n   Дата операции: %s\n   Вид операции: %s\n", i + 1, this->operations[i].weapon.GetName(), this->operations[i].soldier.GetName(), this->operations[i].GetDate(), this->operations[i].GetOperation());
        }
        puts("");
    }
};

void clean()  //Очистка потока
{
    while (getchar() != '\n');
}

// Основные функции
//Ввод классов
Company InputCompany() {// ввод компании
    int LEN = Company::LEN;
    int Date = Company::Date;
    char* name = (char*)calloc(LEN, sizeof(char));
    char* found_date = (char*)calloc(Date, sizeof(char));
    char* address = (char*)calloc(LEN, sizeof(char));

    puts("Введите название компании:");
    gets_s(name, LEN);
    do {
        do {
            puts("Введите дату основания в формате ДД.ММ.ГГГГ:");
            gets_s(found_date, Date);
        } while (found_date[0] < '0' || found_date[0] > '3' || found_date[1] < '0' || (found_date[1] > '1' && found_date[0] > '2') || found_date[1] > '9' || found_date[2] != '.' || found_date[3] < '0' || found_date[3] > '1' || found_date[4] < '0' || (found_date[4] > '0' && found_date[3] > '2') || found_date[4] > '9' || found_date[5] != '.' || found_date[6] < '0' || found_date[6] > '9' || found_date[7] < '0' || found_date[7] > '9' || found_date[8] < '0' || found_date[8] > '9' || found_date[9] < '0' || found_date[9] > '9');
    } while (strlen(found_date) != 10);
    puts("Введите адрес компании:");
    gets_s(address, LEN);

    return Company(name, found_date, address);
}

Soldier InputSoldier() { // ввод солдата 
    int LEN = Soldier::LEN;
    int Date = Soldier::Date;
    char* name = (char*)calloc(LEN, sizeof(char));
    char* draft_date = (char*)calloc(Date, sizeof(char));
    char* address = (char*)calloc(LEN, sizeof(char));

    puts("Введите Фамилия И.О. солдата:");
    gets_s(name, LEN);
    do {
        do {
            puts("Введите дату призыва солдата в формате ДД.ММ.ГГГГ:");
            gets_s(draft_date, Date);
        } while (draft_date[0] < '0' || draft_date[0] > '3' || draft_date[1] < '0' || (draft_date[1] > '1' && draft_date[0] > '2') || draft_date[1] > '9' || draft_date[2] != '.' || draft_date[3] < '0' || (draft_date[3] == '1' && draft_date[4] > '2') || draft_date[3] > '1' || draft_date[4] < '0' || (draft_date[4] > '0' && draft_date[3] > '2') || draft_date[4] > '9' || draft_date[5] != '.' || draft_date[6] < '0' || draft_date[6] > '9' || draft_date[7] < '0' || draft_date[7] > '9' || draft_date[8] < '0' || draft_date[8] > '9' || draft_date[9] < '0' || draft_date[9] > '9');
    } while (strlen(draft_date) != 10);
    puts("Введите адрес прописки солдата:");
    gets_s(address, LEN);

    return Soldier(name, draft_date, address);
}

Weapon InputWeapon(Company company) { // ввод оружия
    int LEN = Weapon::LEN;
    int Date = Weapon::Date;
    int rel_year;
    char* name = (char*)calloc(LEN, sizeof(char));

    puts("Введите модель оружия:");
    gets_s(name, LEN);
    puts("Введите год выпуска:");
    do {
        scanf("%d", &rel_year);
        if (rel_year < 1132) {
            puts("Повторите попытку.");
        }
    } while (rel_year < 1132);
    clean();
    
    return Weapon(name, company, rel_year);
}

Control InputControl(Weapon weapon, Soldier soldier) { // ввод контроля выдачи/сдачи
    int LEN = Control::LEN;
    int Date = Control::Date;
    char* operation = (char*)calloc(LEN, sizeof(char));
    char* date = (char*)calloc(Date, sizeof(char));

    do {
        puts("Введите тип совершённой операции (Выдача/Сдача):");
        gets_s(operation, LEN);
    } while ((strcmp(operation, "Выдача") != 0 && strcmp(operation, "Сдача") != 0));
    puts("Введите дату совершения операции в формате ДД.ММ.ГГГГ:");
    gets_s(date, Date);

    return Control(operation, date, weapon, soldier);
}

Armory InputArmory(Weapon weapon, Soldier soldier, Control operation) { // ввод оружейного склада
    int LEN = Armory::LEN;
    int Date = Armory::Date;
    char* military = (char*)calloc(LEN, sizeof(char));

    puts("Введите номер ячейки склада (Н-р: ячейка А3):");
    gets_s(military, LEN);

    return Armory(weapon, soldier, operation, military);
}