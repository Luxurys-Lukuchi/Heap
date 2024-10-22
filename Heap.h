#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> 
#include <cassert>
// Шаблонный класс MinHeap (минимальная куча)
// Все основные операции выполнены с логарифмической сложностью O(log n),
// так как глубина кучи логарифмически зависит от числа элементов.
template <typename T>
class MinHeap {
private:
    std::vector<T> heap;  // Вектор для хранения элементов кучи

    // Перемещает элемент вверх по куче для восстановления свойств кучи
    // Сложность: O(log n)
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Перемещает элемент вниз по куче для восстановления свойств кучи
    // Сложность: O(log n)
    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        // Выбираем минимального потомка и переставляем его с родителем
        if (leftChild < size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // Если необходимо, производим обмен и продолжаем опускать элемент вниз
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Возвращает индекс родителя элемента
    int parent(int index) const { return (index - 1) / 2; }

    // Возвращает индекс левого потомка элемента
    int left(int index) const { return 2 * index + 1; }

    // Возвращает индекс правого потомка элемента
    int right(int index) const { return 2 * index + 2; }

    // Возвращает количество элементов в куче
    int size() const { return heap.size(); }

    // Проверяет, пустая ли куча
    bool empty() const { return heap.empty(); }

    // Возвращает минимальный элемент (верхушку кучи)
    // Сложность: O(1)
    T top() const {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Вставка нового элемента в кучу
    // Сложность: O(log n)
    void insert(T value) {
        heap.push_back(value);      // Добавляем элемент в конец массива
        heapifyUp(size() - 1);      // Восстанавливаем свойства кучи (перемещаем элемент вверх)
    }

    // Удаление минимального элемента (верхушки кучи)
    // Сложность: O(log n)
    void removeMin() {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();      // Замещаем корень последним элементом
        heap.pop_back();            // Удаляем последний элемент
        heapifyDown(0);             // Восстанавливаем свойства кучи (перемещаем элемент вниз)
    }

    // Предоставляет доступ к внутреннему массиву кучи
    std::vector<T>& getHeap() {
        return heap;
    }

    // Предоставляет доступ к внутреннему массиву кучи только для чтения
    const std::vector<T>& getHeap() const {
        return heap;
    }
};

// Шаблонный класс MaxHeap (максимальная куча)
template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;  // Вектор для хранения элементов кучи

    // Перемещает элемент вверх по куче для восстановления свойств кучи
    // Сложность: O(log n)
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Перемещает элемент вниз по куче для восстановления свойств кучи
    // Сложность: O(log n)
    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int largest = index;

        if (leftChild < size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Возвращает индекс родителя элемента
    int parent(int index) const { return (index - 1) / 2; }

    // Возвращает индекс левого потомка элемента
    int left(int index) const { return 2 * index + 1; }

    // Возвращает индекс правого потомка элемента
    int right(int index) const { return 2 * index + 2; }

    // Возвращает количество элементов в куче
    int size() const { return heap.size(); }

    // Проверяет, пустая ли куча
    bool empty() const { return heap.empty(); }

    // Возвращает максимальный элемент (верхушку кучи)
    // Сложность: O(1)
    T top() const {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Вставка нового элемента в кучу
    // Сложность: O(log n)
    void insert(T value) {
        heap.push_back(value);  // Добавляем элемент в конец массива
        heapifyUp(size() - 1);  // Восстанавливаем свойства кучи
    }

    // Удаление максимального элемента (верхушки кучи)
    // Сложность: O(log n)
    void removeMax() {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();  // Замещаем корень последним элементом
        heap.pop_back();        // Удаляем последний элемент
        heapifyDown(0);         // Восстанавливаем свойства кучи
    }

    // Предоставляет доступ к внутреннему массиву кучи для чтения/записи
    // Сложность: O(1)
    std::vector<T>& getHeap() {
        return heap;
    }

    // Предоставляет доступ к внутреннему массиву кучи только для чтения
    // Сложность: O(1)
    const std::vector<T>& getHeap() const {
        return heap;
    }

    // Функция для проверки, является ли массив максимальной кучей
    template <typename T>
    bool isMaxHeap(const std::vector<T>& heap) {
        int n = heap.size();
        for (int i = 0; i < n / 2; ++i) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if (leftChild < n && heap[i] < heap[leftChild]) {
                return false;
            }
            if (rightChild < n && heap[i] < heap[rightChild]) {
                return false;
            }
        }
        return true;
    }

};

void testMinHeap() {
    MinHeap<int> minHeap;

    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(10);

    const std::vector<int>& heapData = minHeap.getHeap();

    // Проверка, что массив соответствует свойствам минимальной кучи
    assert(std::is_heap(heapData.begin(), heapData.end(), std::greater<int>()) == true);

    assert(minHeap.top() == 1);

    minHeap.removeMin();
    assert(minHeap.top() == 5);

    const std::vector<int>& heapDataAfterRemove = minHeap.getHeap();
    assert(std::is_heap(heapDataAfterRemove.begin(), heapDataAfterRemove.end(), std::greater<int>()) == true);

    std::cout << "MinHeap tests passed!" << std::endl;
}


void testMaxHeap() {
    MaxHeap<int> maxHeap;

    // Вставляем элементы в кучу
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(1);

    const std::vector<int>& heapData = maxHeap.getHeap();

    // Проверка, что массив соответствует свойствам максимальной кучи
    assert(std::is_heap(heapData.begin(), heapData.end()) == true); // Для max-кучи используется std::is_heap без компаратора

    // Проверяем, что верхний элемент кучи - это максимальный элемент
    assert(maxHeap.top() == 20);

    // Удаляем максимальный элемент и проверяем новый верхний элемент
    maxHeap.removeMax();
    assert(maxHeap.top() == 10);

    const std::vector<int>& heapDataAfterRemove = maxHeap.getHeap();
    // Проверяем, что массив соответствует свойствам максимальной кучи после удаления
    assert(std::is_heap(heapDataAfterRemove.begin(), heapDataAfterRemove.end()) == true);

    std::cout << "MaxHeap tests passed!" << std::endl;
}   

// Функция сортировки с использованием кучи (heap sort)
template <typename T>
void heapSortMin(std::vector<T>& arr) {
    MinHeap<T> heap;

    // Построение кучи из всех элементов массива
    for (const T& elem : arr) {
        heap.insert(elem);
    }

    // Извлечение элементов из кучи обратно в массив (в отсортированном порядке)
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = heap.top();
        heap.removeMin();
    }
}

// Функция сортировки с использованием максимальной кучи (heap sort)
template <typename T>
void heapSortMax(std::vector<T>& arr) {
    MaxHeap<T> heap;

    // Построение кучи из всех элементов массива
    for (const T& elem : arr) {
        heap.insert(elem);
    }

    // Извлечение элементов из кучи обратно в массив
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = heap.top();  // Сохраняем максимальный элемент
        heap.removeMax();      // Удаляем максимальный элемент из кучи
    }
}

// Тестирование сортировки
void testHeapSort() {
    // Тест для MinHeap
    std::vector<int> arrMin = { 5, 3, 8, 1, 2 };
    heapSortMin(arrMin);
    assert(arrMin == std::vector<int>({ 1, 2, 3, 5, 8 })); // Проверяем, что массив отсортирован
    // Тест для MinHeap
    std::vector<int> arrMin1 = { 1, 2, 3, 5, 8 };
    heapSortMin(arrMin1);
    assert(arrMin1 == std::vector<int>({ 1, 2, 3, 5, 8 })); // Проверяем, что массив отсортирован

    // Тест для MinHeap
    std::vector<int> arrMin2 = { 8, 5, 3, 2, 1 };
    heapSortMin(arrMin2);
    assert(arrMin2 == std::vector<int>({ 1, 2, 3, 5, 8 })); // Проверяем, что массив отсортирован

    //// Тест для MaxHeap
    //std::vector<int> arrMax = { 5, 3, 8, 1, 2 };
    //heapSortMax(arrMax);
    //assert(arrMax == std::vector<int>({ 8, 5, 3, 2, 1 })); // Проверяем, что массив отсортирован 
    std::cout << "Все тесты пройдены успешно!" << std::endl;
}
