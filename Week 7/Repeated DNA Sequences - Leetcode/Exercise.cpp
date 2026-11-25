class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> subseq;

        int n = s.size();

        for(int i = 0; i <= n - 10; ++i) {
            string sub = s.substr(i, 10);
            subseq[sub]++;
        }

        vector<string> res;

        for(auto it = subseq.begin(); it != subseq.end(); ++it) {
            if(it->second > 1) {
                res.push_back(it->first);
            }
        }

        return res;
    }
};
