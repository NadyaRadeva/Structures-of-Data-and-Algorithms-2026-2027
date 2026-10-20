class Solution {
public:
    string countingSort(char* values, int size) {
        int count[256] = {0};

        for (int i = 0; i < size; ++i) {
            count[(unsigned char)values[i]]++;
        }

        string res = "";

        for (int frequency = size; frequency >= 1; --frequency) {
            for (int i = 0; i < 256; ++i) {
                if (count[i] == frequency) {
                    for (int j = 0; j < frequency; ++j) {
                        res += (char)i;
                    }
                }
            }
        }

        return res;
    }

    string frequencySort(string s) {
        int sSize = s.size();
        char* values = new char[sSize];

        for (int i = 0; i < sSize; ++i) {
            values[i] = s[i];
        }

        string res = countingSort(values, sSize);

        delete[] values;

        return res;
    }
};
