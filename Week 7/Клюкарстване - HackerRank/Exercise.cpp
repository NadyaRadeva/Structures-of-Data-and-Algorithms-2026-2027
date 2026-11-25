#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

const int MIN_GRANDMAS = 1;
const int MAX_GRANDMAS = 100000;
const int MIN_TOPICS = 1;
const int MAX_TOPICS = INT_MAX;

int main() {
    int grandmasCount;
    cin >> grandmasCount;

    if(!cin || grandmasCount > MAX_GRANDMAS ||
       grandmasCount < MIN_GRANDMAS) {
        return -1;
    }

    unordered_map<int, int> grandmas;
    int minDistance = INT_MAX;

    for(int i = 0; i < grandmasCount; ++i) {
        int topic;
        cin >> topic;

        if(!cin || topic < MIN_TOPICS || topic > MAX_TOPICS) {
            return -1;
        }

        if(grandmas.find(topic) != grandmas.end()) {
            int distance = i - grandmas[topic];

            if(distance < minDistance) {
                minDistance = distance;
            }
        }

        grandmas[topic] = i;
    }

    if(minDistance == INT_MAX) {
        cout << -1;
    }
    else {
        cout << minDistance;
    }

    return 0;
}
