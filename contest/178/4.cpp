class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    vector<pair<int, int>> dir = {{}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> node;
    pair<int, int> tmp;
    int now = 0;
    dfs(0, 0, grid, cost, dir, node, now++);
    
    while (!node.empty()) {
      int size = node.size();
      for (int i = 0; i < size; i++) {
        tmp = node.front();
        node.pop();
        for (int i = 1; i <= 4; i++) {
          dfs(tmp.first + dir[i].first, tmp.second + dir[i].second, grid, cost, dir, node, now);
        }
      }
      now++;
    }
    
    return cost[m - 1][n - 1];
  }
  
  void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &cost, vector<pair<int, int>> &dir, queue<pair<int, int>> &node, int now) {
    if (x < 0 || x >= m || y < 0 || y >= n || cost[x][y] != INT_MAX) return;
    cost[x][y] = now;
    node.push(make_pair(x, y));
    dfs(x + dir[grid[x][y]].first, y + dir[grid[x][y]].second, grid, cost, dir, node, now);
  }
  
private:
  int m, n;
};
