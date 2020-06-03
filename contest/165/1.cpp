class Solution {
public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<int>> mat(3, vector<int>(3, 0));
    int now = 1;
    for (auto m : moves) {
      mat[m[0]][m[1]] = now;
      now *= -1;
    }
    
    int result = judge(mat);
    if (result != 0) {
      return result == 1 ? "A" : "B";
    } else {
      return moves.size() == 9 ? "Draw" : "Pending";
    }
  }
  
  int judge(vector<vector<int>> &mat) {
    if (mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0] && mat[0][0] != 0) {
      return mat[0][0];
    } else if (mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1] && mat[0][1] != 0) {
      return mat[0][1];
    } else if (mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2] && mat[0][2] != 0) {
      return mat[0][2];
    } else if (mat[0][0] == mat[0][1] && mat[0][1] == mat[0][2] && mat[0][0] != 0) {
      return mat[0][0];
    } else if (mat[1][0] == mat[1][1] && mat[1][1] == mat[1][2] && mat[1][0] != 0) {
      return mat[1][0];
    } else if (mat[2][0] == mat[2][1] && mat[2][1] == mat[2][2] && mat[2][0] != 0) {
      return mat[2][0];
    } else if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != 0) {
      return mat[0][0];
    } else if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != 0) {
      return mat[0][2];
    } else {
      return 0;
    }
  }
};
