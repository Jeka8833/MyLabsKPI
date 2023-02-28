//
// Created by Jeka8833 on 13.02.2021.
//

#ifndef TESTPROJECT_TASK_H
#define TESTPROJECT_TASK_H

#include <string>
#include <iostream>

using namespace std;

class Task {
public:
    virtual void run() = 0;

    virtual wstring getName() = 0;

    static void printList();

    static void run(int index);

    static int arraySize;
    static Task *labList[];
};


#endif //TESTPROJECT_TASK_H
