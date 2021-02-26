//
// Created by Jeka8833 on 26.02.2021.
//

#include <ctime>
#include "Lab5.h"
#include "../Util.h"

void Lab5::run() {
    srand(time(nullptr));
    unsigned int array[20];
    for (unsigned int &i : array) {
        i = rand() % 100;
    }

    Util::print(L"Сгенерированный массив: [");
    for (int i = 0; i < 20; i++) {
        Util::print(to_wstring(array[i]));
        if (i < 20 - 1)
            Util::print(L", ");
    }
    Util::println(L"]");

    Util::print(L"Является квадратом 3: [");
    for (int i = 0; i < 20; i++) {
        if (array[i] != 9) continue;
        Util::print(to_wstring(array[i]) + L" ");
    }
    Util::println(L"]");

    Util::print(L"Является квадратом 5: [");
    for (int i = 0; i < 20; i++) {
        if (array[i] != 25) continue;
        Util::print(to_wstring(array[i]) + L" ");
    }
    Util::println(L"]");

    Util::print(L"Является квадратом 9: [");
    for (int i = 0; i < 20; i++) {
        if (array[i] != 81) continue;
        Util::print(to_wstring(array[i]) + L" ");
    }
    Util::println(L"]");
}

wstring Lab5::getName() {
    return L"Лабораторна робота #5 (Тема: Одновимірні масиви в С)";
}
