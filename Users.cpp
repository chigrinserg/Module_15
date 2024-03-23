#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <fstream>
#include "Users.h"

std::ostream& operator<< (std::ostream& out, const Users::HashPerson& hp)
{
    out << hp.password << ", " << hp.ID << ", " << hp.status;
    return out;
}

bool operator== (const Users::HashPerson& hp1, const Users::HashPerson& hp2)
{
    return (hp1.password == hp2.password);
}

Users::Users() //конструктор с выделением памяти под массив
{
    count = 0;
    mem_size = 20;
    array = new HashPerson[mem_size];
}
Users::~Users() //деструктор
{
    delete[] array;
}


int Users::hash_func(std::string passw, int offset)  // хеш-функция
{
    int sum = 0;
    for (int i=0; i < passw.size(); i++) 
    {
        sum += passw[i];
    }
    // квадратичные пробы
    return (sum % mem_size + offset * offset) % mem_size;
}

void Users::add(const std::string passw, int ID) //Основная функция загрузки данных в хеш-таблицу
{
    int index = -1;
    int i = 0;
    for (; i < mem_size; i++) // берем пробы по всем i от 0 до размера массива
    {
        index = hash_func(passw, i);
        if (array[index].status != PersonStatus::engaged)
        {
            break;
        }
    }
    if (i >= mem_size)
    {
        int new_size = 2 * mem_size;
        resize(new_size);
        add(passw, ID);
    }
    else
    {
        array[index] = HashPerson(passw, ID);  // кладем в свободную ячейку пару
        count++;
    }
}

void Users::deep_pass() //сохранение в текстовый файл паролей
{
    std::ofstream out("pass.txt"); //сохраняем массив в текстовый файл
    for (int i = 0; i < mem_size; ++i)
    {
        if (array[i].status != PersonStatus::deleted && array[i].password != "*")
        {
            out << array[i].password << '\n';
        }
    }
}

void Users::deep_id() //сохранение в текстовый файл личных номеров
{
    std::ofstream out("id.txt"); 
    for (int i = 0; i < mem_size; ++i)
    {
        if (array[i].status != PersonStatus::deleted && array[i].ID != -1)
        {
            out << array[i].ID << '\n';
        }
    }
    std::cout << '\n';
}

int sizemass = 0;
std::vector<std::string> arr_pass(sizemass); //массив паролей
std::vector<int> arr_id(sizemass); //массив личных номеров

std::string Users::getpasstext(int n) //функция извлечения из файла списка паролей для загрузки хеш-таблицы
{
    std::string line;
    std::ifstream in("pass.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            arr_pass.push_back(line);
            ++sizemass;
        }
    }
    in.close();     // закрываем файл
    return arr_pass[n];
}

int Users::countPasses(const std::string name_file) //подсчет числа строк в файле 
{
    int numPasses = 0;
    std::ifstream input_file("pass.txt");
    std::string s;
    while (!input_file.eof())
    {
        std::getline(input_file, s);
        ++numPasses;
    }
    input_file.close();
    return numPasses;
}

int Users::getIDtext(int n) //функция извлечения из файла личных номеров для загрузки хеш-таблицы при запуске программы
{
    std::string id{};
    std::ifstream in("id.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, id))
        {
            arr_id.push_back(stoi(id)); //загрузка в массив номеров с преобразованием строки в int
            ++sizemass;
        }
    }
    in.close();     // закрываем файл
    if (arr_id[n] != 0)
    {
        return arr_id[n];
    }
}

void Users::show() //вывод хеш-таблицы на экран
{
    for (int i = 0; i < mem_size; ++i)
    {
        if (array[i].status != PersonStatus::deleted)
        {
            std::cout << i << ". \t" << array[i].password << "\t" << array[i].ID << "\t" << array[i].status;
            std::cout << '\n';
        }
    }
}

void Users::resize(int new_size) //изменение размера хеш-таблицы
{
    HashPerson* array_temp = new HashPerson[new_size];
    std::cout << '\n';
    std::swap(array, array_temp);
    mem_size = new_size;
    count = 0;
    for (int i = 0; i < mem_size / 2; ++i)
    {
        if (array[i].status != PersonStatus::deleted)
        {
            add(array_temp[i].password, array_temp[i].ID);
        }
    }
    delete[] array_temp;
    array_temp = array;
}

int Users::find() //поиск ID пользователя в хеш-таблице по паролю
{
    std::string passw;
    std::cout << "Введите пароль: ";
    std::cin >> passw;
    int index = -1;
    for (int i = 0; i < mem_size; i++)
    {
        int index = hash_func(passw, i);

        if (array[index].password.compare(passw) == 0)
        {
            return array[index].ID;
        }
    }
    return -2;
}

int Users::del() //Удаление данных пользователя из хеш-таблицы. Возврат ID пользователя из списка
{
    std::string pas;
    std::cout << "Удаление персонаьных данных. Введите пароль: ";
    std::cin >> pas;
    for (int i=0; i < mem_size; ++i) 
    {
        //i = hash_func(pas, i);
        if (array[i].password.compare(pas) == 0)
        {
            int zx{};
            std::cout << "Вы действительно хотите удалить свои данные?"<<'\n';
            std::cout << "Отмена операции будет невозможна! " << '\n';
            std::cout<<"Да - 1, нет - 0" << '\n';
            std::cin >> zx;
            if (zx == 1)
            {
                array[i].status = PersonStatus::deleted;
                --count;
            }
        }
        if (array[i].password.compare(pas) == 0)
        {
            return array[i].ID;
        }
    }
}

