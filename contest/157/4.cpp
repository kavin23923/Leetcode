class Solution {
public:
  int countVowelPermutation(int n) {
    long long res = 0;
    vector<vector<long long>> dp(n + 1, vector<long long>(5, 1));
    int mod = 1e9 + 7;
    
    for (int i = 2; i <= n; i++) {
      dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod; //a
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod; //e
      dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod; //i
      dp[i][3] = (dp[i - 1][2]) % mod; //o
      dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod; //u
    }
    
    for (int i = 0; i < 5; i++) {
      res = (res + dp[n][i]) % mod;
    }
    
    return (int)(res);
  }
};
