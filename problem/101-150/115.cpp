class Solution {
public:
  int numDistinct(string s, string t) {
    int len1 = t.size(), len2 = s.size();
    vector<vector<long long>> dp(len1 + 1, vector<long long>(len2 + 1));
    
    for (int i = 0; i <= len2; i++) {
      dp[0][i] = 1;
    }
    
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (t[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    
    return dp[len1][len2];
  }
};
