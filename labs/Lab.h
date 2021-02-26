//
// Created by Jeka8833 on 13.02.2021.
//

#ifndef TESTPROJECT_LAB_H
#define TESTPROJECT_LAB_H

#include <string>
#include <iostream>

using namespace std;

class Lab {
public:
    virtual void run() = 0;

    virtual wstring getName() = 0;

    static void printList();
    static void run(int index);

    static int arraySize;
    static Lab *labList[];
};


#endif //TESTPROJECT_LAB_H
