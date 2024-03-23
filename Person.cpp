#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ios>
#include <iomanip>
#include <stdio.h>
#include "Person.h"

void Person::setPerson_inMass(int ID)
{
    _ID = ID;
    std::cout << "�����: ";
    std::cin >> _log_in;
    std::cout << "�������: ";
    std::cin >> _family; //�������
    std::cout << "���: ";
    std::cin >> _name; //���
    std::cout << "��������: ";
    std::cin >> _surname; //��������
    std::cout << "�������: ";
    std::cin >> _phone;
}


void Person::getPersons()
{
    std::cout << _ID << "  ";
    std::cout << _log_in << "   ";
    std::cout <<_family << "   ";
    std::cout << _name << "   ";
    std::cout << _surname << "   ";
    std::cout << _phone;
    std::cout << '\n';
}

std::ostream& operator<< (std::ostream& out, const Person& p)
{
    out << p._ID <<" "<< p._log_in <<" "<< p._family <<" "<< p._name << " " << p._surname <<" "<< p._phone;
    return out;
}

std::istream& operator>> (std::istream& in, Person& p)
{
    in >> p._ID;
    in >> p._log_in;
    in >> p._family;
    in >> p._name;
    in >> p._surname;
    in >> p._phone;
    return in;
}

int size = 1;
std::vector<Person> _array(size); //������ ������ �������������
Person p;

void Person::fillArray(int ID) //������� �������� ������ �������������
{
    std::cout << "���������� � ������� ���� �����. ������� ������ ������ � �������: " << '\n';
    for (int i = 0; i < size; ++i)
    {
        _array[i].setPerson_inMass(ID);
    }
    for (int i = 0; i < size; ++i) //������� ��������� ������ �� �������
    {
        _array[i].getPersons();
    }
    std::ofstream out("listOfUsers.txt", std::ios::app); //��������� ������ � ��������� ����
    for (int i = 0; i < size; ++i)
    {
        out << _array[i]<<'\n';
    }
    out.close();
}

int Person::Get_records_in_file(const std::string name_file) //������� ����� ����� � ����� ������ �������������
{
    int count = 0;
    std::ifstream input_file("listOfUsers.txt");
    std::string s;
    while (!input_file.eof())
    {
        std::getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void Person::getListUsers() //������� ���������� �� ����� ������ �������������
{
    std::cout << "������ ��������� ��������� (���������� ���������� ��������� ������������): " << '\n';
    std::cout << '\n';
    std::vector<Person> _array(Person::Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> _array[i];
    }
    input_file.close();
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
         _array[i].getPersons();
    }
}

void Person::deletePerson(int del_p) // ������� �������� ������������.
{
    std::vector<Person> _array(Person::Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i) 
    {
        input_file >> _array[i];
        if (_array[i]._ID == del_p)
        {
            _array[i] = { -1,"------","------","------","------","------" }; //������ ���������� ���������� ����� ���������
        }
    }
    std::cout << '\n';
    std::ofstream out("listOfUsers.txt"); //���������� ������ ������� � ����
    for (int i = 0; i < (std::end(_array)-std::begin(_array)); ++i)
    {
        out << _array[i] << '\n';
    }
    out.close();
}

int Person::getID() //��������� �� ���������� ����� ������� ������, ���������������� ������
{
    std::string str;
    std::cout << "������� �����: ";
    std::cin >> str;
    std::vector<Person> _array(Person::Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> _array[i];
    }
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        if ((_array[i]._log_in).compare(str) == 0)
        {
            return _array[i]._ID;
        }
    }
    return -1;
}

void Person::DeleteEmptyLines() //�������� ������ ����� �� ����� �������
{
    std::ifstream in("listOfUsers.txt");
    std::string line, text;
    while (std::getline(in, line))
        if (!(line.empty() || line.find_first_not_of(' ') == std::string::npos))
        {
            text += line + "\n";
        }
    in.close();
    std::ofstream out("listOfUsers.txt");
    out << text;
}


