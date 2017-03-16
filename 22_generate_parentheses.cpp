class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n == 0)
      return result;
    string sol;
    generateParenthesisDFS(n, sol, 0, 0, result);
    return result;
  }

  void generateParenthesisDFS(int n, string& sol, int leftParenthesisNum, int rightParenthesisNum, vector<string> &result) {
    if (leftParenthesisNum == n && rightParenthesisNum == n) {
      result.push_back(sol);
      return;
    }

    if (leftParenthesisNum < n) {
      //put left parenthesis
      sol += '(';
      generateParenthesisDFS(n, sol, leftParenthesisNum+1, rightParenthesisNum, result);
      sol.resize(sol.size() - 1);
    }

    if (rightParenthesisNum < n && leftParenthesisNum > rightParenthesisNum) {
      //put right parenthesis
      sol += ')';
      generateParenthesisDFS(n, sol, leftParenthesisNum, rightParenthesisNum + 1, result);
      sol.resize(sol.size() - 1);
    }
  }
};
