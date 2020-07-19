class Solution {
public:
  int findPaths(int m, int n, int N, int i, int j) {
    int res = 0;
    int mod = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n));
    
    dp[i][j] = 1;
    
    for (int k = 0; k < N; k++) {
      vector<vector<int>> tmp(m, vector<int>(n));
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (r == 0) {
            res = (res + dp[r][c]) % mod;
          } else {
            tmp[r][c] = (tmp[r][c] + dp[r - 1][c]) % mod;
          }
          if (r == m - 1) {
            res = (res + dp[r][c]) % mod;
          } else {
            tmp[r][c] = (tmp[r][c] + dp[r + 1][c]) % mod;
          }
          if (c == 0) {
            res = (res + dp[r][c]) % mod;
          } else {
            tmp[r][c] = (tmp[r][c] + dp[r][c - 1]) % mod;
          }
          if (c == n - 1) {
            res = (res + dp[r][c]) % mod;
          } else {
            tmp[r][c] = (tmp[r][c] + dp[r][c + 1]) % mod;
          }
        }
      }
      dp = tmp;
    }
    
    return res;
  }
};
