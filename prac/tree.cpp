//
// Created by Jeka8833 on 24.04.2023.
//

#include "tree.h"

//реалізація функції, що будує дерево
template<class T>
void tree<T>::stree(tree<T> *r, tree<T> *previous, bool sortInverse, T info) {
    if (!r) {
        r = new tree<T>; //виділення пам’яті під елемент дерева
        if (!r)//якщо не вдалося виділити пам’ять під елемент
        {
            std::cout << "Out of memory." << std::endl;//повідомляємо про це

            exit(1);//і виходимо з процедури
        }
//ініціалізуємо елемент
        r->left = NULL;
        r->right = NULL;
        r->info = info;
        if (!root) //якщо треба робимо його коренем дерева
        {
            root = r;
        } else//в противному випадку робимо його звичайним вузлом
        {
            if ((info < previous->info) ^ sortInverse) //якщо елемент менший за попередній, то
            {
                previous->left = r;//переходимо до лівої гілки
            } else {
                previous->right = r;//інакше до правого
            }
        }
        return;
    }//коли дійшли до потрібного термінального листа, то розміщуємо елемент.
    if ((info < r->info) ^ sortInverse) // Якщо елемент менший за попередній, то
    {
        stree(r->left, r, sortInverse, info); //розміщуємо його в лівому листі
    } else {
        stree(r->right, r, sortInverse, info); // інакше розміщуємо його в правому листі
    }
    return;
};

//реалізація процедури відображення дерева
//відображуємо відповідно до порядку послідовного проходження дерева
template<class T>
void tree<T>::print_tree(tree<T> *r, int l) {
    int i;
    if (!r) {
        return; //якщо нема батьківського вузла, то це корінь і процедуру закінчено
    }
    print_tree(r->right, l + 1); //друкуємо елементи правої гілки
    for (i = 0; i < l; ++i) {
        std::wcout << " ";
    }
    std::wcout << r->info << std::endl;
    print_tree(r->left, l + 1); //друкуємо елементи лівої гілки
}

//реалізація процедури пошуку елемента
template<class T>
tree<T> *tree<T>::search_tree(tree<T> *r, T key) {
    if (!r) {
        return r; //якщо нема батьківського вузла, то це корінь і процедуру закінчено
    }
//перевіряємо елементи дерева поки не знайдемо шукане
//або не досягнемо кінця
    while (r->info != key) {
        if (key < r->info) {
            r = r->left; //перевіряємо елементи лівої гілки
        } else {
            r = r->right; //перевіряємо елементи правої гілки
            if (r == NULL) { break; }
        }
    }
    return r;
}