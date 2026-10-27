// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int beg = 0, end = x;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            if ((long long)mid * mid == x) {
                return mid;
            }
            else if ((long long)mid * mid < x) {
                beg = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return end;
    }
};
