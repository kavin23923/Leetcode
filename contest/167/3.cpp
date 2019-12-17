class Solution {
public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int i, j, k;
    int res = 0;
    int upperbound;
    vector<vector<int>> new_mat(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
    for (i = 0; i < mat.size(); i++) {
      for (j = 0; j < mat[0].size(); j++) {
        new_mat[i + 1][j + 1] = new_mat[i][j + 1] + new_mat[i + 1][j] - new_mat[i][j] + mat[i][j];
        upperbound = min(i + 1, j + 1);
        for (k = 1; k <= upperbound; k++) {
          if (new_mat[i + 1][j + 1] - new_mat[i + 1 - k][j + 1] - new_mat[i + 1][j + 1 - k] + new_mat[i + 1 - k][j + 1 - k] <= threshold) {
            res = max(k, res);
          }
        }
      }
    }
    return res;
  }
};