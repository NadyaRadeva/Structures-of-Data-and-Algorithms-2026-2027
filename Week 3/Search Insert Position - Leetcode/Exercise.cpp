// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                beg = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return beg;
    }
};
