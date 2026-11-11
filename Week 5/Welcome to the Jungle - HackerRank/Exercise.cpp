//  https://www.hackerrank.com/contests/practice-4-sda/challenges/welcome-to-the-jungle/problem

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1000000;
const int MIN_N = 2;
const int MAX_TREES = 1000000;
const int MIN_TREES = 1;

int main() {
    int N;
    cin >> N;

    if(N < MIN_N || N > MAX_N) {
        return 0;
    }

    int* trees = new int[N];

    for(int i = 0; i < N; ++i) {
        cin >> trees[i];

        if(trees[i] < MIN_TREES || trees[i] > MAX_TREES) {
            delete[] trees;
            return 0;
        }
    }

    stack<int> st;

    int maxLen = 1;
    int index = N - 1;

    for(int i = N - 1; i >= 0; --i) {

        while(!st.empty() && trees[i] >= st.top()) {
            st.pop();
        }

        st.push(trees[i]);

        if(st.size() >= maxLen) {
            maxLen = st.size();
            index = i;
        }
    }

    cout << index << '\n';

    delete[] trees;

    return 0;
}
