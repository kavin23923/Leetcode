class Solution {
public:
  int minimumMoves(vector<vector<int>>& grid) {
    set<vector<int>> exist;
    int n = grid.size(), now = 0;
    vector<int> end = {n - 1, n - 2, n - 1, n - 1};
    vector<int> tmp;
    queue<vector<int>> pos;
    
    pos.push({0, 0, 0, 1});
    while(!pos.empty()) {
      int size = pos.size();
      for (int i = 0; i < size; i++) {
        tmp = pos.front();
        pos.pop();
        if (tmp == end) return now;
        // rotate
        if (tmp[0] == tmp[2] && tmp[2] + 1 < n && grid[tmp[2] + 1][tmp[3] - 1] == 0 && grid[tmp[2] + 1][tmp[3]] == 0 && exist.find({tmp[0], tmp[1], tmp[2] + 1, tmp[3] - 1}) == exist.end()) {
          exist.insert({tmp[0], tmp[1], tmp[2] + 1, tmp[3] - 1});
          pos.push({tmp[0], tmp[1], tmp[2] + 1, tmp[3] - 1});
        } else if (tmp[1] == tmp[3] && tmp[3] + 1 < n && grid[tmp[2] - 1][tmp[3] + 1] == 0 && grid[tmp[2]][tmp[3] + 1] == 0 && exist.find({tmp[0], tmp[1], tmp[2] - 1, tmp[3] + 1}) == exist.end()){ 
          exist.insert({tmp[0], tmp[1], tmp[2] - 1, tmp[3] + 1});
          pos.push({tmp[0], tmp[1], tmp[2] - 1, tmp[3] + 1});
        }
        // right
        if (tmp[3] + 1 < n && grid[tmp[0]][tmp[1] + 1] == 0 && grid[tmp[2]][tmp[3] + 1] == 0 && exist.find({tmp[0], tmp[1] + 1, tmp[2], tmp[3] + 1}) == exist.end()) {
          exist.insert({tmp[0], tmp[1] + 1, tmp[2], tmp[3] + 1});
          pos.push({tmp[0], tmp[1] + 1, tmp[2], tmp[3] + 1});
        }
        // down
        if (tmp[2] + 1 < n && grid[tmp[0] + 1][tmp[1]] == 0 && grid[tmp[2] + 1][tmp[3]] == 0 && exist.find({tmp[0] + 1, tmp[1], tmp[2] + 1, tmp[3]}) == exist.end()){
          exist.insert({tmp[0] + 1, tmp[1], tmp[2] + 1, tmp[3]});
          pos.push({tmp[0] + 1, tmp[1], tmp[2] + 1, tmp[3]});
        }
      }
      now++;
    }
    
    return -1;
  }
};
