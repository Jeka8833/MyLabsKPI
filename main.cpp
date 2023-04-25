#include "Util.h"
#include "Task.h"
#include "prac/PR5.h"

#include <string>
#include <io.h>
#include <fcntl.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    while (true) {
        Util::println(
                L"Список всех лабораторных(Пожалуйста напишите номер лабораторной работы которую хотите запустить):");
        Task::printList();
        Util::println(L"");
        int number = Util::getIntAndCheckRange(
                L"Напишите 'exit' для выхода из программы\n"
                "Введите номер лабораторной работы за списком (1-" + to_wstring(Task::arraySize) + L"):",
                L"Попробуй ещё раз ввести число\n",
                1, Task::arraySize);

        if (Util::errorCode == EXIT) {
            return 0;
        }
        Task::run(number - 1);
    }
}