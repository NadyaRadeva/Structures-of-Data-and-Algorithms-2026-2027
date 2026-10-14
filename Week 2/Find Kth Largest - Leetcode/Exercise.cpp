// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[(left + right)  / 2];
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

    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;

        quickSort(nums, 0, nums.size() - 1);

        return nums[nums.size() - k];
    }
};
