#pragma once
#include <iostream>
#include <vector>
#include <algorithm>  // ��� std::sort
#include <cassert>    // ��� assert

// ��������� ���������� (��� �� ����������� �������)
template <typename T>
class TournamentSort {
public:
    void sort(std::vector<T>& arr) {
        int n = arr.size();
        if (n <= 1) return;  // ���� � ������� ������ 2 ���������, ����������� �� �����

        PriorityQueue<T> pq;

        // ��������� ������� ����������� ���������� �������
        for (const T& elem : arr) {
            pq.push(elem);
        }

        // ��������� �������� � ��������������� �������
        for (int i = 0; i < n; ++i) {
            arr[i] = pq.top();  // ��������� ����������� �������
            pq.pop();           // ������� ����������� �������
        }
    }
};

// ������������ ���������� � �������������� assert
void testTournamentSort() {
    // �������� ������
    std::vector<int> arr = { 10, -1, 2, 5, 4, 3, 8, 6, 7, 0 };

    // �������� ������ ��� ��������� ����������
    std::vector<int> arrCopy = arr;

    // ��������� ��������� ������ � �������������� ����������� ������� std::sort
    std::sort(arrCopy.begin(), arrCopy.end());

    // ��������� �������� ������ � ������� ��������� ����������
    TournamentSort<int> sorter;
    sorter.sort(arr);

    // ���������� ��������� ��������� ���������� � ��������� �����������
    assert(arr == arrCopy && "������: ��������� ���������� �� ������������� ������ ���������!");

    std::cout << "���� ������� �������: ������ ������������ ���������." << std::endl;
}