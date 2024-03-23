#pragma once
#include <iostream>
#include <string>
#include "Number.h"


class Users //хеш-таблица
{
public:
    Users();
    ~Users();
    void add(const std::string passw, int ID);
    void show();
    int find();
    void resize(int new_size);
    int hash_func(std::string passw, int offset); //вставка: имя и шаг хеширования
    void deep_pass();
    void deep_id();
    std::string getpasstext(int n);
    int getIDtext(int n);
    int countPasses(const std::string name_file); //подсчет числа паролей в файле паролей
    int del(); //удаление пользователя
private:
    enum PersonStatus //перечисление статусов ячейки
    {
        free, //свободна
        engaged, //занята
        deleted //удалена
    };
    struct HashPerson  // пара ключ-значение,
    {
        std::string password; // пароль (ключ)
        int ID; // логин (значение)
        PersonStatus status; // состояние ячейки
        HashPerson():
            password("*"),
            ID(-1),
            status(PersonStatus::free){
        } // конструктор по умолчанию

        HashPerson(std::string passw, int ID) :  // конструктор копирования
            password(passw),
            ID(ID),
            status(PersonStatus::engaged) {
        }
        HashPerson& operator = (const HashPerson& other) { //  оператор присваивания
            password = other.password;
            ID = other.ID;
            status = other.status;
            return *this;
        }
    };
    HashPerson* array; //внутренний массив
    int mem_size; //размер массива
    int count;

    friend std::ostream& operator<< (std::ostream& out, const HashPerson& hp);
    friend std::istream& operator>> (std::istream& in, HashPerson& hp);
    friend bool operator== (const HashPerson& hp1, const HashPerson& hp2);
};


