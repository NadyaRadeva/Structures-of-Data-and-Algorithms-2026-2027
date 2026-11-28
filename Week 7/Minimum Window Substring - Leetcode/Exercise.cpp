class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }

        std::unordered_map<char, int> requiredFreq;

        std::unordered_map<char, int> windowFreq;

        for (char c : t) {
            requiredFreq[c]++;
        }

        int satisfiedChars = 0;
        int totalRequiredDistinct = requiredFreq.size();

        int windowStart = 0;
        int bestWindowLen = INT_MAX;
        int bestWindowStart = 0;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char endChar = s[windowEnd];
            windowFreq[endChar]++;

            if (requiredFreq.count(endChar) && 
                windowFreq[endChar] == requiredFreq[endChar]) {
                satisfiedChars++;
            }

            while (satisfiedChars == totalRequiredDistinct) {

                int currentWindowLen = windowEnd - windowStart + 1;

                if (currentWindowLen < bestWindowLen) {
                    bestWindowLen = currentWindowLen;
                    bestWindowStart = windowStart;
                }

                char startChar = s[windowStart];

                if (requiredFreq.count(startChar) &&
                    windowFreq[startChar] == requiredFreq[startChar]) {
                    satisfiedChars--;
                }

                windowFreq[startChar]--;
                windowStart++;
            }
        }

        if (bestWindowLen == INT_MAX) return "";

        return s.substr(bestWindowStart, bestWindowLen);
    }
};
