class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<int>> row(9);
    unordered_map<int, unordered_set<int>> col(9);
    unordered_map<int, unordered_set<int>> box(9);
    int b;
    
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        b = (i / 3) * 3 + j / 3;
        if (row[i].find(board[i][j]) != row[i].end() || col[j].find(board[i][j]) != col[j].end() || box[b].find(board[i][j]) != box[b].end()) {
          return false;
        }
        row[i].insert(board[i][j]);
        col[j].insert(board[i][j]);
        box[b].insert(board[i][j]);
      }
    }
    
    return true;
  }
};
