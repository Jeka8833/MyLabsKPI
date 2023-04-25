//
// Created by Jeka8833 on 10.04.2023.
//

#ifndef TESTPROJECT_PR5_H
#define TESTPROJECT_PR5_H


#include "../Task.h"
#include "tree.h"

class PR5 : public Task {
public:

    void printOrder(tree<wchar_t> *tree);
    int searchOrder(tree<wchar_t> *tree, wchar_t search, int *index);

    void run() override;

    wstring getName() override;
};


#endif //TESTPROJECT_PR5_H
