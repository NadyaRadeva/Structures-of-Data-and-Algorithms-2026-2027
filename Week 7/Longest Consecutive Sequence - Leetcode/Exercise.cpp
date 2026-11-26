class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        for(int i = 0; i < nums.size(); ++i) {
            numbers.insert(nums[i]);
        }

        int longest = 0;

        for(int num : numbers) {

            if(numbers.find(num - 1) == numbers.end()) {

                int current = num;
                int count = 1;

                while(numbers.find(current + 1) != numbers.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
