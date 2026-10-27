// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int beg = 0, end = n - 1;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(firstBadVersion(mid)) {
                end = mid - 1;
            }
            else {
                beg = mid + 1;
            }
        }

        return -1;
    }
};
