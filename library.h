#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define LEN 30
#define Date 11

// Классы
class Company {
public:
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
private:
    char* name;
    char* found_date;
    char* address;
};

class Weapon {
public:
    class Company company;
    Weapon() {//конструктор без параметров
    }
    Weapon( Company company) { //конструктор с одним параметром
        strcpy(this->name, "FAMAS");
        this->rel_year = 2000;
        this->company = company;
    }
    Weapon(char* name, Company company, int rel_year) {//конструктор с параметрами
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
private:
    char* name;
    int rel_year;
};

class Soldier {
public:
    Soldier() {//конструктор без параметров
    }
    Soldier(char* name) {//конструктор с одним параметром
        this->name = name;
        strcpy(this->draft_date, "11.12.1345");
        strcpy(this->address, "Летная, 13");
    }
    Soldier(char* name, char* draft_date, char* address) {//конструктор с параметрами
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
private:
    char* name;
    char* draft_date;
    char* address;
};

class Control {
private:
    char* operation;
    char* date;
public:
    Control() {//конструктор без параметров
    }
    Control(char* operation, char* date, Weapon weapon, Soldier soldier) { //конструктор с параметрами
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
    class Weapon weapon;
    class Soldier soldier;
};

class Armory {
public:
    int Nweapons = 1;
    int Nsoldiers = 1;
    int Noperations = 1;
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
    class Weapon* weapons;
    class Soldier* soldiers;
    class Control* operations;
private:
    char* military;
};

void clean()  //Очистка потока
{
    while (getchar() != '\n');
}

// Основные функции
//Ввод классов
Company InputCompany() { // ввод компании
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
    char* military = (char*)calloc(LEN, sizeof(char));

    puts("Введите номер ячейки склада (Н-р: ячейка А3):");
    gets_s(military, LEN);

    return Armory(weapon, soldier, operation, military);
}

//Вывод классов

void OutputArmory(Armory armory) {
    puts("\nСписок складского оружия:");
    for (int i = 0; i < armory.Nweapons; i++) {
        printf("|%d|Название \"%s\"\n   Год выпуска: %d\n   Компания: %s\n   Дата основания: %s\n", i + 1, armory.weapons[i].GetName(), armory.weapons[i].GetYear(), armory.weapons[i].company.GetName(), armory.weapons[i].company.GetDate());
    }
    puts("\nСписок призванных солдат:");
    for (int i = 0; i < armory.Nsoldiers; i++) {
        printf("|%d|ФИО: %s\n   Дата призыва: %s\n   Прописка по адресу: %s\n", i + 1, armory.soldiers[i].GetName(), armory.soldiers[i].GetDate(), armory.soldiers[i].GetAddress());
    }
    puts("\nОперации на складе:");
    for (int i = 0; i < armory.Noperations; i++) {
        printf("|%d|Оружие \"%s\"\n   Солдат: %s\n   Дата операции: %s\n   Вид операции: %s\n", i + 1, armory.operations[i].weapon.GetName(), armory.operations[i].soldier.GetName(), armory.operations[i].GetDate(), armory.operations[i].GetOperation());
    }
    puts("");
}

//Дополнительные функции добавления
Armory WeaponToArmory(Armory armory, Weapon weapon) { // добавление оружия
    armory.Nweapons += 1;
    armory.weapons = (Weapon*)realloc(armory.weapons, sizeof(Weapon) * armory.Nweapons);
    armory.weapons[armory.Nweapons - 1] = weapon;
    return armory;
}

Armory SoldierToArmory(Armory armory, Soldier soldier) { // добавление солдата
    armory.Nsoldiers += 1;
    armory.soldiers = (Soldier*)realloc(armory.soldiers, sizeof(Soldier) * armory.Nsoldiers);
    armory.soldiers[armory.Nsoldiers - 1] = soldier;
    return armory;
}

Armory OperationToArmory(Armory armory, Control operation) { // добавление операций контроля
    armory.Noperations += 1;
    armory.operations = (Control*)realloc(armory.operations, sizeof(Control) * armory.Noperations);
    armory.operations[armory.Noperations - 1] = operation;
    return armory;
}
