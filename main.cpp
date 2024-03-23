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
    for (int n = 0; n < (u.countPasses("pass.txt") - 1); ++n) //öèêë çàãðóçêè õåø-òàáëèöû
    {
        u.add(u.getpasstext(n), u.getIDtext(n));
    }
    //u.show(); 
    /* Âûâîä õåø-òàáëèöû íà ýêðàí. Äëÿ òåñòèðîâàíèÿ ïðîãðàììû âûçîâ ôóíêöèè ðàñêîììåíòèðîâàòü,
    â ðàáî÷åì ðåæèìå - óäàëèòü */

    bool repeat{ true };
    while (true)
    {
        std::cout << '\n';
        int Num = u.find();
        int Num_pers = p.getID();
        if (Num_pers == Num)
        {
            std::cout << '\n';
            std::cout << "ÄÎÑÒÓÏ ÐÀÇÐÅØÅÍ. ÊÀÊÓÞ ÎÏÅÐÀÖÈÞ ÂÛ ÕÎÒÈÒÅ ÂÛÏÎËÍÈÒÜ?" << '\n';
            std::cout << '\n';
            std::cout << "Ïðîñìîòðåòü ñïèñîê êîíòàêòîâ - 1;" << '\n';
            std::cout << "Óäàëèòü ñâîè äàííûå èç ñïèñêà - 2;" << '\n';
            int ax{};
            std::cout << '\n';
            std::cout << "Ââåäèòå êîä îïåðàöèè: ";
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
            std::cout << "ÏÀÐÎËÜ ÈËÈ ËÎÃÈÍ ÍÅÂÅÐÍÛ, ËÈÁÎ ÏÎËÜÇÎÂÀÒÅËÜ ÓÄÀËÅÍ. " << '\n';
            std::cout << "Â ÄÎÑÒÓÏÅ ÎÒÊÀÇÀÍÎ, ÏÐÎÉÄÈÒÅ ÐÅÃÈÑÒÐÀÖÈÞ: " << '\n';
            std::cout << '\n';
            while (true)
            {
                int z{};
                std::cout << "ÐÅÃÈÑÒÐÀÖÈß ÏÎËÜÇÎÂÀÒÅËß. Äîáàâèòü - 1, âûõîä - 0" << '\n';
                std::cin >> z;
                if (z != 1) break;
                std::string passw;
                int ID = countNumber();
                std::cout << ID << '\n';
                std::cout << '\n';
                try_again:
                try_2:
                std::cout << "Ââåäèòå ïàðîëü: ";
                std::cin >> passw;
                for (size_t i = 0; i < passw.size(); i++)
                {
                    if (static_cast<unsigned char>(passw[i]) >= 35 && static_cast<unsigned char>(passw[i]) <= 125)
                    {
                        continue;
                    }
                    else
                    {
                        std::cout << "Íåâåðíûå ñèìâîëû! Âêëþ÷èòå ëàòèíñêóþ ðàñêëàäêó êëàâèàòóðû! " << '\n';
                        goto try_2;
                    }
                }
                 if (size(passw) < 8)
                 {
                     std::cout << "Ïàðîëü äîëæåí ñîñòîÿòü íå ìåíåå ÷åì èç 8 ñèìâîëîâ! " << '\n';
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
        std::cout << "Ïîâòîðèòü? Äà - 1, íåò - 0" << '\n';
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


