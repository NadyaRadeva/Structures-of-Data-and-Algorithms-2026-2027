class Solution {
public:
const int MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        unordered_map<long long, long long> leftFrequencies, rightFrequencies;

        for(int i = 0; i < nums.size(); ++i) {
            rightFrequencies[nums[i]]++;
        }

        for (int j = 0; j < n; ++j) {
            int mid = nums[j];
            rightFrequencies[mid]--; 

            int left = leftFrequencies[2 * mid];
            int right = rightFrequencies[2 * mid];
            
            result = (result + (long long)left * right) % MOD;
            leftFrequencies[mid]++;
        }

        return result;
    }
};
