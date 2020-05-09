class Solution {
public:
  void solve(vector<vector<char>>& board) {
    m = board.size();
    n = m == 0 ? 0 : board[0].size();
    
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') {
        dfs(board, i, 0);
      }
      if (board[i][n - 1] == 'O') {
        dfs(board, i, n - 1);
      }
    }
    
    for (int i = 1; i < n - 1; i++) {
      if (board[0][i] == 'O') {
        dfs(board, 0, i);
      }
      if (board[m - 1][i] == 'O') {
        dfs(board, m - 1, i);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O'){
          board[i][j] = 'X';
        }
      }
    }
    
  }
  
  void dfs(vector<vector<char>>& board, int i, int j) {
    board[i][j] = '.';
    if (i - 1 >= 0 && board[i - 1][j] == 'O') {
      dfs(board, i - 1, j);
    }
    if (i + 1 < m && board[i + 1][j] == 'O') {
      dfs(board, i + 1, j);
    }
    if (j - 1 >= 0 && board[i][j - 1] == 'O') {
      dfs(board, i, j - 1);
    }
    if (j + 1 < n && board[i][j + 1] == 'O') {
      dfs(board, i, j + 1);
    }
  }
    
private:
  int m, n;
};
