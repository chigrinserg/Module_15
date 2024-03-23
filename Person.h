#pragma once
#include <iostream>
#include "Number.h"

class Person
{
private:
    int _ID{};
    std::string _log_in;
    std::string _family; //фамилия
    std::string _name; //имя
    std::string _surname; //отчество
    std::string _phone; //телефон

public:
    Person() {}; // конструктор по умолчанию
    Person(int ID, std::string log_in, std::string family, std::string name, std::string surname, std::string phone)
    {
        _ID = ID;
        _log_in = log_in;
        _family = family;
        _name = name;
        _surname = surname;
        _phone = phone;
    }
    void setPerson_inMass(int ID);
    void getPersons();
    void fillArray(int ID);
    int Get_records_in_file(const std::string name_file);
    void getListUsers();
    int getID();
    void deletePerson(int del_p);
    void DeleteEmptyLines();
    Person& operator = (const Person& other)  //  оператор присваивания
    {
        _ID = other._ID;
        _log_in = other._log_in;
        _family = other._family;
        _name = other._name;
        _surname = other._surname;
        _phone = other._phone;
        return *this;
    }
    friend std::ostream& operator<< (std::ostream& out, const Person& p);
    friend std::istream& operator>> (std::istream& in, Person& p);
};
