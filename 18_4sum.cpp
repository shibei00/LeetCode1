class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        int first = 0;
        while (first < nums.size() - 3) {
            int second = first + 1;
            int total_3 = target - nums[first];
            while (second < nums.size() - 2) {
                int total_2 = total_3 - nums[second];
                int third = second + 1;
                int fourth = nums.size() - 1;
                while (third < fourth) {
                    if (nums[third] + nums[fourth] < total_2) {
                        third++;
                    } else if (nums[third] + nums[fourth] > total_2) {
                        fourth--;
                    } else {
                        vector<int> r(4, 0);
                        r[0] = nums[first];
                        r[1] = nums[second];
                        r[2] = nums[third];
                        r[3] = nums[fourth];
                        result.push_back(r);
                        while (third + 1 < fourth && nums[third+1] == nums[third])
                            third++;
                        while (fourth > third + 1 && nums[fourth-1] == nums[fourth])
                            fourth--;
                        third++;
                        fourth--;
                    }
                }
                while (second < nums.size() - 1 && nums[second+1] == nums[second])
                    second++;
                second++;
            }
            while(first < nums.size() - 1 && nums[first+1] == nums[first])
                first++;
            first++;
        }
        return result;
    }
};
