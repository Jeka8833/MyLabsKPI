//
// Created by Jeka8833 on 26.02.2021.
//

#include <ctime>
#include "Lab6.h"
#include "../Util.h"

void Lab6::run() {
    srand(time(nullptr));
    unsigned int array[5][5];
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            array[x][y] = rand() % 100;

    Util::println(L"Наш массив: ");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            Util::print(to_wstring(array[x][y]) + L" ");
        }
        Util::println(L"");
    }

    int remove = Util::getIntAndCheckRange(L"Введите номер колонки которую хотите удалить: ", L"Попробуй ещё раз", 1,
                                           5);

    unsigned int out[4][5];
    int realCount = 0;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (x + 1 == remove) continue;
            out[realCount++][y] = array[x][y];
        }
        realCount = 0;
    }

    Util::println(L"Результат: ");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 4; x++) {
            Util::print(to_wstring(out[x][y]) + L" ");
        }
        Util::println(L"");
    }
}

wstring Lab6::getName() {
    return L"Лабораторна робота #6 (Тема: Двовимірні масиви в С)";
}
