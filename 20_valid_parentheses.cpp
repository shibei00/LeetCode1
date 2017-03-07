class Solution {
 public:
  bool isValid(string s) {
    int len = s.size();
    if (len <= 0)
      return true;

    stack<char> mStack;
    for (int i = 0; i < len; i++) {
      char c = s[i];
      if (c == ')' || c == ']' || c == '}') {
        bool flag = match(c, mStack);
        if (!flag)
          return false;
      } else {
        mStack.push(c);
      }
    }

    if (mStack.empty())
      return true;
    else
      return false;
  }

  bool match(char c, stack<char>& mStack) {
    if (mStack.empty())
      return false;

    char topChar = mStack.top();

    if ((c == ')' && topChar == '(') || (c == ']' && topChar == '[') || (c == '}' && topChar == '{')) {
      mStack.pop();
      return true;
    }
    return false;
  }
};
