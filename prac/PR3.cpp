//
// Created by Jeka8833 on 27.03.2023.
//

#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>
#include "PR3.h"
#include "../Util.h"

void PR3::run() {
    auto *list = new LinkedList<Row>();

    std::ifstream infile(R"(C:\Users\Jeka8833\CLionProjects\MyLabsKPI\DP0102)");
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);

        auto *newElement = new PR3::Row;
        if (!(iss >> newElement->x >> newElement->y)) { break; } // error

        list->add(newElement);
    }

    list->print();
    list->addMiddle();
    Util::println(L"");
    Util::println(L"");
    list->print();
    Util::println(L"");
    Util::println(L"");
    for (int i = 0; i < 5;) {
        double value = Util::printAndReadFloat(to_wstring(i) + L": Value to delete: ");

        if (!list->remove(value, 0.0001)) {
            Util::println(L"The current value isn't in the list, try another one");
            continue;
        }

        i++;
    }
    Util::println(L"");
    Util::println(L"");
    list->print();
}

wstring PR3::getName() {
    return L"Практикум №3. Робота зі списками. Динамічна зміна розмірів списків.";
}

template<class T>
void PR3::LinkedList<T>::print() {
    if (begin == nullptr) return;

    Util::println(L"    X        Y");
    Element<Row> *currentPosition = begin;
    while (currentPosition != nullptr) {
        const Row *row = currentPosition->data;

        Util::println(to_wstring(row->x) + L" " + to_wstring(row->y));

        currentPosition = currentPosition->next;
    }
}

template<class T>
void PR3::LinkedList<T>::addMiddle() {
    if (begin == nullptr) return;

    Element<Row> *currentPosition = begin;
    while (currentPosition->next != nullptr) {
        Element<Row> *nextPosition = currentPosition->next;

        const Row *current = currentPosition->data;
        const Row *next = nextPosition->data;

        auto *newElement = new PR3::Row;
        newElement->x = (current->x + next->x) / 2;
        newElement->y = (current->y + next->y) / 2;

        addNext(newElement, currentPosition);

        currentPosition = nextPosition;
    }
}

template<class T>
bool PR3::LinkedList<T>::remove(double value, double error) {
    if (begin == nullptr) return false;

    if (abs(begin->data->x - value) < error || abs(begin->data->y - value) < error) {
        if (begin->next == nullptr) {
            begin = nullptr;
            end = nullptr;
        } else {
            begin = begin->next;
        }
        return true;
    }

    Element<Row> *currentPosition = begin;
    while (currentPosition->next != nullptr) {
        Element<Row> *nextPosition = currentPosition->next;
        const Row *next = nextPosition->data;

        if (abs(next->x - value) < error || abs(next->y - value) < error) {
            currentPosition->next = nextPosition->next;

            if (currentPosition->next == nullptr) end = currentPosition;

            return true;
        }
        currentPosition = nextPosition;
    }
    return false;
}

template<class T>
void PR3::LinkedList<T>::addNext(T *element, PR3::Element<T> *position) {
    auto *newElement = new PR3::Element<T>;
    newElement->data = element;
    newElement->next = position->next;

    position->next = newElement;

    if (newElement->next == nullptr) end = newElement;
}

template<class T>
void PR3::LinkedList<T>::add(T *element) {
    auto *newElement = new PR3::Element<T>;
    newElement->data = element;

    if (begin == nullptr || end == nullptr) {
        begin = newElement;
    } else {
        end->next = newElement;
    }
    end = newElement;
}