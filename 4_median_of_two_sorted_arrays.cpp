class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> a = len1 <= len2 ? nums1 : nums2;
        vector<int> b = len1 <= len2 ? nums2 : nums1;
        
        int low = 0;
        int end = a.size();
        int i = 0, j = 0;
        
        if (a.size() == 0) {
            if (b.size() % 2 == 1) {
                return b[b.size()/2];
            } else 
                return (b[b.size()/2] + b[b.size()/2-1])/2.0;
        }
        
        while (low <= end) {
            i = (low + end) >> 1;
            j = (len1 + len2 + 1) / 2 - i;
            cout << i << j << endl;
            if ((i == 0 || a[i-1] <= b[j]) && (j == 0 || b[j-1] <= a[i])) {
                break;
            } else if (i > 0 && a[i-1] > b[j]) {
                end = i - 1;
            } else if (j > 0 && a[i] < b[j-1]) {
                low = i + 1;
            } else {
                
            }
        }

        if ((len1 + len2) % 2 == 0) {
            return (max(i > 0 ? a[i-1] : INT_MIN, j > 0 ? b[j-1] : INT_MIN) + min(i < a.size() ? a[i] : INT_MAX, j < b.size() ? b[j] : INT_MAX)) / 2.0;
        } else
            return max(i > 0 ? a[i-1] : INT_MIN, j > 0 ? b[j-1] : INT_MIN);
    }
};
