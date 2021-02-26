//
// Created by Jeka8833 on 26.02.2021.
//

#ifndef TESTPROJECT_LAB3_H
#define TESTPROJECT_LAB3_H


#include "Lab.h"

class Lab3 : public Lab{
    void run() override;
    wstring getName() override;

private:
    int static fac(int i);
};


#endif //TESTPROJECT_LAB3_H
