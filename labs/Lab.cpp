//
// Created by Jeka8833 on 13.02.2021.
//

#include "Lab.h"
#include "Lab2.h"
#include "../Util.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"

int Lab::arraySize = 5;
Lab *Lab::labList[] = {new Lab2(), new Lab3(), new Lab4(), new Lab5(), new Lab6()};

void Lab::run(int index) {
    while (true) {
        try {
            Util::println(L"");
            Util::println(L"============================================");
            Util::println(L"Запуск: " + labList[index]->getName());
            Util::println(L"============================================");
            Util::println(L"");
            labList[index]->run();

            if (!Util::equalsIgnoreCase(Util::printAndRead(L"Выполнить снова [yes, no]: "), L"yes")) {
                if (Util::errorCode == EXIT)
                    exit(0);
                return;
            }
        } catch (...) {
            Util::println(L"Ошибка выполнения...");
        }
    }
}

void Lab::printList() {
    for (int i = 0; i < arraySize; i++)
        Util::println(to_wstring(i + 1) + L": " + labList[i]->getName());
}
