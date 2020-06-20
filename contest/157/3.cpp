class Solution {
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int res = 0;
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) {
          dfs(grid, i, j, 0, &res);
        }
      }
    }
    
    return res;
  }
  
  void dfs(vector<vector<int>>& grid, int r, int c, int now, int* res) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
      *res = max(*res, now);
      return;
    }
    int g = grid[r][c];
    grid[r][c] = 0;
    dfs(grid, r - 1, c, now + g, res);
    dfs(grid, r + 1, c, now + g, res);
    dfs(grid, r, c - 1, now + g, res);
    dfs(grid, r, c + 1, now + g, res);
    grid[r][c] = g;
  }
  
private:
  int m, n;
};
