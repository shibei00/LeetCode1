class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> cache;
    return diffWaysToComputeByIter(input, 0, input.size()-1, cache);
  }

  vector<int> diffWaysToComputeByIter(string& input, int start, int end, unordered_map<string, vector<int>>& cache) {
    vector<int> result;
    for (int i = start; i <= end; i++) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        string lStr = input.substr(start, i-start);
        string rStr = input.substr(i+1, end-i);
        vector<int> left = cache.count(lStr) > 0 ? cache[lStr] : diffWaysToComputeByIter(input, start, i-1, cache);
        vector<int> right = cache.count(rStr) > 0 ? cache[rStr] : diffWaysToComputeByIter(input, i+1, end, cache);
        for (int l : left) {
          for (int r : right) {
            switch(input[i]) {
              case '+':
                result.push_back(l + r);
                break;
              case '-':
                result.push_back(l - r);
                break;
              default:
                result.push_back(l * r);
            }
          }
        }
      }
    }

    if (result.empty()) {
      result.push_back(stoi(input.substr(start, end - start + 1)));
    }
    cache[input.substr(start, end - start + 1)] = result;
    return result;
  }
};
