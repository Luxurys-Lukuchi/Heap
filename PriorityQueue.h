#pragma once
// Шаблонный класс для приоритетной очереди на базе MinHeap
template <typename T>
class PriorityQueue {
private:
    MinHeap<T> heap;  // Используем MinHeap для хранения данных

public:
    // Вставка элемента в очередь приоритетов
    // Сложность: O(log n)
    void push(const T& value) {
        heap.insert(value);  // Вставляем элемент в кучу
    }

    // Извлечение элемента с наивысшим приоритетом (минимального)
    // Сложность: O(log n)
    void pop() {
        heap.removeMin();  // Удаляем элемент с наивысшим приоритетом
    }

    // Получение элемента с наивысшим приоритетом (минимального)
    // Сложность: O(1)
    T top() const {
        return heap.top();  // Возвращаем элемент с наивысшим приоритетом
    }

    // Проверка, пустая ли очередь
    // Сложность: O(1)
    bool empty() const {
        return heap.empty();
    }

    // Возвращаем размер очереди
    // Сложность: O(1)
    int size() const {
        return heap.size();
    }
};