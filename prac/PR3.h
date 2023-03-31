//
// Created by Jeka8833 on 27.03.2023.
//

#ifndef TESTPROJECT_PR3_H
#define TESTPROJECT_PR3_H


#include "../Task.h"

class PR3 : public Task {
public:
    void run() override;

    wstring getName() override;

private:
    struct Row {
        double x;
        double y;
    };

    template<class T>
    struct Element {
        T *data = nullptr;
        Element *next = nullptr;
    };

    template<class T>
    class LinkedList {
    public:
        Element<T> *begin;
        Element<T> *end;

        void add(T *element);

        void addNext(T *element, Element<T> *position);

        void addMiddle();

        bool remove(double value, double error);

        void print();
    };
};

#endif //TESTPROJECT_PR3_H
