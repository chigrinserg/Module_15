#include <iostream>
#include <fstream>
#include "Number.h"

int countNumber() //�������-�������
{
    int countNumber{};
    std::ifstream in("Numbers.txt"); // �������� ���� ��� ������
    if (in.is_open())
    {
        in >> countNumber;
    }
    in.close();     // ��������� ����
    ++countNumber;
    std::ofstream out;          // ����� ��� ������
    out.open("Numbers.txt");      // ��������� ���� ��� ������
    if (out.is_open())
    {
        out << countNumber << std::endl;
    }
    out.close();
    return countNumber;
}
