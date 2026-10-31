#include <map>
#include<vector>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long MIN_N = 1;
long long MAX_N = 50000;
long long MIN_T = 1;
long long MAX_T = 50;
long long MIN_X = 2;
long long MAX_X = 1000000000 - 1;
long long MIN_Wi = 1;
long long MAX_Wi = 1000000000;

struct Box {
    int weight;
    int initialIndex;

    Box(int weight, int initialIndex) {
        this->weight = weight;
        this->initialIndex = initialIndex;
    }
};

bool operator<(const Box& lhs, const Box& rhs) {
    return lhs.weight < rhs.weight;
}

long long binarySearch(vector<Box>& W, long long el, long long start, long long end) {

    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (el == W[mid].weight) {
            return mid;
        }
        else if (el < W[mid].weight) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return -1;
}

void handleRequests(vector<Box>& W, long long X) {

    sort(W.begin(), W.end());

    for (long long i = 0; i < W.size(); ++i) {

        long long needed = X - W[i].weight;

        long long position = binarySearch(W, needed, i + 1, W.size() - 1);

        if (position != -1) {
            if (W[i].initialIndex < W[position].initialIndex) {
                cout << W[i].initialIndex << " " << W[position].initialIndex << endl;
            }
            else {
                cout << W[position].initialIndex << " " << W[i].initialIndex << endl;
            }

            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    long long T;
    cin >> T;

    if (T < MIN_T || T > MAX_T) {
        return -1;
    }

    for (long long t = 0; t < T; ++t) {

        long long X;
        cin >> X;

        if (X < MIN_X || X > MAX_X) {
            return -1;
        }

        long long N;
        cin >> N;

        if (N < MIN_N || N > MAX_N) {
            return -1;
        }

        vector<Box> W;

        for (long long i = 0; i < N; ++i) {
            long long weight;
            cin >> weight;

            if (weight < MIN_Wi || weight > MAX_Wi) {
                return -1;
            }

            W.push_back(Box(weight, i + 1));
        }

        handleRequests(W, X);
    }

    return 0;
}
