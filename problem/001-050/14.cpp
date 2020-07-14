class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    int len = n == 0 ? 0 : strs[0].size();
    string res = "";
    
    for (int i = 0; i < len; i++) {
      for (int j = 1; j < n; j++) {
        if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
          return res;
        }
      }
      res += strs[0][i];
    }
    
    return res;
  }
};
