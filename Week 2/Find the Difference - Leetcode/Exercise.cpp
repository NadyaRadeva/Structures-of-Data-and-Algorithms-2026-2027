// https://leetcode.com/problems/find-the-difference/description/

class Solution {
public:
    void countingSort(string &s, string &t) {
        string strSCopy = s;
        string strTCopy = t;

        int countS[26] = {0};

        for (size_t i = 0; i < s.size(); ++i) {
            countS[s[i] - 'a']++;
        }

        for (int i = 1; i < 26; ++i) {
            countS[i] += countS[i - 1];
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            s[countS[strSCopy[i] - 'a'] - 1] = strSCopy[i];
            countS[strSCopy[i] - 'a']--;
        }

        int countT[26] = {0};

        for (size_t i = 0; i < t.size(); ++i) {
            countT[t[i] - 'a']++;
        }

        for (int i = 1; i < 26; ++i) {
            countT[i] += countT[i - 1];
        }
        
        for (int i = (int)t.size() - 1; i >= 0; i--) {
            t[countT[strTCopy[i] - 'a'] - 1] = strTCopy[i];
            countT[strTCopy[i] - 'a']--;
        }
    }

    char findTheDifference(string s, string t) {
        countingSort(s, t);

        int index = 0;
        while (index < s.size()) {
            if (s[index] != t[index]) {
                return t[index];
            }
            ++index;
        }

        return t.back();
    }
};
