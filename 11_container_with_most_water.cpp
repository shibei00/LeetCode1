class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int water = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            water = max(water, h * (right - left));
            while (height[left] <= h) left++;
            while (height[right] <= h) right--;
        }
        return water;
    }
};
