#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <ios>
#include "Number.h"
#include "Person.h"
#include "Users.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Users u;
    Person p;
    for (int n = 0; n < (u.countPasses("pass.txt") - 1); ++n) //���� �������� ���-�������
    {
        u.add(u.getpasstext(n), u.getIDtext(n));
    }
    //u.show(); 
    /* ����� ���-������� �� �����. ��� ������������ ��������� ����� ������� �����������������,
    � ������� ������ - ������� */

    bool repeat{ true };
    while (true)
    {
        std::cout << '\n';
        int Num = u.find();
        int Num_pers = p.getID();
        if (Num_pers == Num)
        {
            std::cout << '\n';
            std::cout << "������ ��������. ����� �������� �� ������ ���������?" << '\n';
            std::cout << '\n';
            std::cout << "����������� ������ ��������� - 1;" << '\n';
            std::cout << "������� ���� ������ �� ������ - 2;" << '\n';
            int ax{};
            std::cout << '\n';
            std::cout << "������� ��� ��������: ";
            std::cin >> ax;
            std::cout << '\n';
            switch (ax)
            {
            case 1:
                p.Get_records_in_file("listOfUsers.txt");
                p.getListUsers();
                break;
            case 2:
                int del_p = u.del();
                p.deletePerson(del_p);
                p.DeleteEmptyLines();
                u.deep_pass();
                u.deep_id();
                break;
            }
        }
        else
        {
            std::cout << '\n';
            std::cout << "������ ��� ����� �������, ���� ������������ ������. " << '\n';
            std::cout << "� ������� ��������, �������� �����������: " << '\n';
            std::cout << '\n';
            while (true)
            {
                int z{};
                std::cout << "����������� ������������. �������� - 1, ����� - 0" << '\n';
                std::cin >> z;
                if (z != 1) break;
                std::string passw;
                int ID = countNumber();
                std::cout << ID << '\n';
                std::cout << '\n';
                try_again:
                try_2:
                std::cout << "������� ������: ";
                std::cin >> passw;
                for (size_t i = 0; i < passw.size(); i++)
                {
                    if (static_cast<unsigned char>(passw[i]) >= 35 && static_cast<unsigned char>(passw[i]) <= 125)
                    {
                        continue;
                    }
                    else
                    {
                        std::cout << "�������� �������! �������� ��������� ��������� ����������! " << '\n';
                        goto try_2;
                    }
                }
                 if (size(passw) < 8)
                 {
                     std::cout << "������ ������ �������� �� ����� ��� �� 8 ��������! " << '\n';
                     goto try_again;
                 }
                u.add(passw, ID);
                std::cout << '\n';
                p.fillArray(ID);
            }
            p.DeleteEmptyLines();
            u.deep_pass();
            u.deep_id();
        }
        int z{};
        std::cout << '\n';
        std::cout << "���������? �� - 1, ��� - 0" << '\n';
        std::cin >> z;
        if (z == 1)
        {
            repeat = true;
        }
        else
        {
            repeat = false;
            break;
        }
        system("cls");
    }
    return 0;
}


