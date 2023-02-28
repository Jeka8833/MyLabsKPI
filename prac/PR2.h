//
// Created by Jeka8833 on 27.02.2023.
//

#ifndef TESTPROJECT_PR2_H
#define TESTPROJECT_PR2_H


#include "../Task.h"

class PR2 : public Task {
    void run() override;

    wstring getName() override;

private:
    static void insertionSort(int a[], int N, bool inversion);
    static int binarySearch(const int mas[], int search_key, int size, bool inversion);
};


#endif //TESTPROJECT_PR2_H
