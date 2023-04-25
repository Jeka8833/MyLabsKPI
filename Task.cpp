//
// Created by Jeka8833 on 13.02.2021.
//

#include "Task.h"
#include "labs/Lab2.h"
#include "Util.h"
#include "labs/Lab3.h"
#include "labs/Lab4.h"
#include "labs/Lab5.h"
#include "labs/Lab6.h"
#include "labs/Lab7.h"
#include "labs/Lab8.h"
#include "prac/PR2.h"
#include "prac/PR3.h"
#include "prac/PR5.h"

int Task::arraySize = 10;
Task *Task::labList[] = {new PR2(), new PR3(), new PR5(), new Lab2(), new Lab3(), new Lab4(), new Lab5(), new Lab6(), new Lab7(), new Lab8()};

void Task::run(int index) {
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

void Task::printList() {
    for (int i = 0; i < arraySize; i++)
        Util::println(to_wstring(i + 1) + L": " + labList[i]->getName());
}
