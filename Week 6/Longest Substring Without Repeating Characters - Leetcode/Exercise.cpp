class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        set<char> charSet;
        int beg = 0;

        for (int i = 0; i < n; i++) {
            if (charSet.count(s[i]) == 0) {
                charSet.insert(s[i]);
            } 
            else {
                while (s[beg] != s[i]) {
                    charSet.erase(s[beg]);
                    beg++;
                }

                beg++;
            }

            charSet.insert(s[i]);

            maxLength = max(maxLength, (int)charSet.size());
        }

        return maxLength;
    }
};
