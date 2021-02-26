//
// Created by Jeka8833 on 26.02.2021.
//

#include <cmath>
#include <cfloat>
#include "Lab3.h"
#include "../Util.h"

void Lab3::run() {
    int e = INT_MIN;
    float x = -FLT_MAX;
    double res = -DBL_MAX;
    while (true) {
        Util::println(L"");
        Util::println(L"1. Введення даних");
        Util::println(L"2. Розрахунок");
        Util::println(L"3. Відображення результатів розрахунку");
        Util::println(L"4. Вихід з програми");
        switch (Util::getIntAndCheckRange(L"\nВведи номер запускаемого пункта: ", L"Попробуй ещё раз", 1, 4)) {
            case 1:
                e = Util::getIntAndCheckRange(L"Введите точность: ", L"Попробуй ещё раз", 1, 17);
                x = Util::getFloatAndCheckRange(L"Введите x: ", L"Попробуй ещё раз", -1, 1);
                Util::println(L"Удачно");
                break;
            case 2:
                if (e == INT_MIN || x == -FLT_MAX) {
                    Util::println(L"Введите сначала данные");
                    continue;
                }
                res = 0;
                for (int i = 0; i < e; i++) {
                    res += (((pow(-1, i) * ((x / 2) * (x / 2))) / (fac(i + 1) * fac(i + 1))));
                }
                Util::println(L"Удачно");
                break;
            case 3:
                if (e == INT_MIN || x == -FLT_MAX) {
                    Util::println(L"Введите сначала данные");
                    continue;
                }
                if (res == -DBL_MAX) {
                    Util::println(L"Сначала посчитайте");
                    continue;
                }
                wprintf((L"Результат: %." + to_wstring(e) + L"f\n").c_str(), res);
                break;
            case 4:
                return;
        }
        if (Util::errorCode == EXIT) {
            break;
        }
    }

}

wstring Lab3::getName() {
    return L"Оператори циклу в С.";
}

int Lab3::fac(int N) {
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fac(N - 1);
}
