class Solution {
public:
  int closedIsland(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    int now = 0;
    
    for (int i = 0; i < n; i++) {
      dfs(grid, 0, i);
      dfs(grid, m - 1, i);
    }
    for (int i = 1; i < m - 1; i++) {
      dfs(grid, i, 0);
      dfs(grid, i, n - 1);
    }
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          dfs(grid, i, j); 
          now++;
        }
      }
    }
    
    return now;
  }
  
  void dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0) return;
    grid[r][c] = 1;
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
  }
    
private:
  int m, n;
};
