// https://www.hackerrank.com/contests/sda-hw-2-2026/challenges/challenge-3670/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canDivide(long long arr[], int n, int k, long long limit) {
    int teams = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {

        if (currentSum + arr[i] > limit) {
            teams++;
            currentSum = arr[i];
        }
        else {
            currentSum += arr[i];
        }

        if (teams > k) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long* arr = new long long[n];

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        left = max(left, arr[i]);
        right += arr[i];
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(arr, n, k, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    delete[] arr;

    return 0;
}
