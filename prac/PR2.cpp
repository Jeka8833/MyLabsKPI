//
// Created by Jeka8833 on 27.02.2023.
//

#include "PR2.h"
#include "../Util.h"

void PR2::run() {
    srand(time(nullptr));

    int *array;
    int count = Util::getIntAndCheckRange(L"Count values (0-" + to_wstring(INT_MAX / 2) + L"): ",
                                          L"Давай попробуем снова...", 0,
                                          INT_MAX / 2);
    if (Util::errorCode == EXIT) return;

    array = new int[count];
    for (int i = 0; i < count; ++i) {
        array[i] = rand() % 100;
    }

    Util::print(L"Сгенерированный массив: [");
    for (int i = 0; i < count; i++) {
        Util::print(to_wstring(array[i]));
        if (i < count - 1)
            Util::print(L", ");
    }
    Util::println(L"]");

    bool inversion = Util::equalsIgnoreCase(Util::printAndRead(L"Inversion(T, F): "), L"T");
    if (Util::errorCode == EXIT) return;

    insertionSort(array, count, inversion);

    Util::print(L"Sorted array: [");
    for (int i = 0; i < count; i++) {
        Util::print(to_wstring(array[i]));
        if (i < count - 1)
            Util::print(L", ");
    }
    Util::println(L"]");

    int queueSize = Util::getIntAndCheckRange(L"Queue length: ", L"Давай попробуем снова...", 1,
                                              INT_MAX / 2);
    if (Util::errorCode == EXIT) return;
    int queue[queueSize];
    for (int i = 0; i < queueSize; i++) {
        queue[i] = Util::getIntAndCheckRange(L"Item " + to_wstring(i) + L": ", L"Давай попробуем снова...", 0,
                                             99);
        if (Util::errorCode == EXIT) return;
    }

    for (int i = 0; i < queueSize; i++) {
        int position = binarySearch(array, queue[i], count, inversion);

        Util::println(L"Number " + to_wstring(queue[i]) + L" contained in position " +
                      (position == -1 ? L"None" : to_wstring(position)));
    }
}

wstring PR2::getName() {
    return L"Практикум №2 Робота з масивами та списками. Методи сортування та пошуку.";
}

void PR2::insertionSort(int a[], int N, bool inversion) {
    for (int i = 0; i < N; i++) {
        int X = a[i];
        int j = i - 1;
        if (inversion) {
            for (; j >= 0 && a[j] < X; --j)
                a[j + 1] = a[j];
        } else {
            for (; j >= 0 && a[j] > X; --j)
                a[j + 1] = a[j];
        }
        a[j + 1] = X;
    }
}

int PR2::binarySearch(const int mas[], int search_key, int size, bool inversion) {
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (inversion) {
            if (search_key > mas[mid]) {
                high = mid - 1;
            } else {
                if (search_key < mas[mid]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            }
        } else {
            if (search_key < mas[mid]) {
                high = mid - 1;
            } else {
                if (search_key > mas[mid]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            }
        }
    }
    return -1;
}
