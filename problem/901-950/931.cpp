class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int res = INT_MAX;
    int m = A.size(), n = A[0].size(), tmp;
    
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        tmp = INT_MAX;
        if (j > 0) tmp = min(tmp, A[i - 1][j - 1]);
        if (j < n - 1) tmp = min(tmp, A[i - 1][j + 1]);
        tmp = min(tmp, A[i - 1][j]);
        A[i][j] += tmp;
      }
    }
    
    for (int i = 0; i < n; i++) {
      res = min(res, A[m - 1][i]);
    }
    return res;
  }
};
