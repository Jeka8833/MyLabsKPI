//
// Created by Jeka8833 on 24.04.2023.
//

#ifndef TESTPROJECT_TREE_H
#define TESTPROJECT_TREE_H

#include <iostream>
#include <stdlib.h>

template <class T> class tree {
public:
    T info; //поле, що містить інформацію
    tree * left; //покажчик на лівий елемент ланки
    tree * right; //покажчик на правий елемент ланки

    tree * root;//покажчик на корінь дерева
    tree(){root=NULL;};//конструктор
//функція, що будує дерево
    void stree(tree<T> *r, tree<T> *previous, bool sortInverse, T info);
//функція, що відображає дерево на екрані
    void print_tree(tree *r, int l);
    //функція пошуку елемента дерева
    tree<T>  *search_tree(tree<T> *r, T key);
};


#endif //TESTPROJECT_TREE_H
