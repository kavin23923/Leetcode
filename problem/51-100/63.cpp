class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = m == 0 ? 0 : obstacleGrid[0].size();
    int i, j;
    long long dp[n] = {1};

    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        if (obstacleGrid[i][j]) {
          dp[j] = 0;
        } else if (j != 0){
          dp[j] += dp[j - 1];
        }
      }
    }
    return (int) dp[n - 1];
  }
};
