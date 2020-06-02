class Solution {
public:
  int minFlips(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();
    int res = INT_MAX;
    int zero = 0;
    unordered_set<int> visit;
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) zero++;
      }
    }
    
    if (zero == m * n) return 0;
    
    tryAll(mat, &res, visit, zero);
    
    return res == INT_MAX ? -1 : res;
  }
  
  void tryAll(vector<vector<int>>& mat, int* res, unordered_set<int> &visit, int zero) {
    if (visit.size() == m * n || visit.size() >= *res) {
      return;
    }
    for (int i = 0; i < m * n; i++) {
      if (visit.find(i) == visit.end()) {
        unordered_set<int> pos;
        int cur = zero;
        for (int j = 0; j < 5; j++) {
          int r = (i / n) + dir[j][0];
          int c = (i % n) + dir[j][1];
          if (r >= 0 && r < m && c >= 0 && c < n) {
            pos.insert(r * n + c);
            zero += mat[r][c] == 0 ? -1 : 1;
            mat[r][c] = mat[r][c] == 0 ? 1 : 0;
          }
        }
        if (zero == m * n) {
          *res = min(*res, (int)visit.size() + 1);
          for (int j : pos) {
            mat[j / n][j % n] = mat[j / n][j % n] == 0 ? 1 : 0;
          }
          return;
        }
        visit.insert(i);
        tryAll(mat, res, visit, zero);
        zero = cur;
        for (int j : pos) {
          mat[j / n][j % n] = mat[j / n][j % n] == 0 ? 1 : 0;
        }
        visit.erase(i);
      }
    }
  }
  
private:
  int m, n;
  vector<vector<int>> dir = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
