class Solution {
public:
  int numTrees(int n) {
    int dp[n + 1] = {1};
    int i, j;
    
    for (i = 1; i <= n; i++) {
      for (j = 0; j < i; j++) {
        dp[i] += dp[j] * dp[i - j - 1]; 
      }
    }
    return dp[n];
  }
};
