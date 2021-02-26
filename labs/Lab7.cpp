//
// Created by Jeka8833 on 26.02.2021.
//

#include "Lab7.h"
#include "../Util.h"

void Lab7::run() {
    wstring text = Util::printAndRead(L"Введите строку для изменения порядка: ");
    Util::println(L"Вывод: " + text.substr(text.size()/2, text.size()) + text.substr(0, text.size()/2));
}

wstring Lab7::getName() {
    return L"Лабораторна робота #7 (Тема: Обробка символьних і рядкових даних в С)";
}
