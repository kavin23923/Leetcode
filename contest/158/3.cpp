class Solution {
public:
  int dieSimulator(int n, vector<int>& rollMax) {
    long long res = 0;
    long long mod = (long long)1e9 + 7;
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(6, vector<long long>(16)));
    
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 6; j++) {
        long long tmp = 0; // dp[i][j]][1]
        for (int a = 0; a < 6; a++) {
          for (int b = 1; b <= min(i - 1, 15); b++) {
            if (j != a) {
              tmp += dp[i - 1][a][b];
            }
          }
        }
        dp[i][j][1] = tmp == 0 ? 1 : tmp % mod;
        for (int k = 2; k <= i; k++) {
          if (rollMax[j] >= k) {
            dp[i][j][k] = dp[i - 1][j][k - 1];
          }
        }
      }
    }
    
    for (int i = 0; i < 6; i++) {
      for (int j = 1; j <= 15; j++) {
        res = (res + dp[n][i][j]) % mod;
      }
    }
    
    return (int)res;
  }
};
