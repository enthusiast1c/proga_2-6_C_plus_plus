#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <vector>
using namespace std;

// Классы
class Company {
private:
    string name;
    string found_date;
    string address;
public:
    static const int LEN = 30;
    static const int Date = 11;
    Company() {//конструктор без параметров
    }
    Company(string name, string found_date, string address) { //конструктор с параметрами
        if (name.empty() || address.empty()) {
            exit(-1);
        }
        else if (found_date.length() != Date - 1) {
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
    string GetName() {
        return name;
    }
    string GetDate() {
        return found_date;
    }
    string GetAddress() {
        return address;
    }
    string SetName(string name) {
        this->name = name;
    }
    void SetDate(string found_date) {
        this->found_date = found_date;
    }
    void SetAddress(string address) {
        this->address = address;
    }
};

class Weapon {
private:
    string name;
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
        this->rel_year = 2000;
        this->company = company;
    }
    Weapon(string name, Company company, int rel_year) {//конструктор с параметрами
        NumWeap++;
        if (name.empty() || rel_year < 1000) {
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
    string GetName() {
        return name;
    }
    int GetYear() {
        return rel_year;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetYear(int rel_year) {
        this->rel_year = rel_year;
    }
};
int Weapon::NumWeap = -1;

class Soldier {
private:
    string name;
    string draft_date;
    string address;
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
    Soldier(string name) {//конструктор с одним параметром
        NumSold++;
        this->name = name;
        draft_date = "11.12.1345";
        address = "Летная, 13";
    }
    Soldier(string name, string draft_date, string address) {//конструктор с параметрами
        NumSold++;
        if (name.empty() || draft_date.length() != Date - 1 || address.empty()) {
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
    string GetName() {
        return name;
    }
    string GetDate() {
        return draft_date;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetDate(string draft_date) {
        this->draft_date = draft_date;
    }
    void SetAddress(string address) {
        this->address = address;
    }
};
int Soldier::NumSold = -1;

class Control {
private:
    string operation;
    string date;
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
    Control(string operation, string date, Weapon weapon, Soldier soldier) { //конструктор с параметрами
        NumOper++;
        if (operation.empty() || date.length() != Date - 1) {
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
    string GetOperation() {
        return operation;
    }
    string GetDate() {
        return date;
    }
    void SetOperation(string operation) {
        this->operation = operation;
    }
    void SetDate(string date) {
        this->date = date;
    }
};
int Control::NumOper = 0;

class Armory {
private:
    string military;
public:
    static const int LEN = 30;
    static const int Date = 11;
    int Nweapons = 1;
    int Nsoldiers = 1;
    int Noperations = 1;
    vector <Weapon> weapons;
    vector <Soldier> soldiers;
    vector <Control> operations;
    Armory(){//конструктор без параметров
    }
    Armory(Weapon weapon, Soldier soldier, Control operation, string military) { //конструктор с параметрами
        if (military.empty()) {
            exit(-1);
        }
        else {
            this->military = military;
            this->weapons.push_back(weapon);
            this->soldiers.push_back(soldier);
            this->operations.push_back(operation);
        }
    }
    ~Armory() {//деструктор
    }
    string GetMilitary() {
        return military;
    }
    void SetMilitary(string military) {
        this->military = military;
    }
    void WeaponToArmory(Weapon weapon) { // добавление оружия
        this->Nweapons += 1;
        this->weapons.push_back(weapon);
    }
    void SoldierToArmory(Soldier soldier) { // добавление солдата
        this->Nsoldiers += 1;
        this->soldiers.push_back(soldier);
    }
    void OperationToArmory(Control operation) { // добавление операций контроля
        this->Noperations += 1;
        this->operations.push_back(operation);
    }
    void OutputArmory() {
        printf("\n\nСписок складского оружия:\nВсего на складе: |%d|\n",Weapon::getNumber());
        for (int i = 0, j = 1; i < this->Nweapons; i++) {
            cout << "\n|" << j++ << "|Название: " << this->weapons.at(i).GetName() << "\n   Год выпуска: " << this->weapons.at(i).GetYear() << "\n   Компания: " << this->weapons.at(i).company.GetName() << "\n   Дата основания: " << this->weapons.at(i).company.GetDate();
        }
        printf("\n\nСписок призванных солдат:\nВсего на складе: |%d|\n", Soldier::getNumber());
        for (int i = 0, j = 1; i < this->Nsoldiers; i++) {
            cout << "\n|" << j++ << "|ФИО: " << this->soldiers.at(i).GetName() << "\n   Дата призыва: " << this->soldiers.at(i).GetDate() + "\n   Прописка по адресу: " << this->soldiers.at(i).GetAddress();
        }
        printf("\n\nОперации на складе:\nВсего на складе: |%d|\n", Control::getNumber());
        for (int i = 0, j = 1; i < this->Noperations; i++) {
            cout << "\n|" << j++ << "|Оружие: " << this->operations.at(i).weapon.GetName() << "\n   Солдат: " << this->operations.at(i).soldier.GetName() << "\n   Дата операции: " << this->operations.at(i).GetDate() << "\n   Вид операции: " << this->operations.at(i).GetOperation();
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
    string name;
    string found_date;
    string address;

    puts("Введите название компании:");
    cin >> name;
    clean();
    do {
        do {
            puts("Введите дату основания в формате ДД.ММ.ГГГГ:");
            cin >> found_date;
        } while (found_date[0] < '0' || found_date[0] > '3' || found_date[1] < '0' || (found_date[1] > '1' && found_date[0] > '2') || found_date[1] > '9' || found_date[2] != '.' || found_date[3] < '0' || found_date[3] > '1' || found_date[4] < '0' || (found_date[4] > '0' && found_date[3] > '2') || found_date[4] > '9' || found_date[5] != '.' || found_date[6] < '0' || found_date[6] > '9' || found_date[7] < '0' || found_date[7] > '9' || found_date[8] < '0' || found_date[8] > '9' || found_date[9] < '0' || found_date[9] > '9');
    } while (found_date.length() != 10);
    puts("Введите адрес компании:");
    cin >> address;
    clean();
    return Company(name, found_date, address);
}

Soldier InputSoldier() { // ввод солдата 
    int LEN = Soldier::LEN;
    int Date = Soldier::Date;
    string name;
    string draft_date;
    string address;

    puts("Введите Фамилия И.О. солдата:");
    cin >> name;
    clean();
    do {
        do {
            puts("Введите дату призыва солдата в формате ДД.ММ.ГГГГ:");
            cin >> draft_date;
        } while (draft_date[0] < '0' || draft_date[0] > '3' || draft_date[1] < '0' || (draft_date[1] > '1' && draft_date[0] > '2') || draft_date[1] > '9' || draft_date[2] != '.' || draft_date[3] < '0' || (draft_date[3] == '1' && draft_date[4] > '2') || draft_date[3] > '1' || draft_date[4] < '0' || (draft_date[4] > '0' && draft_date[3] > '2') || draft_date[4] > '9' || draft_date[5] != '.' || draft_date[6] < '0' || draft_date[6] > '9' || draft_date[7] < '0' || draft_date[7] > '9' || draft_date[8] < '0' || draft_date[8] > '9' || draft_date[9] < '0' || draft_date[9] > '9');
    } while (draft_date.length() != 10);
    puts("Введите адрес прописки солдата:");
    cin >> address;
    clean();
    return Soldier(name, draft_date, address);
}

Weapon InputWeapon(Company company) { // ввод оружия
    int LEN = Weapon::LEN;
    int Date = Weapon::Date;
    int rel_year;
    string name;

    puts("Введите модель оружия:");
    cin >> name;
    clean();
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
    string operation;
    string date;

    do {
        puts("Введите тип совершённой операции (Выдача/Сдача):");
        cin >> operation;
        clean();
    } while ((operation != "Выдача") && (operation != "Сдача"));
    puts("Введите дату совершения операции в формате ДД.ММ.ГГГГ:");
    cin >> date;
    clean();
    return Control(operation, date, weapon, soldier);
}

Armory InputArmory(Weapon weapon, Soldier soldier, Control operation) { // ввод оружейного склада
    int LEN = Armory::LEN;
    int Date = Armory::Date;
    string military;

    puts("Введите номер ячейки склада (Н-р: ячейка А3):");
    cin >> military;
    clean();
    return Armory(weapon, soldier, operation, military);
}