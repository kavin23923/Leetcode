class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    m = grid.size();
    n = m == 0 ? 0 : grid[0].size();
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          res++;
          dfs(grid, i, j);
        }
      }
    }
    
    return res;
  }
  
  void dfs(vector<vector<char>>& grid, int x, int y) {
    grid[x][y] = '0';
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
      dfs(grid, x - 1, y);
    }
    if (x + 1 < m && grid[x + 1][y] == '1') {
      dfs(grid, x + 1, y);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
      dfs(grid, x, y - 1);
    }
    if (y + 1 < n && grid[x][y + 1] == '1') {
      dfs(grid, x, y + 1);
    }
  }
  
private:
  int m, n;
};
