// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }

    int firstMissingPositive(vector<int>& nums) {
        int target = 1;

       for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                ++target;
            }
        }

        return target;
    }
};
