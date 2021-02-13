//
// Created by Jeka8833 on 13.02.2021.
//

#include "Lab2.h"
#include "../Util.h"

#include <cfloat>

void Lab2::run() {
    int m1 = Util::getIntAndCheckRange(
            L"Введите массу первого тела(0-" + to_wstring(INT_MAX / 2) + L"): ", L"Давай попробуем снова...", 0,
            INT_MAX / 2);
    if (Util::errorCode == EXIT)
        return;
    int m2 = Util::getIntAndCheckRange(
            L"Введите массу второго тела(0-" + to_wstring(INT_MAX / 2) + L"): ", L"Давай попробуем снова...", 0,
            INT_MAX / 2);
    if (Util::errorCode == EXIT)
        return;
    int r = Util::getIntAndCheckRange(L"Введите расстояние между телами(0-" + to_wstring(INT_MAX / 2) + L"): ",
                                      L"Давай попробуем снова...", 0, INT_MAX / 2);
    if (Util::errorCode == EXIT)
        return;
    float g = Util::getFloatAndCheckRange(L"Введите гравитационную постоянную(0-....): ",
                                          L"Давай попробуем снова...", 0,
                                          FLT_MAX);
    if (Util::errorCode == EXIT)
        return;
    float out = ((g * (m1 + m2)) / (r * r));
    Util::println(L"Ответ: F=" + to_wstring(out) + L"H");
}

wstring Lab2::getName() {
    return L"Лабораторна робота #2 (Тема: Структура програми в С. Оператори вводу та виводу інформації в С.)";
}
