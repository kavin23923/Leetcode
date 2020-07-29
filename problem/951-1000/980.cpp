class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int res = 0;
    int target = 0;
    
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != -1) {
          target++;
        }
        if (grid[i][j] == 1) {
          sr = i;
          sc = j;
        } else if (grid[i][j] == 2) {
          dr = i;
          dc = j;
        }
      }
    }
    
    dfs(grid, sr, sc, target, &res);
    
    return res;
  }
  
  void dfs(vector<vector<int>>& grid, int r, int c, int target, int *res) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) {
      return;
    }
    if (--target == 0) {
      if (r == dr && c == dc) (*res)++;
      return;
    }
    grid[r][c] = -1;
    for (int i = 0; i < 4; i++) {
      dfs(grid, r + move[i][0], c + move[i][1], target, res);
    }
    grid[r][c] = 0;
  }

private:
  int m, n;
  int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int sr, sc;
  int dr, dc;
};
