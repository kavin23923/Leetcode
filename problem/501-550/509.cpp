class Solution {
public:
  int fib(int N) {
    int i, dp[30 + 1] = {0};
    dp[1] = 1;
    
    for (i = 2; i <= N; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
  }
};
