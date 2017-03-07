class Solution {
 public:
  int longestValidParentheses(string s) {
    /* the complexity is O(n^2)
       if (s.size() == 0)
       return 0;
       int len = s.size();

       if (len <= 0)
       return 0;

       vector<vector<int>> dp (len, vector<int>(len, 0));

       for (int i = 0; i < len; i++) {
       if (s[i] == '(')
       dp[i][i] = 1;
       else
       dp[i][i] = -1;
       }

       int maxLen = INT_MIN;

       for (int i = 0; i < len; i++) {
       for (int j = i + 1; j < len; j++) {
       if (dp[i][j-1] < 0) {
       dp[i][j] = -1;
       continue;
       }

       if (s[j] == '(') {
       dp[i][j] = dp[i][j-1] + 1;
       } else {
       dp[i][j] = dp[i][j-1] - 1;
       }
       if (dp[i][j] == 0)
       maxLen = max(maxLen, j - i + 1);
       }
       }
       return max(0, maxLen); */

    /* use dynamic programming : dp[i] is the length of valid parentheses end at i. The complexity is O(n).
       int len = s.size();
       if (len <= 0)
       return 0;
       vector<int> dp(len, 0);
       dp[0] = 0;
       int maxResult = 0;

       for (int i = 1; i < len; i++) {
       if (s[i] == '(')
       dp[i] = 0;
       else {
       if (s[i-1] == ')') {
       if (i >= dp[i-1] + 1 && s[i - dp[i-1] - 1] == '(') {
       dp[i] = dp[i-1] + 2;
       if (i >= dp[i-1] + 2)
       dp[i] += dp[i - dp[i-1] - 2];
       } else
       dp[i] = 0;
       } else {
       dp[i] = i - 2 >= 0 ? 2 + dp[i - 2] : 2;
       }
       }
       maxResult = max(maxResult, dp[i]);
       }
       return maxResult; */

    /* Use the stack. The complexity is O(n). */
    int len = s.size();
    if (len <= 0)
      return 0;
    stack<int> tStack;
    int maxLen = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '(')
        tStack.push(i);
      else {
        if (!tStack.empty() && s[tStack.top()] == '(')
          tStack.pop();
        else
          tStack.push(i);
      }
    }

    if (tStack.empty())
      maxLen = max(maxLen, len);
    else {
      int end = len;
      for (int j = tStack.size() - 1; j >= 0; j--) {
        maxLen = max(maxLen, end - tStack.top() - 1);
        end = tStack.top();
        tStack.pop();
      }
      if (end != 0)
        maxLen = max(maxLen, end);
    }
    return maxLen;
  }
};
