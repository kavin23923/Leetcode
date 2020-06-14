class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    int total = m * n, now = 0;
    vector<vector<int>> res(m, vector<int>(n));
    
    k = (total - (k % total)) % total;
    while (now < total) {
      res[now / n][now % n] = grid[k / n][k % n];
      now++;
      k++;
      k %= total;
    }
    
    return res;
  }
};
