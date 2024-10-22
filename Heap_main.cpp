// Heap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Heap.h"
#include "PriorityQueue.h"
#include "TreeNode.h"
#include "Tournament.h"

int main() {
    setlocale(LC_ALL, "Russian");
    testMinHeap();
    testMaxHeap();
    testHeapSort();
    testTournamentSort();
    testTournamentSort();

    // Пример 1: Построение дерева из кучи
    std::vector<int> heap = { 1, 3, 6, 5, 9, 8 };
    TreeNode<int>* root = buildTreeFromHeap(heap);

    // Вывод дерева
    std::cout << "Содержимое дерева (симметричный обход): ";
    root->print(); // Вывод дерева
    std::cout << std::endl;

    // Пример 2: Очередь приоритетов
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    std::cout << "Top of PriorityQueue: " << pq.top() << std::endl;  // Должен вывести 1
    pq.pop();
    std::cout << "Top after pop: " << pq.top() << std::endl;  // Должен вывести 5

    // Пример 3: Сортировка с использованием кучи
    std::vector<int> arr = { 4, 10, 3, 5, 1 };
    heapSortMin(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    root->del_all();

    return 0;


    //int n;
    //std::cout << "Введите количество элементов массива: ";
    //std::cin >> n;

    //std::vector<int> array(n);
    //std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел

    //// Повторяем сортировку 25 раз и измеряем среднее время
    //const int repetitions = 25;
    //double totalDuration = 0.0;

    //for (int r = 0; r < repetitions; ++r) {
    //    // Генерация случайных значений от -1000 до 1000
    //    for (int i = 0; i < n; ++i) {
    //        array[i] = std::rand() % 2001 - 1000; // Генерация числа от -1000 до 1000
    //    }

    //    // Измерение времени сортировки
    //    auto start = std::chrono::high_resolution_clock::now();
    //    heapSortMin(array);
    //    auto end = std::chrono::high_resolution_clock::now();

    //    // Суммируем время сортировки
    //    std::chrono::duration<double> duration = end - start;
    //    totalDuration += duration.count();
    //}

    //// Вычисление среднего времени
    //double averageDuration = totalDuration / repetitions;

    //// Вывод среднего времени сортировки
    //std::cout << "Среднее время сортировки за " << repetitions << " повторений: "
    //    << averageDuration << " секунд." << std::endl;

    //return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
