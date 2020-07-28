class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    int dis = 0;
    int r, c;
    pair<int, int> tmp;
    queue<pair<int, int>> node;
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          node.push(make_pair(i, j));
        }
      }
    }
    
    if (node.size() == 0 || node.size() == n * n) return -1;
    
    while (!node.empty()) {
      int size= node.size();
      for (int i = 0; i < size; i++) {
        tmp = node.front();
        node.pop();
        for (int j = 0; j < 4; j++) {
          r = tmp.first + move[j][0];
          c = tmp.second + move[j][1];
          if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
            node.push(make_pair(r, c));
            grid[r][c] = 1;
          }
        }
      }
      dis++;
    }
    
    return dis - 1;
    
  }
};
