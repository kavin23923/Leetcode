class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[n] = {0};
    int i, j;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        if (j != 0) {
          dp[j] += dp[j - 1];
        } else {
          dp[j] = 1;
        }
      }
    }
    return dp[n - 1];   
  }
};
