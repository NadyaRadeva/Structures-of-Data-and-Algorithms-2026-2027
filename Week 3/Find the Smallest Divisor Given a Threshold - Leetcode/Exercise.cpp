class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxVal = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }

        int left = 1;
        int right = maxVal;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int sum = 0;
            for(int i = 0; i < nums.size(); ++i) {
                sum += (nums[i]  + mid  - 1)/ mid;
            }
            if(sum <= threshold) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
