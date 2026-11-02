//  https://www.hackerrank.com/contests/sda-hw-3-2026/challenges/cache-8/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long MIN_N = 1;
long long MAX_N = 3000;
long long MIN_Q = 1;
long long MAX_Q = 200000;
long long MIN_K = 1;
long long MAX_K = 200000;
long long MIN_X = 0;
long long MAX_X = 10000;
long long MIN_Y = 0;
long long MAX_Y = 100000;
const long long MAX_KEY = 10000;

class Node {
public:
    long long key;
    long long value;
    Node* next;

    Node(long long key, long long value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

void putElementAtTheFront(
    Node*& head,
    Node*& tail,
    Node* newNode,
    Node* positions[],
    Node* previous[]
) {
    newNode->next = head;
    previous[newNode->key] = nullptr;

    if (head != nullptr) {
        previous[head->key] = newNode;
    }
    else {
        tail = newNode;
    }

    head = newNode;
    positions[newNode->key] = newNode;
}

void moveElementToFront(
    Node*& head,
    Node*& tail,
    Node* current,
    Node* positions[],
    Node* previous[]
) {
    if (current == head) {
        return;
    }

    Node* prev = previous[current->key];

    prev->next = current->next;

    if (current == tail) {
        tail = prev;
    }
    else {
        previous[current->next->key] = prev;
    }

    current->next = head;
    previous[current->key] = nullptr;
    previous[head->key] = current;

    head = current;
}

void removeLastElement(
    Node*& head,
    Node*& tail,
    long long& size,
    Node* positions[],
    Node* previous[]
) {
    if (tail == nullptr) {
        return;
    }

    Node* temp = tail;
    long long key = temp->key;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        tail = previous[key];
        tail->next = nullptr;
    }

    positions[key] = nullptr;
    previous[key] = nullptr;

    delete temp;
    --size;
}

void putElementInCache(
    Node*& head,
    Node*& tail,
    long long& size,
    long long key,
    long long value,
    Node* positions[],
    Node* previous[]
) {
    if (positions[key] != nullptr) {
        Node* current = positions[key];

        current->value = value;

        moveElementToFront(
            head, tail, current, positions, previous
        );
    }
    else {
        Node* newNode = new Node(key, value);

        putElementAtTheFront(
            head, tail, newNode, positions, previous
        );

        ++size;
    }
}

long long getElementFromCache(
    Node*& head,
    Node*& tail,
    long long key,
    Node* positions[],
    Node* previous[]
) {
    if (positions[key] == nullptr) {
        return -1;
    }

    Node* current = positions[key];

    long long result = current->value;

    moveElementToFront(
        head, tail, current, positions, previous
    );

    return result;
}

int main() {
    long long N, Q, K;

    cin >> N >> Q >> K;

    Node* head = nullptr;
    Node* tail = nullptr;

    long long size = 0;

    Node* positions[MAX_KEY + 1] = {};
    Node* previous[MAX_KEY + 1] = {};

    for (long long i = 1; i <= Q; ++i) {
        string command;
        cin >> command;

        if (command == "put") {
            long long x, y;
            cin >> x >> y;

            putElementInCache(
                head, tail, size, x, y,
                positions, previous
            );

            if (size > N) {
                removeLastElement(
                    head, tail, size,
                    positions, previous
                );
            }
        }
        else if (command == "get") {
            long long x;
            cin >> x;

            cout << getElementFromCache(
                head, tail, x, positions, previous
            ) << '\n';
        }

        if (i % K == 0) {
            removeLastElement(
                head, tail, size,
                positions, previous
            );
        }
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
