class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        int sum = 0;

        for(int i = 0; i < k; ++i) {
            q.push(nums[i]);
            sum += nums[i];
        }

        double maxAverage = 1.0 * sum / k;

        for(int i = k; i < nums.size(); ++i) {
            sum -= q.front();
            q.pop();

            q.push(nums[i]);
            sum += nums[i];

            maxAverage = max(maxAverage, sum * 1.0 / k);
        }

        return maxAverage;
    }
};
