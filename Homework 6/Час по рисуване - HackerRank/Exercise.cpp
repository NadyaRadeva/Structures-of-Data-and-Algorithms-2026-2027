#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> leftChild(n);
    vector<int> rightChild(n);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> leftChild[i] >> rightChild[i];

        if (leftChild[i] != -1) {
            parent[leftChild[i]] = i;
        }

        if (rightChild[i] != -1) {
            parent[rightChild[i]] = i;
        }
    }

    vector<int> order;
    vector<int> st;

    st.push_back(0);

    while (!st.empty()) {
        int v = st.back();
        st.pop_back();

        order.push_back(v);

        if (leftChild[v] != -1) {
            st.push_back(leftChild[v]);
        }

        if (rightChild[v] != -1) {
            st.push_back(rightChild[v]);
        }
    }

    vector<long long> subtreeSize(n, 1);

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int v = order[i];

        if (parent[v] != -1) {
            subtreeSize[parent[v]] += subtreeSize[v];
        }
    }

    long long maxResult = 0;

    for (int v = 0; v < n; v++) {
        long long product = 1;

        if (leftChild[v] != -1) {
            product *= subtreeSize[leftChild[v]];
        }

        if (rightChild[v] != -1) {
            product *= subtreeSize[rightChild[v]];
        }

        if (parent[v] != -1) {
            product *= n - subtreeSize[v];
        }

        if (product > maxResult) {
            maxResult = product;
        }
    }

    cout << maxResult << endl;

    return 0;
}
