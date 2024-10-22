#pragma once
#include <iostream>
#include <vector>
#include <functional> // ��� std::function

// ����� ���� ��������� ������
template <typename T>
class TreeNode {
public:
    T value;                // �������� ����
    TreeNode* left;        // ��������� �� ����� ���������
    TreeNode* right;       // ��������� �� ������ ���������

    // �����������
    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}

    // ����������� �����������
    TreeNode(const TreeNode& other) : value(other.value), left(nullptr), right(nullptr) {
        if (other.left) {
            left = new TreeNode(*other.left);  // ����������� ����������� ������ ���������
        }
        if (other.right) {
            right = new TreeNode(*other.right); // ����������� ����������� ������� ���������
        }
    }

    // �������� ������������
    TreeNode& operator=(const TreeNode& other) {
        if (this != &other) { // �������� ����������������
            value = other.value;
            // ����������� ������ ������ �����
            delete left;
            delete right;
            left = nullptr;
            right = nullptr;
            if (other.left) {
                left = new TreeNode(*other.left); // ����������� �����������
            }
            if (other.right) {
                right = new TreeNode(*other.right); // ����������� �����������
            }
        }
        return *this;
    }

    // ����������
    ~TreeNode() {
        delete left;  // ������������ ������ ������ ���������
        delete right; // ������������ ������ ������� ���������
    }

    // ��������� ������� �� ���� ����� ������
    void apply(const std::function<void(T&)>& func) {
        func(value); // ��������� ������� � �������� ����
        if (left) left->apply(func);   // ���������� ��������� � ������ ���������
        if (right) right->apply(func); // ���������� ��������� � ������� ���������
    }

    // ������� ��� ���� ������
    void del_all() {
        delete this; // �������� �������� ���� (�������� ����������)
    }

    // ������� ����� ������
    TreeNode* copy() const {
        return new TreeNode(*this); // ���������� ����� ����, ������������� �� ��������
    }

    // ���������� ���������� ����� � ������
    int count() const {
        int left_count = (left) ? left->count() : 0;   // ������������ ���������� ����� � ����� ���������
        int right_count = (right) ? right->count() : 0; // ������������ ���������� ����� � ������ ���������
        return 1 + left_count + right_count; // ���������� ����� ���������� �����
    }

    // ��������� ������� ������
    int depth() const {
        int left_depth = (left) ? left->depth() : 0;   // ��������� ������� ������ ���������
        int right_depth = (right) ? right->depth() : 0; // ��������� ������� ������� ���������
        return 1 + std::max(left_depth, right_depth); // ���������� ������������ �������
    }

    // ����� ������ (������������ �����) LNR
    void print() const {
        if (left) left->print();              // ���������� ������� ����� ���������
        std::cout << value << " ";            // ������� �������� �������� ����
        if (right) right->print();            // ���������� ������� ������ ���������
    }
};

// ����������� ������� ��� ���������� ��������� ������ �� �������, ������� ������������ ����� ����
template <typename T>
TreeNode<T>* buildTreeFromHeap(const std::vector<T>& heap, int index = 0) {
    // ���� ������ ������� �� ������� �������, ������� nullptr
    if (index >= heap.size()) {
        return nullptr;
    }

    // ������� ����� ���� � ������� ��������� �� �������
    TreeNode<T>* root = new TreeNode<T>(heap[index]);

    // ���������� ������� ����� � ������ ����������
    root->left = buildTreeFromHeap(heap, 2 * index + 1);  // ����� �������
    root->right = buildTreeFromHeap(heap, 2 * index + 2);  // ������ �������

    return root;
}

// ������ ���������:
// - �����������: O(1)
// - ����������� �����������: O(n) (��� n � ���������� ����� � ������)
// - �������� ������������: O(n) (��� n � ���������� ����� � ������)
// - ����������: O(n) (��� n � ���������� ����� � ������)
// - ����� apply: O(n) (��� n � ���������� ����� � ������)
// - ����� del_all: O(1) (���������� ����������)
// - ����� copy: O(n) (��� n � ���������� ����� � ������)
// - ����� count: O(n) (��� n � ���������� ����� � ������)
// - ����� depth: O(n) (��� n � ���������� ����� � ������)
// - ����� print: O(n) (��� n � ���������� ����� � ������)
// - ������� buildTreeFromHeap: O(n) (��� n � ���������� ��������� � �������)
