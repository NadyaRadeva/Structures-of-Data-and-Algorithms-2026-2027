// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        
        for(int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[j] == diff) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }

        return result;
    }
};
