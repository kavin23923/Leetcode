class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int res = 0;
    m = matrix.size();
    n = m == 0 ? 0 : matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res = max(res, dfs(matrix, dp, i, j));
      }
    }
    
    return res;
  }
  
  int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, int x, int y) {
    if (dp[x][y]) return dp[x][y];
    for (int i = 0; i < 4; i++) {
      int r = x + move[i][0];
      int c = y + move[i][1];
      if (r >= 0 && r < m && c >= 0 && c < n && matrix[x][y] < matrix[r][c]) {
        dp[x][y] = max(dp[x][y], dfs(matrix, dp, r, c));
      }
    }
    return ++dp[x][y];
  }
  
private:
  int m, n;
  vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
