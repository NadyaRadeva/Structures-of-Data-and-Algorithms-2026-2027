//  https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        int left = 0, right = height.size() - 1;

        while(left <= right) {
            int wid = right - left;
            int currentArea = wid * (height[left] > height[right] ? height[right]: height[left]);
            if(currentArea > maxArea) {
                maxArea = currentArea;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
