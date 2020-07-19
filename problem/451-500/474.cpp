class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int size = strs.size();
    vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
    
    for (int k = 1; k <= size; k++) {
      int one = 0, zero;
      for (char c : strs[k - 1]) {
        one += c - '0';
      }
      zero = strs[k - 1].size() - one;
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          if (i >= zero && j >= one) {
            dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - zero][j - one] + 1);
          } else {
            dp[k][i][j] = dp[k - 1][i][j];
          }
        }
      }
    }
    
    return dp[size][m][n];
  }
};
