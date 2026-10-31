// https://www.hackerrank.com/contests/sda-hw-2-2026/challenges/challenge-3668/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long k, q;
    cin >> k >> q;

    while (q--) {
        long long x;
        cin >> x;

        x--;

        long long power = 1;

        for (int i = 0; i < k - 1; i++) {
            power *= 3;
        }

        int answer = k + 1;

        for (int i = 1; i <= k; i++) {
            int digit = x / power;

            if (digit == 1) {
                answer = i;
                break;
            }

            x %= power;
            power /= 3;
        }

        cout << answer << '\n';
    }

    return 0;
}
