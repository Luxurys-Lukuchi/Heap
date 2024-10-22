#pragma once
#include <iostream>
#include <vector>
#include <algorithm>  // Для std::sort
#include <cassert>    // Для assert

// Турнирная сортировка (код из предыдущего примера)
template <typename T>
class TournamentSort {
public:
    void sort(std::vector<T>& arr) {
        int n = arr.size();
        if (n <= 1) return;  // Если в массиве меньше 2 элементов, сортировать не нужно

        PriorityQueue<T> pq;

        // Заполняем очередь приоритетов элементами массива
        for (const T& elem : arr) {
            pq.push(elem);
        }

        // Извлекаем элементы в отсортированном порядке
        for (int i = 0; i < n; ++i) {
            arr[i] = pq.top();  // Извлекаем минимальный элемент
            pq.pop();           // Удаляем минимальный элемент
        }
    }
};

// Тестирование сортировки с использованием assert
void testTournamentSort() {
    // Исходный массив
    std::vector<int> arr = { 10, -1, 2, 5, 4, 3, 8, 6, 7, 0 };

    // Копируем массив для эталонной сортировки
    std::vector<int> arrCopy = arr;

    // Сортируем эталонный массив с использованием стандартной функции std::sort
    std::sort(arrCopy.begin(), arrCopy.end());

    // Сортируем исходный массив с помощью турнирной сортировки
    TournamentSort<int> sorter;
    sorter.sort(arr);

    // Сравниваем результат турнирной сортировки с эталонным результатом
    assert(arr == arrCopy && "Ошибка: Турнирная сортировка не отсортировала массив корректно!");

    std::cout << "Тест пройден успешно: массив отсортирован правильно." << std::endl;
}