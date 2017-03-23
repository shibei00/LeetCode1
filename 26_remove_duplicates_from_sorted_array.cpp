class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        if (nums.size()==0)
            return 0;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        }
        return nums.size()-count;
        */
        
        if (nums.size() == 0)
            return 0;
            
        int currentIndex = 1;
        int lastElement = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != lastElement) {
                nums[currentIndex] = nums[i];
                lastElement = nums[i];
                currentIndex++;
            }
        }
        return currentIndex;
    }
};
