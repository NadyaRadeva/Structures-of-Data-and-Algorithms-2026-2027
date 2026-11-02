//  https://www.hackerrank.com/contests/sda-hw-3-2026/challenges/exam-5-1/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void add(Node*& head, Node*& tail, Node*& mid, int x, int& size) {
    Node* newNode = new Node(x);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        mid = newNode;

        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;

        if (size % 2 == 1) {
            mid = mid->next;
        }
    }

    ++size;
}

void gun(Node*& head, Node*& tail, Node*& mid, int& size) {
    if (size == 1) {
        delete head;

        head = nullptr;
        tail = nullptr;
        mid = nullptr;

        size = 0;
        return;
    }

    if (size % 2 == 0) {
        mid = mid->prev;
    }

    Node* temp = tail;

    tail = tail->prev;

    tail->next = head;
    head->prev = tail;

    delete temp;

    --size;
}

void milen(Node*& head, Node*& tail, Node*& mid, int size) {
    if (size < 2) {
        return;
    }

    Node* oldHead = head;
    Node* oldTail = tail;

    head = mid;

    tail = mid->prev;

    if (size % 2 == 0) {
        mid = oldHead;
    }
    else {
        mid = oldTail;
    }
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;

    int size = 0;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;

            add(head, tail, mid, x, size);
        }
        else if (command == "gun") {
            gun(head, tail, mid, size);
        }
        else if (command == "milen") {
            milen(head, tail, mid, size);
        }
    }

    cout << size << '\n';

    Node* current = head;

    for (int i = 0; i < size; ++i) {
        cout << current->data;

        if (i < size - 1) {
            cout << " ";
        }

        current = current->next;
    }

    cout << '\n';

    while (size > 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
    }

    return 0;
}
