#include <iostream>
#include <unordered_map>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1000000;

int main() {
    int sizeOfArr;
    cin >> sizeOfArr;

    if(!cin || sizeOfArr < MIN_N || sizeOfArr > MAX_N) {
        return -1;
    }

    unordered_map<int, int> firstPosition;

    int sum = 0;
    int maxLength = 0;

    firstPosition[0] = -1;

    for(int i = 0; i < sizeOfArr; ++i) {
        int num;
        cin >> num;

        if(!cin || (num != 0 && num != 1)) {
            return -1;
        }

        if(num == 0) {
            sum--;
        }
        else {
            sum++;
        }

        if(firstPosition.find(sum) != firstPosition.end()) {
            int length = i - firstPosition[sum];

            if(length > maxLength) {
                maxLength = length;
            }
        }
        else {
            firstPosition[sum] = i;
        }
    }

    cout << maxLength;

    return 0;
}
