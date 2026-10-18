class Solution {
public:
    string countingSort(string s) {
        int count[128] = {0};

        for (int i = 0; i < s.size(); ++i) {
            count[s[i]]++;
        }

        int maxFreq = 0;

        for (int i = 0; i < 128; ++i) {
            if (count[i] > maxFreq) {
                maxFreq = count[i];
            }
        }

        string newString = "";

        for (int freq = maxFreq; freq > 0; --freq) {
            for (int i = 0; i < 128; ++i) {
                if (count[i] == freq) {
                    for (int j = 0; j < freq; ++j) {
                        newString += (char)i;
                    }
                }
            }
        }

        return newString;
    }

    string frequencySort(string s) {
        return countingSort(s);
    }
};
