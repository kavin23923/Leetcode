class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
    int i = m - 1, j = 0;
    
    while (i >= 0 && j < n) {
      if (matrix[i][j] > target) {
        i--;
      } else if (matrix[i][j] < target) {
        j++;
      } else {
        return true;
      }
    } 
    return false;
  }
};
