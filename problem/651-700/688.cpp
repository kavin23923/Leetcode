class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    double res = 0;
    vector<vector<double>> dp(N, vector<double>(N));
    vector<vector<int>> move = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    dp[r][c] = 1;
    while (K > 0) {
      vector<vector<double>> tmp(N, vector<double>(N));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          for (int m = 0; m < 8; m++) {
            r = i + move[m][0];
            c = j + move[m][1];
            if (r >= 0 && r < N && c >= 0 && c < N) {
              tmp[r][c] += dp[i][j] / 8;
            }
          }
        }
      }
      dp = tmp;
      K--;
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        res += dp[i][j];
      }
    }
    
    return res;
  }
};
