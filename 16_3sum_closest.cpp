class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        int tsum = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int second = i + 1;
            int third = nums.size() - 1;
            int sum = target - nums[i];
            while (second < third) {
                if (abs(sum - nums[second] - nums[third]) < result) {
                    result = abs(sum - nums[second] - nums[third]);
                    tsum = nums[i] + nums[second] + nums[third];
                }
                if (nums[second] + nums[third] < sum) {
                    second++;
                } else if (nums[second] + nums[third] > sum) {
                    third--;
                } else {
                    return target;
                }
            }
        }
        return tsum;
    }
};
