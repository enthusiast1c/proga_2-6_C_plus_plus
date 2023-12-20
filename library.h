#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

// Классы
//Разумное использование абстрактного класса
class AbstractCompany {
public:
    virtual string GetName() = 0;
    virtual string GetDate() = 0;
    virtual string GetAddress() = 0;
    virtual void SetName(string name) = 0;
    virtual void SetDate(string found_date) = 0;
    virtual void SetAddress(string address) = 0;
};

//Разумное использование шаблона класса
template <class D>
class Company : AbstractCompany{
private:
    string name;
    D found_date;
    string address;
public:
    static const int LEN = 30;
    static const int Date = 11;
    Company() {//конструктор без параметров
    }
    Company(string name, D found_date, string address) { //конструктор с параметрами
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
    void SetName(string name) {
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
    class Company<string> company;
    static int getNumber() {
        return NumWeap;
    }
    //Перегрузка оператора
    void operator++() {
        NumWeap++;
    }
    void operator--() {
        NumWeap--;
    }
    Weapon() {
    }
    Weapon( Company<string> company) { //конструктор с одним параметром
        NumWeap++;
        this->rel_year = 2000;
        this->company = company;
    }
    Weapon(string name, Company<string> company, int rel_year) {//конструктор с параметрами
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
    string& GetName() {
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
    void SetCompany(Company<string> company) {
        this->company = company;
    }
    virtual void Output() {
        cout << "Название: " << this->name << "\n   Год выпуска: " << rel_year << "\n   Компания: " << company.GetName() << "\n   Дата основания: " << company.GetDate() << endl;
    }
};
int Weapon::NumWeap = 0;

//Производный класс от класса Weapon
//Модификатор  protected
class WeaponMode : protected Weapon {
private: 
    vector<string> mods;
    static int NumWeapMods;
public:
    //Вызов конструктора базового класса в производном классе
    WeaponMode(string name, Company<string> company, int rel_year, vector<string> mods) : Weapon(name, company, rel_year) {
        NumWeapMods++;
        this->mods = mods;
    }
    WeaponMode(string name, Company<string> company, int rel_year) : Weapon(name, company, rel_year) {
        NumWeapMods++;
        this->mods = mods;
    }
    WeaponMode() {
        NumWeapMods++;
    }
    void operator--() {
        NumWeapMods--;
    }
    //Перегрузка оператора присвоения
    WeaponMode& operator=(Weapon& weapon) {
        SetYear(weapon.GetYear());
        SetName(weapon.GetName());
        SetCompany(weapon.company);
        return *this;
    }
    void AddMode(string mode) {
        mods.push_back(mode);
    }
    void DeleteMode(int i) {
        for (i; i < mods.size() - 1; i++) {
            mods.at(i) = mods.at(i + 1);
        }
        mods.pop_back();
    }
    //Перегрузка метода базового класса
    void Output() {
        Weapon::Output();
        for (int i = 0; i < mods.size(); i++) {
            cout << "   Модификация <" << mods.at(i) << ">" << endl;
        }
    }
    static int GetCountMode() {
        return NumWeapMods;
    }
};
int WeaponMode::NumWeapMods = 0;

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
    //Перегрузка оператора
    Soldier operator++() {
        NumSold++;
    }
    Soldier() {
    }
    Soldier(string name) {//Инструкция throw
        this->name = name;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] >= '0' && name[i] <= '9') {
                throw invalid_argument("Неккоректный формат входных данных\n");
            }
        }
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
int Soldier::NumSold = 0;

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
    vector <WeaponMode> weaponmods;
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
    int GetNweapons() {
        return Nweapons;
    }
    int GetNsoldiers() {
        return Nsoldiers;
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
    void WeaponModeToArmory(WeaponMode weaponmode) {
        this->Nweapons += 1;
        this->weaponmods.push_back(weaponmode);
    }
    void operator+(Soldier& soldier) {
        this->Nsoldiers += 1;
        this->soldiers.push_back(soldier);
    }
    void operator+(Weapon& weapon) {
        this->Nweapons += 1;
        this->weapons.push_back(weapon);
    }
    void OutputArmory() {
        printf("\n\nСписок складского оружия:\nВсего на складе: |%d|\n",Weapon::getNumber() - WeaponMode::GetCountMode());
        for (int i = 0; i < Weapon::getNumber() - WeaponMode::GetCountMode(); i++) {
            cout << "|" << (i + 1) << "|";
            this->weapons.at(i).Output();
        }
        printf("\nСписок складской модификации:\nВсего на складе: |%d|\n", WeaponMode::GetCountMode());
        if (WeaponMode::GetCountMode() != 0) {
            for (int i = 0; i < WeaponMode::GetCountMode(); i++) {
                cout << "|" << (i + 1) << "|";
                this->weaponmods.at(i).Output();
            }
        }
        printf("\nСписок призванных солдат:\nВсего на складе: |%d|", Soldier::getNumber());
        for (int i = 0, j = 1; i < this->Nsoldiers; i++) {
            cout << "\n|" << j++ << "|ФИО: " << this->soldiers.at(i).GetName() << "\n   Дата призыва: " << this->soldiers.at(i).GetDate() + "\n   Прописка по адресу: " << this->soldiers.at(i).GetAddress();
        }
        printf("\n\nОперации на складе:\nВсего на складе: |%d|", Control::getNumber());
        for (int i = 0, j = 1; i < this->Noperations; i++) {
            cout << "\n|" << j++ << "|Оружие: " << this->operations.at(i).weapon.GetName() << "\n   Солдат: " << this->operations.at(i).soldier.GetName() << "\n   Дата операции: " << this->operations.at(i).GetDate() << "\n   Вид операции: " << this->operations.at(i).GetOperation();
        }
        puts("");
    }
};

//Разумное использование дружественной функции
class OrderingOperations {
private:
    vector<Control> operations;
    //Дружественная функция для сортировки дат операций на складе
    friend void ArmoryToOrder(const Armory& operation, OrderingOperations& operations);
    void Sort() {
        int flag;
        Control temp;
        char* str1 = (char*)calloc(20, sizeof(char));
        char* str2 = (char*)calloc(20, sizeof(char));
        for (int k = 0; k < operations.size() - 1; k++) {
            for (int i = 0; i < operations.size() - 1; i++) {
                flag = 1;
                strcpy(str1, operations.at(i).GetDate().c_str());
                strcpy(str2, operations.at(i + 1).GetDate().c_str());
                for (int j = 6; j <= 9 && flag == 1; j++) {
                    if (str2[j] > str1[j]) {
                        flag = 0;
                    }
                    if (str2[j] < str1[j]) {
                        flag = 2;
                    }
                }
                for (int j = 3; j <= 4 && flag == 1; j++) {
                    if (str2[j] > str1[j]) {
                        flag = 0;
                    }
                    if (str2[j] < str1[j]) {
                        flag = 2;
                    }
                }
                for (int j = 0; j <= 1 && flag == 1; j++) {
                    if (str2[j] > str1[j]) {
                        flag = 0;
                    }
                    if (str2[j] < str1[j]) {
                        flag = 2;
                    }
                }
                if (flag == 2) {
                    temp = operations.at(i);
                    operations.at(i) = operations.at(i + 1);
                    operations.at(i + 1) = temp;
                }
            }
        }
    }
public:
    OrderingOperations() {
    }
    void OutputOrder() {
        for (int i = 0; i < operations.size(); i++) {
            cout << "|" << i + 1 << "|" << "Тип операции: " << operations.at(i).GetOperation() << " Дата операции: " << operations.at(i).GetDate() << " Солдат: " << operations.at(i).soldier.GetName() << " Оружие: " << operations.at(i).weapon.GetName() << "\n";
        }
        operations.clear();
        puts("Нажмите ENTER для возвращения в меню.");
    }
};

// Реализация дружественной функции
void ArmoryToOrder(const Armory& source, OrderingOperations& destination) {
    for (int i = 0; i < source.operations.size(); i++) {
        destination.operations.push_back(source.operations.at(i));
    }
    destination.Sort();
}

//Работа с двумерным массивом
class Platoon {
private:
    int Ntroop;
    string index;
    vector<int>NumSoldOfTroop;
    vector<vector<Soldier>> soldiers;
    void SetIndex(string index) {
        this->index = index;
    }
public:
    Platoon() {
        string index;
        system("cls");
        puts("Введите обозначение взвода:");
        cin >> index;
        SetIndex(index);
    }
    ~Platoon() {}
    void AddSoldier(int id, Soldier soldier) {
        if (soldiers.size() == id) {
            vector<Soldier> sold;
            sold.push_back(soldier);
            soldiers.push_back(sold);
        }
        else {
            soldiers.at(id).push_back(soldier);
        }
    }
    int GetNtroop() {
        return soldiers.size();
    }
    int GetSize(int i) {
        return soldiers.at(i).size();
    }
    string GetIndex() {
        return index;
    }
    void OutputPlatoon() {
        cout << "Взвод <<" << this->GetIndex() << ">>\n";
        for (int i = 0; i < soldiers.size(); i++) {
            cout << "\n\nВ (" << i + 1 << ") роте прикомандированы следующие солдаты:";
            for (int j = 0; j < soldiers.at(i).size(); j++) {
                cout << "\n|" << j + 1 << "|ФИО: " << this->soldiers.at(i).at(j).GetName() << "\n   Дата призыва: " << this->soldiers.at(i).at(j).GetDate() + "\n   Прописка по адресу: " << this->soldiers.at(i).at(j).GetAddress();
            }
        }
    }
};

void clean()  //Очистка потока
{
    while (getchar() != '\n');
}

// Основные функции.Ввод классов
Company<string> InputCompany() {// ввод компании
    int LEN = Company<string>::LEN;
    int Date = Company<string>::Date;
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
    return Company<string>(name, found_date, address);
}

Soldier InputSoldier() { // ввод солдата 
    int LEN = Soldier::LEN;
    int Date = Soldier::Date;
    string name;
    string draft_date;
    string address;

    puts("Введите Фамилию солдата:");
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

Weapon InputWeapon(Company<string> company) { // ввод оружия
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