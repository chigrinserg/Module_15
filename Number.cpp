#include <iostream>
#include <fstream>
#include "Number.h"

int countNumber() //функция-счетчик
{
    int countNumber{};
    std::ifstream in("Numbers.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        in >> countNumber;
    }
    in.close();     // закрываем файл
    ++countNumber;
    std::ofstream out;          // поток для записи
    out.open("Numbers.txt");      // открываем файл для записи
    if (out.is_open())
    {
        out << countNumber << std::endl;
    }
    out.close();
    return countNumber;
}
