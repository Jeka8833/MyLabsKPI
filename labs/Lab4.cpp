//
// Created by Jeka8833 on 26.02.2021.
//

#include <cmath>
#include <cfloat>
#include "Lab4.h"
#include "../Util.h"

void Lab4::run() {
    float x = -FLT_MAX;
    float res = -FLT_MAX;
    while (true) {
        Util::println(L"");
        Util::println(L"1. Введення даних");
        Util::println(L"2. Розрахунок");
        Util::println(L"3. Відображення результатів розрахунку");
        Util::println(L"4. Вихід з програми");
        switch (Util::getIntAndCheckRange(L"\nВведи номер запускаемого пункта: ", L"Попробуй ещё раз", 1, 4)) {
            case 1:
                x = Util::printAndReadFloatError(L"Введите x: ", L"Попробуй ещё раз", true);
                Util::println(L"Удачно");
                break;
            case 2:
                if (x == -FLT_MAX) {
                    Util::println(L"Введите сначала данные");
                    continue;
                }
                res = calc(x);
                Util::println(L"Удачно");
                break;
            case 3:
                if (x == -FLT_MAX) {
                    Util::println(L"Введите сначала данные");
                    continue;
                }
                if (res == -FLT_MAX) {
                    Util::println(L"Сначала посчитайте");
                    continue;
                }
                Util::println(L"Результат: " + to_wstring(res));
                break;
            case 4:
                return;
        }
        if (Util::errorCode == EXIT) {
            break;
        }
    }
}

wstring Lab4::getName() {
    return L"Лабораторна робота #4 (Тема: Умовний оператор в С)";
}

float Lab4::calc(float value) {
    if (value <= 0)
        return sin(value) - sin(value / 2);
    return sin(value * value * value) - sin(value);
}
