// https://leetcode.com/problems/single-number/

class Solution {
public:
    int elementOccurence(vector<int>& nums, int el) {
        int occ = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == el) {
                ++occ;
            }
        }

        return occ;
    }

    int singleNumber(vector<int>& nums) {
        int oddOneOut = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(elementOccurence(nums, nums[i]) == 1) {
                oddOneOut = nums[i];
            }
        }    

        return oddOneOut;
    }
};
