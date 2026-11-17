#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int OFFSET = 200000;
const int SIZE = 400001;

struct Node {
    int val;
    int left;
    int right;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n);

    for (int i = 0; i < n; i++) {
        cin >> tree[i].val;
        cin >> tree[i].left;
        cin >> tree[i].right;
    }

    queue<int> q;
    queue<int> coordinates;

    long long sums[SIZE] = {};

    q.push(0);
    coordinates.push(0);

    while (!q.empty()) {

        int index = q.front();
        q.pop();

        int x = coordinates.front();
        coordinates.pop();

        sums[x + OFFSET] += tree[index].val;

        if (tree[index].left != -1) {
            q.push(tree[index].left);
            coordinates.push(x - 1);
        }

        if (tree[index].right != -1) {
            q.push(tree[index].right);
            coordinates.push(x + 1);
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (sums[i] != 0) {
            cout << sums[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
