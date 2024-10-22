#pragma once
#include <iostream>
#include <vector>
#include <functional> // Для std::function

// Класс узла бинарного дерева
template <typename T>
class TreeNode {
public:
    T value;                // Значение узла
    TreeNode* left;        // Указатель на левое поддерево
    TreeNode* right;       // Указатель на правое поддерево

    // Конструктор
    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}

    // Конструктор копирования
    TreeNode(const TreeNode& other) : value(other.value), left(nullptr), right(nullptr) {
        if (other.left) {
            left = new TreeNode(*other.left);  // Рекурсивное копирование левого поддерева
        }
        if (other.right) {
            right = new TreeNode(*other.right); // Рекурсивное копирование правого поддерева
        }
    }

    // Оператор присваивания
    TreeNode& operator=(const TreeNode& other) {
        if (this != &other) { // Проверка самоприсваивания
            value = other.value;
            // Освобождаем память старых узлов
            delete left;
            delete right;
            left = nullptr;
            right = nullptr;
            if (other.left) {
                left = new TreeNode(*other.left); // Рекурсивное копирование
            }
            if (other.right) {
                right = new TreeNode(*other.right); // Рекурсивное копирование
            }
        }
        return *this;
    }

    // Деструктор
    ~TreeNode() {
        delete left;  // Освобождение памяти левого поддерева
        delete right; // Освобождение памяти правого поддерева
    }

    // Применить функцию ко всем узлам дерева
    void apply(const std::function<void(T&)>& func) {
        func(value); // Применяем функцию к текущему узлу
        if (left) left->apply(func);   // Рекурсивно применяем к левому поддереву
        if (right) right->apply(func); // Рекурсивно применяем к правому поддереву
    }

    // Удалить все узлы дерева
    void del_all() {
        delete this; // Удаление текущего узла (вызывает деструктор)
    }

    // Создать копию дерева
    TreeNode* copy() const {
        return new TreeNode(*this); // Возвращаем новый узел, скопированный из текущего
    }

    // Подсчитать количество узлов в дереве
    int count() const {
        int left_count = (left) ? left->count() : 0;   // Подсчитываем количество узлов в левом поддереве
        int right_count = (right) ? right->count() : 0; // Подсчитываем количество узлов в правом поддереве
        return 1 + left_count + right_count; // Возвращаем общее количество узлов
    }

    // Вычислить глубину дерева
    int depth() const {
        int left_depth = (left) ? left->depth() : 0;   // Вычисляем глубину левого поддерева
        int right_depth = (right) ? right->depth() : 0; // Вычисляем глубину правого поддерева
        return 1 + std::max(left_depth, right_depth); // Возвращаем максимальную глубину
    }

    // Вывод дерева (симметричный обход) LNR
    void print() const {
        if (left) left->print();              // Рекурсивно выводим левое поддерево
        std::cout << value << " ";            // Выводим значение текущего узла
        if (right) right->print();            // Рекурсивно выводим правое поддерево
    }
};

// Рекурсивная функция для построения бинарного дерева из массива, который представляет собой кучу
template <typename T>
TreeNode<T>* buildTreeFromHeap(const std::vector<T>& heap, int index = 0) {
    // Если индекс выходит за пределы массива, вернуть nullptr
    if (index >= heap.size()) {
        return nullptr;
    }

    // Создаем новый узел с текущим значением из массива
    TreeNode<T>* root = new TreeNode<T>(heap[index]);

    // Рекурсивно создаем левое и правое поддеревья
    root->left = buildTreeFromHeap(heap, 2 * index + 1);  // Левый потомок
    root->right = buildTreeFromHeap(heap, 2 * index + 2);  // Правый потомок

    return root;
}

// Оценка сложности:
// - Конструктор: O(1)
// - Конструктор копирования: O(n) (где n — количество узлов в дереве)
// - Оператор присваивания: O(n) (где n — количество узлов в дереве)
// - Деструктор: O(n) (где n — количество узлов в дереве)
// - Метод apply: O(n) (где n — количество узлов в дереве)
// - Метод del_all: O(1) (вызывается деструктор)
// - Метод copy: O(n) (где n — количество узлов в дереве)
// - Метод count: O(n) (где n — количество узлов в дереве)
// - Метод depth: O(n) (где n — количество узлов в дереве)
// - Метод print: O(n) (где n — количество узлов в дереве)
// - Функция buildTreeFromHeap: O(n) (где n — количество элементов в массиве)
