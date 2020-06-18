class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    vector<vector<int>> matrix(8, vector<int>(8));
    vector<vector<int>> res;
    int r, c;
    
    for (auto q : queens) {
      matrix[q[0]][q[1]] = 1;
    }
    
    for (int i = 0; i < 8; i++) {
      r = king[0];
      c = king[1];
      while (r >= 0 && r < 8 && c >= 0 && c < 8) {
        if (matrix[r][c] == 1) {
          res.push_back({r, c});
          break;
        }
        r += dir[i][0];
        c += dir[i][1];
      }
    } 
    
    return res;
  }
};
