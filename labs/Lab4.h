//
// Created by Jeka8833 on 26.02.2021.
//

#ifndef TESTPROJECT_LAB4_H
#define TESTPROJECT_LAB4_H


#include "Lab.h"

class Lab4  : public Lab{
    void run() override;
    wstring getName() override;

private:
    static float calc(float value);
};


#endif //TESTPROJECT_LAB4_H
