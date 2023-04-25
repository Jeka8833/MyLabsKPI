//
// Created by Jeka8833 on 10.04.2023.
//

#include "PR5.h"

#include "tree.cpp"
#include "../Util.h"

using namespace std;


void PR5::run() {
    srand(time(nullptr));

    auto *chTree = new tree<wchar_t>;
    for (int i = 0; i < 10; ++i) {
        chTree->stree(chTree->root, NULL, true, L'a' + rand() % 26);
    }

    Util::print(L"Tree: ");
    printOrder(chTree->root);
    Util::println(L"");

    Util::println(L"Print tree:");
    chTree->print_tree(chTree->root, 0);

    wchar_t char_ = Util::printAndRead(L"Search char: ")[0];
    int i = 0;
    int pos = searchOrder(chTree->root, char_, &i);
    if (pos == -1) {
        Util::println(L"Not found");
    } else {
        Util::println(L"Position: " + to_wstring(pos));
    }
}

wstring PR5::getName() {
    return L"Практикум №5. Робота з бінарними деревами.";
}

void PR5::printOrder(tree<wchar_t> *tree) {
    if (tree == nullptr) return;

    printOrder(tree->left);

    std::wcout << tree->info;

    printOrder(tree->right);
}

int PR5::searchOrder(tree<wchar_t> *tree, wchar_t search, int *index) {
    if (tree == nullptr) return -1;

    int left = searchOrder(tree->left, search, index);
    if (left != -1) return left;

    (*index)++;

    if (tree->info == search) return *index;

    int right = searchOrder(tree->right, search, index);
    if (right != -1) return right;

    return -1;
}
