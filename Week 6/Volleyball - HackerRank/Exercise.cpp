#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;


int main() {
    int first, n, count;
    std::cin >> first >> n;
    set<int> s;
    s.insert(first);
    
    for(int i = 0; i < n; ++i) {
        int x, y;
        
        std::cin >> x >> y;
        
        if(s.find(x) != s.end()) {
            s.insert(y);
        }
    }
    
    std::cout << s.size();
    
    return 0;
}
