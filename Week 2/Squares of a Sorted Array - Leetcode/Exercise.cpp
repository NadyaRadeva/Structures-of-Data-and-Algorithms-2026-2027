// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[(left + right) / 2];
        
        int i = left;
        int j = right;

        while(true) {
            while(nums[i] < pivot) {
                ++i;
            }

            while(nums[j] > pivot) {
                --j;
            }

            if(i >= j) {
                return j;
            }

            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return;
        }

        int pIndex = partition(nums, left, right);
        quickSort(nums, left, pIndex);
        quickSort(nums, pIndex + 1, right);
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sortedSquaresNums(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            sortedSquaresNums[i] = nums[i] * nums[i];
        }

        quickSort(sortedSquaresNums, 0, nums.size() - 1);

        return sortedSquaresNums;
    }
};
