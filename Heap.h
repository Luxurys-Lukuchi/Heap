#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> 
#include <cassert>
// ��������� ����� MinHeap (����������� ����)
// ��� �������� �������� ��������� � ��������������� ���������� O(log n),
// ��� ��� ������� ���� �������������� ������� �� ����� ���������.
template <typename T>
class MinHeap {
private:
    std::vector<T> heap;  // ������ ��� �������� ��������� ����

    // ���������� ������� ����� �� ���� ��� �������������� ������� ����
    // ���������: O(log n)
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // ���������� ������� ���� �� ���� ��� �������������� ������� ����
    // ���������: O(log n)
    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        // �������� ������������ ������� � ������������ ��� � ���������
        if (leftChild < size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // ���� ����������, ���������� ����� � ���������� �������� ������� ����
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // ���������� ������ �������� ��������
    int parent(int index) const { return (index - 1) / 2; }

    // ���������� ������ ������ ������� ��������
    int left(int index) const { return 2 * index + 1; }

    // ���������� ������ ������� ������� ��������
    int right(int index) const { return 2 * index + 2; }

    // ���������� ���������� ��������� � ����
    int size() const { return heap.size(); }

    // ���������, ������ �� ����
    bool empty() const { return heap.empty(); }

    // ���������� ����������� ������� (�������� ����)
    // ���������: O(1)
    T top() const {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // ������� ������ �������� � ����
    // ���������: O(log n)
    void insert(T value) {
        heap.push_back(value);      // ��������� ������� � ����� �������
        heapifyUp(size() - 1);      // ��������������� �������� ���� (���������� ������� �����)
    }

    // �������� ������������ �������� (�������� ����)
    // ���������: O(log n)
    void removeMin() {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();      // �������� ������ ��������� ���������
        heap.pop_back();            // ������� ��������� �������
        heapifyDown(0);             // ��������������� �������� ���� (���������� ������� ����)
    }

    // ������������� ������ � ����������� ������� ����
    std::vector<T>& getHeap() {
        return heap;
    }

    // ������������� ������ � ����������� ������� ���� ������ ��� ������
    const std::vector<T>& getHeap() const {
        return heap;
    }
};

// ��������� ����� MaxHeap (������������ ����)
template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;  // ������ ��� �������� ��������� ����

    // ���������� ������� ����� �� ���� ��� �������������� ������� ����
    // ���������: O(log n)
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // ���������� ������� ���� �� ���� ��� �������������� ������� ����
    // ���������: O(log n)
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
    // ���������� ������ �������� ��������
    int parent(int index) const { return (index - 1) / 2; }

    // ���������� ������ ������ ������� ��������
    int left(int index) const { return 2 * index + 1; }

    // ���������� ������ ������� ������� ��������
    int right(int index) const { return 2 * index + 2; }

    // ���������� ���������� ��������� � ����
    int size() const { return heap.size(); }

    // ���������, ������ �� ����
    bool empty() const { return heap.empty(); }

    // ���������� ������������ ������� (�������� ����)
    // ���������: O(1)
    T top() const {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // ������� ������ �������� � ����
    // ���������: O(log n)
    void insert(T value) {
        heap.push_back(value);  // ��������� ������� � ����� �������
        heapifyUp(size() - 1);  // ��������������� �������� ����
    }

    // �������� ������������� �������� (�������� ����)
    // ���������: O(log n)
    void removeMax() {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        heap[0] = heap.back();  // �������� ������ ��������� ���������
        heap.pop_back();        // ������� ��������� �������
        heapifyDown(0);         // ��������������� �������� ����
    }

    // ������������� ������ � ����������� ������� ���� ��� ������/������
    // ���������: O(1)
    std::vector<T>& getHeap() {
        return heap;
    }

    // ������������� ������ � ����������� ������� ���� ������ ��� ������
    // ���������: O(1)
    const std::vector<T>& getHeap() const {
        return heap;
    }

    // ������� ��� ��������, �������� �� ������ ������������ �����
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

    // ��������, ��� ������ ������������� ��������� ����������� ����
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

    // ��������� �������� � ����
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(1);

    const std::vector<int>& heapData = maxHeap.getHeap();

    // ��������, ��� ������ ������������� ��������� ������������ ����
    assert(std::is_heap(heapData.begin(), heapData.end()) == true); // ��� max-���� ������������ std::is_heap ��� �����������

    // ���������, ��� ������� ������� ���� - ��� ������������ �������
    assert(maxHeap.top() == 20);

    // ������� ������������ ������� � ��������� ����� ������� �������
    maxHeap.removeMax();
    assert(maxHeap.top() == 10);

    const std::vector<int>& heapDataAfterRemove = maxHeap.getHeap();
    // ���������, ��� ������ ������������� ��������� ������������ ���� ����� ��������
    assert(std::is_heap(heapDataAfterRemove.begin(), heapDataAfterRemove.end()) == true);

    std::cout << "MaxHeap tests passed!" << std::endl;
}   

// ������� ���������� � �������������� ���� (heap sort)
template <typename T>
void heapSortMin(std::vector<T>& arr) {
    MinHeap<T> heap;

    // ���������� ���� �� ���� ��������� �������
    for (const T& elem : arr) {
        heap.insert(elem);
    }

    // ���������� ��������� �� ���� ������� � ������ (� ��������������� �������)
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = heap.top();
        heap.removeMin();
    }
}

// ������� ���������� � �������������� ������������ ���� (heap sort)
template <typename T>
void heapSortMax(std::vector<T>& arr) {
    MaxHeap<T> heap;

    // ���������� ���� �� ���� ��������� �������
    for (const T& elem : arr) {
        heap.insert(elem);
    }

    // ���������� ��������� �� ���� ������� � ������
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = heap.top();  // ��������� ������������ �������
        heap.removeMax();      // ������� ������������ ������� �� ����
    }
}

// ������������ ����������
void testHeapSort() {
    // ���� ��� MinHeap
    std::vector<int> arrMin = { 5, 3, 8, 1, 2 };
    heapSortMin(arrMin);
    assert(arrMin == std::vector<int>({ 1, 2, 3, 5, 8 })); // ���������, ��� ������ ������������
    // ���� ��� MinHeap
    std::vector<int> arrMin1 = { 1, 2, 3, 5, 8 };
    heapSortMin(arrMin1);
    assert(arrMin1 == std::vector<int>({ 1, 2, 3, 5, 8 })); // ���������, ��� ������ ������������

    // ���� ��� MinHeap
    std::vector<int> arrMin2 = { 8, 5, 3, 2, 1 };
    heapSortMin(arrMin2);
    assert(arrMin2 == std::vector<int>({ 1, 2, 3, 5, 8 })); // ���������, ��� ������ ������������

    //// ���� ��� MaxHeap
    //std::vector<int> arrMax = { 5, 3, 8, 1, 2 };
    //heapSortMax(arrMax);
    //assert(arrMax == std::vector<int>({ 8, 5, 3, 2, 1 })); // ���������, ��� ������ ������������ 
    std::cout << "��� ����� �������� �������!" << std::endl;
}
