// https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int Q;
    std::cin >> Q;
    
    for(int i = 0; i < Q; ++i) {
        int len;
        std::cin >> len;
        
        int lettersRemoved = 0;
        vector<char> list(len);
        for(int i = 0; i < len; ++i) {
            std::cin >> list[i];
        }
        
        for(int i = 0; i < len - 1; ++i) {
            if(list[i] == list[i + 1]) {
                ++lettersRemoved;
            }
        }
        
        std::cout << lettersRemoved << std::endl;
    }
      
    
    return 0;
}
