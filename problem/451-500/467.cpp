class Solution {
public:
  int findSubstringInWraproundString(string p) {
    int longest[26] = {0};
    int res = 0, len = p.size();
    vector<int> dp(len, 1);
    
    for (int i = 0; i < len; i++) {
      if (i != 0 && (p[i] - p[i - 1] == 1 || (p[i] - p[i - 1] == -25))) {
        dp[i] = dp[i - 1] + 1;
      }
      longest[p[i] - 'a'] = max(longest[p[i] - 'a'], dp[i]);
    }
    
    for (int i = 0; i < 26; i++) {
      res += longest[i];
    }
    
    return res;
  }
};
