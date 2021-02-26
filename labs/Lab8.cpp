//
// Created by Jeka8833 on 27.02.2021.
//

#include <fstream>
#include <sstream>
#include "Lab8.h"
#include "../Util.h"

void Lab8::run() {
    std::wifstream t("in.txt");
    if (t) {
        std::wstringstream buffer;
        buffer << t.rdbuf();
        Util::println(L"Входной файл: " + buffer.str());
        wstring out = buffer.str().substr(buffer.str().size() / 2, buffer.str().size()) +
                      buffer.str().substr(0, buffer.str().size() / 2);
        Util::println(L"Выходной файл: " + out);
        std::wofstream outfile("out.txt");
        outfile << out;
        outfile.close();
    } else {
        bool state = Util::equalsIgnoreCase(
                Util::printAndRead(L"Файл ненайден, вы хотите создать новый? [true, false]: "), L"true");
        if (state) {
            std::ofstream outfile("in.txt");
            outfile.close();
            Util::println(L"Файл создан");
        }
    }

}

wstring Lab8::getName() {
    return L"Лабораторна робота #8 (Тема: Робота з файлами в С)";
}
