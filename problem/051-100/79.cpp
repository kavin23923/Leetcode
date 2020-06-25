class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = m == 0 ? 0 : board[0].size();
    len = word.size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, word, 0, i, j)) return true;
      }
    }
    return false;
  }
  
  bool dfs(vector<vector<char>>& board, string &word, int now, int r, int c) {
    if (now == len) {
      return true;
    } else if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[now]) {
      return false;
    }
    board[r][c] = '.';
    if (dfs(board, word, now + 1, r - 1, c)) {
      return true;
    } else if (dfs(board, word, now + 1, r + 1, c)) {
      return true;
    } else if (dfs(board, word, now + 1, r, c - 1)) {
      return true;
    } else if (dfs(board, word, now + 1, r, c + 1)) {
      return true;
    }
    board[r][c] = word[now];
    return false;
  }

private:
  int m, n;
  int len;
};
