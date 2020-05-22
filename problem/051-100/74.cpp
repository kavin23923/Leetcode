class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
    int l = 0, r = m * n - 1, mid;
    int x, y;
    while (l <= r) {
      mid = l + (r - l) / 2;
      x = mid / n;
      y = mid % n;
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};
