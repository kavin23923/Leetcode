class Solution {
public:
  int minSteps(int n) {
    vector<int> dp(n + 1);
    
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i / 2; j++) {
        if (i % j == 0) {
          dp[i] = dp[j] + i / j; + 1;
        }
      }
    }
    
    return dp[n];
  }
};
