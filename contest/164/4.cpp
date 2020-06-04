class Solution {
public:
  int numWays(int steps, int arrLen) {
    int mod = 1000000007;
    int size = min(steps, arrLen);
    vector<long long> dp(size, 0);
    dp[0] = 1;
    
    for (int i = 0; i < steps; i++) {
      vector<long long> tmp(size, 0);
      for (int j = 0; j < size; j++) {
        tmp[j] += dp[j];
        if (j - 1 >= 0) tmp[j] += dp[j - 1];
        if (j + 1 < size) tmp[j] += dp[j + 1];
        tmp[j] %= mod;
      }
      dp = tmp;
    }
    return (int)dp[0];
  }
};
