class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int res = 0;
    vector<vector<int>> one(m, vector<int>(n + 1));
    
    for (int i = 0; i < m; i++) {
      for (int j = n - 1; j >= 0; j--) {
        one[i][j] = mat[i][j] == 0 ? 0 : one[i][j + 1] + 1;
      }
    }
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int now = INT_MAX;
        for (int k = i; k < m; k++) {
          now = min(now, one[k][j]);
          res += now;
        }
      }
    }
    
    return res;
  }
};
