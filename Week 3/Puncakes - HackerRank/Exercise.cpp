// https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem

#include <map>
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

long long MIN_N = 1;
long long MAX_N = 10000000000000LL;
long long MIN_K = 1;
long long MAX_K = 100000;
long long MIN_Ti = 1;
long long MAX_Ti = 10000;

int main() {
    long long N, K;
    std::cin >> N;

    if (N < MIN_N || N > MAX_N) {
        return -1;
    }

    std::cin >> K;

    if (K < MIN_K || K > MAX_K) {
        return -1;
    }

    long long* T = new long long[K];

    long long minTime = LLONG_MAX;

    for (long long i = 0; i < K; ++i) {
        std::cin >> T[i];

        if (T[i] < MIN_Ti || T[i] > MAX_Ti) {
            delete[] T;
            return -1;
        }

        if (T[i] < minTime) {
            minTime = T[i];
        }
    }

    long long beg = 0;
    long long end = N * minTime;

    while (beg <= end) {
        long long mid = beg + (end - beg) / 2;

        long long total = 0;

        for (long long i = 0; i < K; ++i) {
            total += mid / T[i];

            if (total >= N) {
                break;
            }
        }

        if (total >= N) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }

    std::cout << beg << std::endl;

    delete[] T;

    return 0;
}
