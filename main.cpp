#include "Util.h"
#include "labs/Lab.h"
#include "labs/Lab2.h"

#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>

int arraySize = 1;
Lab *labList[] = {new Lab2()};

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    while (true) {
        Util::println(
                L"Список всех лабораторных(Пожалуйста напишите номер лабораторной работы которую хотите запустить):");
        for (int i = 0; i < arraySize; i++)
            Util::println(to_wstring(i + 1) + L": " + labList[i]->getName());

        Util::println(L"");
        int number = Util::printAndReadIntError(
                L"Напишите 'exit' для выхода из программы\n"
                "Введите номер лабораторной работы за списком (1-" + to_wstring(arraySize) + L"):",
                L"Попробуй ещё раз ввести число\n",
                true);

        if (Util::errorCode == EXIT) {
            return 0;
        }
        if (number < 1 || number > arraySize) {
            Util::println(L"Умный чтоль или слишком умный...");
            Util::println(L"\n");
            continue;
        }
        Lab::run(number - 1);
    }
}