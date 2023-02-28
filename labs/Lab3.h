//
// Created by Jeka8833 on 26.02.2021.
//

#ifndef TESTPROJECT_LAB3_H
#define TESTPROJECT_LAB3_H


#include "../Task.h"

class Lab3 : public Task{
    void run() override;
    wstring getName() override;

private:
    int static fac(int i);
};


#endif //TESTPROJECT_LAB3_H
