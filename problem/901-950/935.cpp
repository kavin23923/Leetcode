class Solution {
public:
  int knightDialer(int N) {
    int mod = 1e9 + 7;
    int res = 0;
    vector<vector<int>> move = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    vector<vector<int>> dp(N, vector<int>(10));
    
    for (int i = 0; i < 10; i++) {
      dp[0][i] = 1;
    }
    
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < 10; j++) {
        for (int pre : move[j]) {
          dp[i][j] = (dp[i][j] + dp[i - 1][pre]) % mod;
        }
      }
    }
    
    for (int i = 0; i < 10; i++) {
      res = (res + dp[N - 1][i]) % mod;
    }
    return res;
  }
};
