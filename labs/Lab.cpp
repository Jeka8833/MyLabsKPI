//
// Created by Jeka8833 on 13.02.2021.
//

#include "Lab.h"
#include "Lab2.h"
#include "../Util.h"

int Lab::arraySize = 1;
Lab *Lab::labList[] = {new Lab2()};

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
