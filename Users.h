#pragma once
#include <iostream>
#include <string>
#include "Number.h"


class Users //���-�������
{
public:
    Users();
    ~Users();
    void add(const std::string passw, int ID);
    void show();
    int find();
    void resize(int new_size);
    int hash_func(std::string passw, int offset); //�������: ��� � ��� �����������
    void deep_pass();
    void deep_id();
    std::string getpasstext(int n);
    int getIDtext(int n);
    int countPasses(const std::string name_file); //������� ����� ������� � ����� �������
    int del(); //�������� ������������
private:
    enum PersonStatus //������������ �������� ������
    {
        free, //��������
        engaged, //������
        deleted //�������
    };
    struct HashPerson  // ���� ����-��������,
    {
        std::string password; // ������ (����)
        int ID; // ����� (��������)
        PersonStatus status; // ��������� ������
        HashPerson():
            password("*"),
            ID(-1),
            status(PersonStatus::free){
        } // ����������� �� ���������

        HashPerson(std::string passw, int ID) :  // ����������� �����������
            password(passw),
            ID(ID),
            status(PersonStatus::engaged) {
        }
        HashPerson& operator = (const HashPerson& other) { //  �������� ������������
            password = other.password;
            ID = other.ID;
            status = other.status;
            return *this;
        }
    };
    HashPerson* array; //���������� ������
    int mem_size; //������ �������
    int count;

    friend std::ostream& operator<< (std::ostream& out, const HashPerson& hp);
    friend std::istream& operator>> (std::istream& in, HashPerson& hp);
    friend bool operator== (const HashPerson& hp1, const HashPerson& hp2);
};


