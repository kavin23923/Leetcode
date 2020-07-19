class Solution {
public:
  int minCut(string s) {
    int len = s.size();
    vector<vector<bool>> is_pan(len, vector<bool>(len, false));
    vector<int> dp(len + 1);
    
    for (int i = 0; i < len; i++) {
      is_pan[i][i] = true;
      dp[i] = i - 1;
    }  
    dp[len] = len - 1;
  
    for (int i = 0; i < len; i++) {
      for (int j = i; j >= 0; j--) {
        if (s[i] == s[j] && (i - j < 2 || is_pan[j + 1][i - 1])) {
          is_pan[j][i] = true;
          dp[i + 1] = min(dp[i + 1], dp[j] + 1);
        }
      }
    }
    
    return dp[len];
  }
};
