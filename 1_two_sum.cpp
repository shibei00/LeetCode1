class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numsMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numsMap.find(complement) != numsMap.end()) {
                result = {i, numsMap[complement]};
                break;
            } else {
                numsMap[nums[i]] = i;
            }
        }
        return result;
    }
};
