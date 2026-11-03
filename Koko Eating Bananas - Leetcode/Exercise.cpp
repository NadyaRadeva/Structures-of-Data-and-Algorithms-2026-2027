class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int h, int k) {
        long long hoursNeeded = 0;

        for(int i = 0; i < piles.size(); ++i) {
            hoursNeeded += ((long long)piles[i] + k - 1) / k;
        }

        return hoursNeeded <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = piles[0];

        for(int i = 0; i < piles.size(); ++i) {
            if(maxElement < piles[i]) {
                maxElement = piles[i];
            }
        }

        int left = 1;
        int right = maxElement;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(canEatAllBananas(piles, h, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
