#pragma once
// ��������� ����� ��� ������������ ������� �� ���� MinHeap
template <typename T>
class PriorityQueue {
private:
    MinHeap<T> heap;  // ���������� MinHeap ��� �������� ������

public:
    // ������� �������� � ������� �����������
    // ���������: O(log n)
    void push(const T& value) {
        heap.insert(value);  // ��������� ������� � ����
    }

    // ���������� �������� � ��������� ����������� (������������)
    // ���������: O(log n)
    void pop() {
        heap.removeMin();  // ������� ������� � ��������� �����������
    }

    // ��������� �������� � ��������� ����������� (������������)
    // ���������: O(1)
    T top() const {
        return heap.top();  // ���������� ������� � ��������� �����������
    }

    // ��������, ������ �� �������
    // ���������: O(1)
    bool empty() const {
        return heap.empty();
    }

    // ���������� ������ �������
    // ���������: O(1)
    int size() const {
        return heap.size();
    }
};