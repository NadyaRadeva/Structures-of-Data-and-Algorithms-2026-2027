class Solution {
public:
    bool canLoadThisWeight(vector<int>& weights, int days, int X) {
        int currentWeight = 0;
        int requiredDays = 1;

        for(int i = 0; i < weights.size(); ++i) {

            if(currentWeight + weights[i] <= X) {
                currentWeight += weights[i];
            }
            else {
                requiredDays++;
                currentWeight = weights[i];
            }
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int left = weights[0];
        int right = 0;

        for(int i = 0; i < weights.size(); ++i) {

            if(weights[i] > left) {
                left = weights[i];
            }

            right += weights[i];
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(canLoadThisWeight(weights, days, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
